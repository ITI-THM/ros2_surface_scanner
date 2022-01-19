from email.mime import image
import rclpy
from rclpy.node import Node

from cv_bridge import CvBridge

from std_srvs.srv import Trigger
from sensor_msgs.msg import Image
from interfaces.msg import ImagePair
from interfaces.msg import CameraCalibrationImgs

import cv2 as cv
import numpy as np

class Camera_Node(Node):

    def __init__(self):
        super().__init__('camera_node')

        self.bridge = CvBridge()

        # SERVICE: send images to calibrate laser
        self.send_laser_calibration_imgs_srv = self.create_service(
            Trigger, 
            'send_laser_calib_imgs',
            self.send_img_pair
        )

        #SERVICE: send images for intrinsic camera calibration
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

    def send_img_pair(self, request, response):
        origin_img = cv.imread('/home/tristan/Praktikum/scanner_ros_ws/src/surface_scanner/data/images/input/calibration_img_laser0.png')
        origin_img = self.bridge.cv2_to_imgmsg(origin_img)
        laser_img = cv.imread('/home/tristan/Praktikum/scanner_ros_ws/src/surface_scanner/data/images/input/calibration_img_laser1.png')
        laser_img = self.bridge.cv2_to_imgmsg(laser_img)

        image_pair_msg = ImagePair()
        image_pair_msg.origin_img = origin_img
        image_pair_msg.laser_img = laser_img
        self.get_logger().info("Publishing image pair!")
        self.img_pair_publisher.publish(image_pair_msg)

        response.success = True
        response.message = "Successfully send images!"
        return response

    def send_cam_calib_imgs(self, request, response):
        
        image_names = []

        for i in range(0, 12):
            image_names.append(f"calibration_img_{i}.png")

        print(image_names)

        images = []

        for name in image_names:
            img = cv.imread(f'/home/tristan/Praktikum/git/ros2_surface_scanner/scanner_ros_ws/src/surface_scanner/data/images/calibration/{name}')
            img = self.bridge.cv2_to_imgmsg(img)
            images.append(img)

        img_list_msg = CameraCalibrationImgs()

        for index in range(0, len(images) - 1):
            img_list_msg.imgs.append(images[index])

        self.get_logger().info("Publishing list of calibration images!")
        self.cam_calib_imgs_publisher.publish(img_list_msg)

        response.success = True
        response.message = "Successfully send images!"
        return response

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