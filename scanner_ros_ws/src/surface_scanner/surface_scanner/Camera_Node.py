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
        self.send_calibration_images_srv = self.create_service(
            Trigger, 
            'send_calibration_images',
            self.send_img_pair
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
        response.message = "Successfuly send images!"
        return response

    def send_calib_imgs(self):
        return

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