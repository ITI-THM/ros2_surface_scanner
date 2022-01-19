import sys

import rclpy
from rclpy.node import Node

from interfaces.msg import PlaneEquation
from interfaces.srv import CalibrateLaser
from interfaces.srv import CalibrateLaserImport

from std_srvs.srv import Trigger

import cv2 as cv
import numpy as np


class Calibration_Client(Node):

    def __init__(self):
        super().__init__('calibration_node')
        self.client = self.create_client(Trigger, 'calibrate_scanner')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.request = Trigger.Request()

    def send_request(self):
        self.future = self.client.call_async(self.request)


class Calibration_Client_Import(Node):

    def __init__(self):
        super().__init__('calibration_import_node')
        self.client = self.create_client(CalibrateLaserImport, 'calibrate_with_import')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.request = CalibrateLaserImport.Request()

    def send_request(self):
        self.request.file = sys.argv[1]
        self.future = self.client.call_async(self.request)


class Trigger_Take_Img_Pair(Node):

    def __init__(self):
        super().__init__('trigger_img_pair_node')
        self.client = self.create_client(Trigger, 'send_laser_calib_imgs')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('camera not available, waiting again...')
        self.request = Trigger.Request()

    def send_request(self):
        self.future = self.client.call_async(self.request)


class Trigger_Take_Cam_Calib_Imgs(Node):

    def __init__(self):
        super().__init__('trigger_cam_calib_img_node')
        self.client = self.create_client(Trigger, 'send_cam_calib_imgs')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('camera not available, waiting again...')
        self.request = Trigger.Request()

    def send_request(self):
        self.future = self.client.call_async(self.request)


def calibrate_client_function(args=None):
    rclpy.init(args=args)

    calibrate_client = Calibration_Client()
    calibrate_client.send_request()

    while rclpy.ok():
        rclpy.spin_once(calibrate_client)
        if calibrate_client.future.done():
            try:
                response = calibrate_client.future.result()
            except Exception as e:
                calibrate_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                calibrate_client.get_logger().info(
                    f'Calibrated laser status: "{response.success}"'
                )
                calibrate_client.get_logger().info(
                    f'Recieved message: \n ||{response.message}||'
                )
            break

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    calibrate_client.destroy_node()
    rclpy.shutdown()


def calibrate_client_import_function(args=None):
    rclpy.init(args=args)

    calibrate_client = Calibration_Client_Import()
    calibrate_client.send_request()

    while rclpy.ok():
        rclpy.spin_once(calibrate_client)
        if calibrate_client.future.done():
            try:
                response = calibrate_client.future.result()
            except Exception as e:
                calibrate_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                calibrate_client.get_logger().info(
                    f'Calibrated laser status: "{response.success}"'
                )
                calibrate_client.get_logger().info(
                    f'Recieved message: \n ||{response.message}||'
                )
            break

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    calibrate_client.destroy_node()
    rclpy.shutdown()


def trigger_take_img_pair_function(args=None):
    rclpy.init(args=args)

    trigger_client = Trigger_Take_Img_Pair()
    trigger_client.send_request()

    while rclpy.ok():
        rclpy.spin_once(trigger_client)
        if trigger_client.future.done():
            try:
                response = trigger_client.future.result()
            except Exception as e:
                trigger_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                trigger_client.get_logger().info(
                    f'Status: "{response.success}"'
                )
                trigger_client.get_logger().info(
                    f'Recieved message: \n ||{response.message}||'
                )
            break

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    trigger_client.destroy_node()
    rclpy.shutdown()


def trigger_take_cam_calib_imgs_function(args=None):
    rclpy.init(args=args)

    trigger_client = Trigger_Take_Cam_Calib_Imgs()
    trigger_client.send_request()

    while rclpy.ok():
        rclpy.spin_once(trigger_client)
        if trigger_client.future.done():
            try:
                response = trigger_client.future.result()
            except Exception as e:
                trigger_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                trigger_client.get_logger().info(
                    f'Status: "{response.success}"'
                )
                trigger_client.get_logger().info(
                    f'Recieved message: \n ||{response.message}||'
                )
            break

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    trigger_client.destroy_node()
    rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)

    handler_node = Calibration_Client()

    rclpy.spin(handler_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    handler_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()