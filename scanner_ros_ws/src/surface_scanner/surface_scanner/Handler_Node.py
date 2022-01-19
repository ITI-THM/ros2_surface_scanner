import sys

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from sensor_msgs.msg import Image
from example_interfaces.srv import AddTwoInts
from interfaces.msg import PlaneEquation
from interfaces.srv import CalibrateLaser

from cv_bridge import CvBridge

import cv2 as cv
import numpy as np


class Handler_Node(Node):

    def __init__(self):
        super().__init__('handler_node')

        self.bridge = CvBridge()

        self.subscription_plane_eq = self.create_subscription(
            PlaneEquation,
            'laser_plane',
            self.listener_callback,
            10)
        # self.subscription  # prevent unused variable warning

        self.test_sub = self.create_subscription(
            Image,
            'laser_img',
            self.test_sub_callback,
            10
        )

    def listener_callback(self, msg):
        self.get_logger().info(f'I saw: "{msg.plane_equation}"')

    def test_sub_callback(self, msg):
        img = self.bridge.imgmsg_to_cv2(msg)
        cv.imshow("test", img)
        cv.waitKey(0)

def main(args=None):
    rclpy.init(args=args)

    handler_node = Handler_Node()

    rclpy.spin(handler_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    handler_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
