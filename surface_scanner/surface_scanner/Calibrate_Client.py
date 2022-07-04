import sys

import rclpy
from rclpy.node import Node

from interfaces.msg import ScannerStatus
from interfaces.srv import CalibrateLaserImport

from std_srvs.srv import Trigger

import cv2 as cv
import numpy as np
import serial
import time


class Serial_Connection:
    
    def __init__(self):
        self.establish_serial_connection()
        self.set_home()

    # methods for serial connection to arduino
    def establish_serial_connection(self):
        self.SERIAL_CONNECTION = serial.Serial("/dev/ttyACM0", 115200)
        in_bytes = '\r\n\r\n'.encode('utf-8')
        self.SERIAL_CONNECTION.write(in_bytes)
        time.sleep(1)
        self.SERIAL_CONNECTION.flushInput()

    def mm_step(self, mm: int):
        self.SERIAL_CONNECTION.write(f'G1 Y{mm} F3000 \n'.encode('utf-8'))

    def set_home(self):
        self.SERIAL_CONNECTION.write('G91 \n'.encode('utf-8'))
        self.SERIAL_CONNECTION.write('G28 \n'.encode('utf-8'))

    def home(self):
        self.SERIAL_CONNECTION.write('G28 \n'.encode('utf-8'))
        

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


class Trigger_Take_Img_Pair_Surface(Node):

    def __init__(self):
        super().__init__('img_pair_stream_node')

        # PUBLISHER: point cloud of surface line
        self.status_pub = self.create_publisher(
            ScannerStatus, 
            'scanner_status', 
            10)

        # CLIENT
        self.client = self.create_client(
            Trigger, 
            'send_img_pair_surface'
        )

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('camera not available, waiting again...')
        self.request = Trigger.Request()

    def send_request(self):
        self.get_logger().info("Send request..")
        self.future = self.client.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future, timeout_sec=2)
        if self.future.result() is not None:
            self.get_logger().info("Future not None!")
        else:
            self.get_logger().warn("Future None!")


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

    # only usable with the original test set-up
    # SERIAL_CONNECTION = Serial_Connection()
    # trigger_client.get_logger().info("Established serial connection!")

    # SERIAL_CONNECTION.mm_step(mm=150)
    # time.sleep(20)

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
                # only usable with the original test set-up
                # SERIAL_CONNECTION.home()
                # time.sleep(20)
            break

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    trigger_client.destroy_node()
    rclpy.shutdown()


def trigger_surface_line_function(args=None):
    rclpy.init(args=args)

    trigger_client = Trigger_Take_Img_Pair_Surface()

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


def trigger_send_img_pair_stream_function(args=None):
    rclpy.init(args=args)

    trigger_client = Trigger_Take_Img_Pair_Surface()

    SERIAL_CONNECTION = Serial_Connection()
    trigger_client.get_logger().info("Established serial connection!")

    # set scanner active
    status_msg = ScannerStatus()
    status_msg.is_scanner_active = True
    trigger_client.status_pub.publish(status_msg)

    for mm_step in range(0, 290):
        if not rclpy.ok():
            trigger_client.get_logger().warn("rclpy ERROR!")
            break

        SERIAL_CONNECTION.mm_step(mm=1)
        time.sleep(0.5)
        
        trigger_client.get_logger().info(f"Sending request for image pair for mm_step: {mm_step}!")
        trigger_client.send_request()
        rclpy.spin_once(trigger_client)

    SERIAL_CONNECTION.home()
    time.sleep(36)

    trigger_client.get_logger().info("Finished surface scan!")

    # shut down scanner
    status_msg = ScannerStatus()
    status_msg.is_scanner_active = False
    trigger_client.status_pub.publish(status_msg)

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