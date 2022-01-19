from email.mime import image
import sys

import rclpy
from rclpy.node import Node
from interfaces.srv import ImagePairRequest

from cv_bridge import CvBridge

from std_srvs.srv import Trigger


class Start_Scan_Client(Node):

    def __init__(self):
        super().__init__('start_scan_client')

        self.client = self.create_client(Trigger, 'scan')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.request = Trigger.Request()

    def send_request(self):
        self.future = self.client.call_async(self.request)

class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(ImagePairRequest, 'send_calibration_images')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = ImagePairRequest.Request()

    def send_request(self):
        self.future = self.cli.call_async(self.req)

def test_image_cli():
    rclpy.init()

    minimal_client = MinimalClientAsync()
    minimal_client.send_request()

    tries = 1
    while rclpy.ok():
        rclpy.spin_once(minimal_client)
        minimal_client.get_logger().info(f'{tries}')
        tries+=1
        if minimal_client.future.done():
            try:
                response = minimal_client.future.result()
            except Exception as e:
                minimal_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                minimal_client.get_logger().info(
                    'Result of add_two_ints: for')
            break

    minimal_client.destroy_node()
    rclpy.shutdown()

def start_scan_function():
    rclpy.init()

    start_scan_client = Start_Scan_Client()
    start_scan_client.send_request()

    while rclpy.ok():
        rclpy.spin_once(start_scan_client)
        if start_scan_client.future.done():
            try:
                response = start_scan_client.future.result()
            except Exception as e:
                start_scan_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                start_scan_client.get_logger().info(
                    f'Calibrated laser status: \n "{response.success}"')
                start_scan_client.get_logger().info(
                    f'Received message: \n ||{response.message}||'
                )
            break

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    start_scan_client.destroy_node()
    rclpy.shutdown()
