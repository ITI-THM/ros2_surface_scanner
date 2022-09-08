import rclpy
from rclpy.node import Node

from cv_bridge import CvBridge

from std_srvs.srv import Trigger
from interfaces.msg import ImagePair
from interfaces.msg import CameraCalibrationImgs
import cv2 as cv
import time
import numpy as np
import RPi.GPIO as GPIO
import os

class Camera_Node_Rasp(Node):

    def __init__(self):
        super().__init__('camera_node_rasp')

        self.bridge = CvBridge()

        # SERVICE: send image pair to calibrate laser
        self.send_img_pair_calib_srv = self.create_service(
            Trigger, 
            'send_img_pair_calib',
            self.send_img_pair_calib
        )

        # SERVICE: sending image pair for surface reconstruction
        self.send_img_pair_surface_srv = self.create_service(
            Trigger,
            'send_img_pair_surface',
            self.send_img_pair_surface
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

    def send_img_pair_calib(self, request, response):

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

        return response

    def send_cam_calib_imgs(self, request, response):
        
        # Functionality for manually capturing 10 different images is not yet implemented!
        # Therefor the images will be send to te scanner_node out of a special directory.

        image_names = []

        for i in range(0, 10):
            image_names.append(f"calibration_img_{i}.png")

        images = []

        for name in image_names:
            img = cv.imread(f'./src/ros2_surface_scanner/surface_scanner/input/{name}')
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

    def send_img_pair_surface(self, request, response):
        images = self.__getLaserImages()

        origin_img = self.bridge.cv2_to_imgmsg(images[0])
        laser_img = self.bridge.cv2_to_imgmsg(images[1])

        image_pair_msg = ImagePair()
        image_pair_msg.is_for_laser_calib = False
        image_pair_msg.origin_img = origin_img
        image_pair_msg.laser_img = laser_img

        self.get_logger().info(f"Publishing image pair for x-length!")

        self.img_pair_publisher.publish(image_pair_msg)

        response.success = True
        response.message = "Successfully sending images!"
        return response

    def __getLaserImages(self):

        pin = 13
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(pin, GPIO.OUT)

        origin_img = self.__capture_image()

        GPIO.output(pin, True)
        time.sleep(0.05)
        
        laser_img = self.__capture_image()

        GPIO.output(pin, False)
        GPIO.cleanup()
        return np.array([origin_img, laser_img])

    def __capture_image(self):
        cam = cv.VideoCapture(0)

        ret, frame = cam.read()
        if ret:
                img = frame
                
        cam.release()

        return img

def main(args=None):
    rclpy.init(args=args)

    camera_node = Camera_Node_Rasp()

    rclpy.spin(camera_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    camera_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()