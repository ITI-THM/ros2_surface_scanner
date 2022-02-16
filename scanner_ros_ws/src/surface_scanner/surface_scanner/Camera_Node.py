import rclpy
from rclpy.node import Node

from cv_bridge import CvBridge

from std_srvs.srv import Trigger
from sensor_msgs.msg import Image
from interfaces.msg import ImagePair
from interfaces.msg import CameraCalibrationImgs

import cv2 as cv
import numpy as np
from pypylon import pylon
import serial
import time

class Camera_Node(Node):

    def __init__(self):
        super().__init__('camera_node')

        self.bridge = CvBridge()

        self.SERIAL_CONNECTION = serial.Serial("/dev/ttyACM0", 115200)
        self.get_logger().info("Established serial connection!")
        in_bytes = '\r\n\r\n'.encode('utf-8')
        self.SERIAL_CONNECTION.write(in_bytes)
        time.sleep(1)
        self.SERIAL_CONNECTION.flushInput()

        self.SERIAL_CONNECTION.write('G91 \n'.encode('utf-8'))
        self.SERIAL_CONNECTION.write('G28 \n'.encode('utf-8'))

        # CAMERA: setup camera settings!
        self.__camera = pylon.InstantCamera(
            pylon.TlFactory.GetInstance().CreateFirstDevice())

        self.__camera.RegisterConfiguration(
            pylon.SoftwareTriggerConfiguration(), 
            pylon.RegistrationMode_ReplaceAll,
            pylon.Cleanup_Delete
        )
        self.get_logger().info(f"Using camera device {self.__camera.GetDeviceInfo().GetModelName()}")

        self.__camera.MaxNumBuffer = 5
        self.__camera.Open()
        self.__camera.StartGrabbing(pylon.GrabStrategy_OneByOne)

        # Activate GPIO of Line 2
        self.__camera.LineSelector.SetValue("Line2")
        self.__camera.LineMode.SetValue("Output")
        self.__camera.LineSource.SetValue("UserOutput1")
        self.__camera.LineInverter.SetValue(False)
        self.__camera.UserOutputSelector.SetValue('UserOutput1')
        self.__camera.UserOutputValue.SetValue(False)

        # Setup Image Converter
        self.__converter = pylon.ImageFormatConverter()
        self.__converter.OutputPixelFormat = pylon.PixelType_BGR8packed
        self.__converter.OutputBitAlignment = pylon.OutputBitAlignment_MsbAligned

        # SERVICE: send images to calibrate laser
        self.send_laser_calibration_imgs_srv = self.create_service(
            Trigger, 
            'send_laser_calib_imgs',
            self.send_img_pair
        )

        # SERVICE: send stream of image pairs
        self.send_img_pair_stream_srv = self.create_service(
            Trigger,
            'send_img_pair_stream',
            self.img_pair_stream
        )

        # SERVICE: send images for intrinsic camera calibration
        self.send_cam_calibration_imgs_srv = self.create_service(
            Trigger,
            'send_cam_calib_imgs',
            self.send_cam_calib_imgs
        )
        
        # PUBLISHER: image pair
        self.img_pair_publisher = self.create_publisher(
            ImagePair,
            'img_pair', 
            10
        )

        # PUBLISHER: for intrinsic camera calibration images
        self.cam_calib_imgs_publisher = self.create_publisher(
            CameraCalibrationImgs,
            'cam_calib_imgs',
            10
        )

        self.get_logger().info('Camera-Node ready!')

    # Callback functions:

    def send_img_pair(self, request, response):

        self.SERIAL_CONNECTION.write('G1 Y150 F1000 \n'.encode('utf-8'))

        time.sleep(20)

        images = self.__getLaserImages()

        time.sleep(0.5)

        # origin_img = cv.imread('/home/tristan/Praktikum/scanner_ros_ws/src/surface_scanner/data/images/input/calibration_img_laser0.png')
        origin_img = self.bridge.cv2_to_imgmsg(images[0])
        # laser_img = cv.imread('/home/tristan/Praktikum/scanner_ros_ws/src/surface_scanner/data/images/input/calibration_img_laser1.png')
        laser_img = self.bridge.cv2_to_imgmsg(images[1])

        image_pair_msg = ImagePair()
        image_pair_msg.is_for_laser_calib = True
        image_pair_msg.origin_img = origin_img
        image_pair_msg.laser_img = laser_img
        self.get_logger().info("Publishing image pair!")
        self.img_pair_publisher.publish(image_pair_msg)

        response.success = True
        response.message = "Successfully send images!"

        self.SERIAL_CONNECTION.write('G91 \n'.encode('utf-8'))
        self.SERIAL_CONNECTION.write('G28 \n'.encode('utf-8'))

        return response

    def send_cam_calib_imgs(self, request, response):
        
        image_names = []

        for i in range(0, 10):
            image_names.append(f"calibration_img_{i}.png")

        images = []

        for name in image_names:
            img = cv.imread(f'/home/tristan/Praktikum/calib_imgs/{name}')
            img = self.bridge.cv2_to_imgmsg(img)
            images.append(img)

        img_list_msg = CameraCalibrationImgs()

        for index in range(0, len(images)):
            img_list_msg.imgs.append(images[index])

        self.get_logger().info(f"Publishing list with {len(img_list_msg.imgs)} calibration images!")
        self.cam_calib_imgs_publisher.publish(img_list_msg)

        response.success = True
        response.message = "Successfully send images!"
        return response

    def img_pair_stream(self, request, response):

        for mm_step in range(0, 290):

            self.SERIAL_CONNECTION.write('G1 Y1 F3000 \n'.encode('utf-8'))

            time.sleep(0.5)

            images = self.__getLaserImages()

            origin_img = self.bridge.cv2_to_imgmsg(images[0])
            laser_img = self.bridge.cv2_to_imgmsg(images[1])

            cv.imshow('title', images[1])
            exit_key = cv.waitKey(1)

            image_pair_msg = ImagePair()
            image_pair_msg.is_for_laser_calib = False
            image_pair_msg.origin_img = origin_img
            image_pair_msg.laser_img = laser_img

            self.get_logger().info(f"Publishing image pair for x-length: {mm_step + 1}!")

            self.img_pair_publisher.publish(image_pair_msg)

        self.SERIAL_CONNECTION.write('G28 \n'.encode('utf-8'))
        time.sleep(36)

        response.success = True
        response.message = "Successfully sending images!"
        return response

    # Camera functions:

    def __del__(self):
        self.__camera.StopGrabbing()
        self.__camera.Close()
        cv.destroyAllWindows()

    def __getLaserImages(self):
        self.__camera.UserOutputValue.SetValue(False)
        # time.sleep(0.01)
        for i in range(2):
            if self.__camera.WaitForFrameTriggerReady(200, pylon.TimeoutHandling_ThrowException):
                if i > 0:
                    self.__camera.UserOutputValue.SetValue(True)
                self.__camera.ExecuteSoftwareTrigger()
                time.sleep(0.01)
                self.get_logger().info(f"Line Value: {self.__camera.LineStatus.GetValue()}")

        self.__camera.UserOutputValue.SetValue(False)

        # stime.sleep(0.2)

        if self.__camera.GetGrabResultWaitObject().Wait(0):
            self.get_logger().info("Grab results wait in the output queue.")

        images = []
        for i in range(2):
            result = self.__camera.RetrieveResult(
                200 , pylon.TimeoutHandling_ThrowException)
            image = self.__converter.Convert(result)
            images.append(image.GetArray())

        return images

def main(args=None):
    rclpy.init(args=args)

    camera_node = Camera_Node()

    rclpy.spin(camera_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    camera_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()