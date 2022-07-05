from operator import le
import re
import sys
import os

import rclpy
from rclpy.node import Node

import sensor_msgs.msg as sensor_msgs
import std_msgs.msg as std_msgs
from std_srvs.srv import Trigger

from std_msgs.msg import String
from interfaces.msg import ImagePair
from interfaces.msg import CameraCalibrationImgs
from interfaces.srv import CalibrateLaserImport

from cv_bridge import CvBridge

import numpy as np
import open3d as o3d
import cv2 as cv


from .src_scanner.Scanner import Scanner

"""
References:
https://github.com/SebastianGrans/ROS2-Point-Cloud-Demo
"""


class Surface_Scanner_Node(Node):

    def __init__(self):
        super().__init__('surface_scanner_node')

        self.cv_bridge = CvBridge()

        # SERVICE: calibrate scanner
        self.calibrate_scanner_srv = self.create_service(
            Trigger,
            'calibrate_scanner',
            self.calibrate_scanner_srv_callback
        )

        # SERVICE: calibrate laser with import of camera params
        self.calibrate_laser_with_import_srv = self.create_service(
            CalibrateLaserImport, 
            'calibrate_with_import', 
            self.calibrate_with_import_srv_callback
        )

        # PUBLISHER: point cloud of surface line
        self.pcd_publisher = self.create_publisher(
            sensor_msgs.PointCloud2, 
            'surface_line', 
            10)

        # PUBLISHER: generated laser plane
        # ---> Debug-Information
        self.laser_plane_publisher = self.create_publisher(
            sensor_msgs.PointCloud2,
            'laser_plane',
            10
        )

        # SUBSCRIBER: image pair, one origin and one with laser
        self.img_pair_sub = self.create_subscription(
            ImagePair,
            'img_pair',
            self.image_pair_callback,
            10
        )

        # SUBSCRIBER: images for intrinsic calibration of the camera
        self.cam_calibrate_imgs_sub = self.create_subscription(
            CameraCalibrationImgs,
            'cam_calib_imgs',
            self.cam_calib_imgs_callback,
            10
        )

        # Make scanner object
        self.scanner = Scanner()

        # other fields
        self.__origin_img = None
        self.__laser_img = None
        self.__calib_imgs = None

        # self.__scanner_status: bool = False

        # self.scanner.display_pcd(with_laser=True)

        self.get_logger().info('Surface-Scanner-Node ready!')

    def calibrate_scanner_srv_callback(self, request, response):

        if self.__calib_imgs is None:
            response.success = False
            response.message = "Scanner calibration cancelled! Missing images for intrinsic camera calibration."

            return response    

        if self.__origin_img is None or self.__laser_img is None:
            response.success = False
            response.message = "Scanner calibration cancelled! Missing images for laser calibration."

            return response

        self.get_logger().info('Incoming request for scanner calibration!')
        self.get_logger().info(f'Holding list of {len(self.__calib_imgs)} images for intrinsic calibration.')
        self.get_logger().info(f'Holding two images to calibrate laser with shape [{self.__origin_img.shape}, {self.__laser_img.shape}]')

        # scanner object calibrates laser
        self.scanner.calibrate_scanner(
            pictures=self.__calib_imgs,
            safe_data_in_npz=True,
            calibration_img=self.__origin_img,
            calibration_img_laser=self.__laser_img
        )

        if self.scanner.is_scanner_calibrated() is not True:
            # fill response
            response.success = False
            response.message = "Scanner calibration unsuccessful!"
            return response

        # Publish laser lines of laser calibration
        pcd_laser = self.scanner.make_laser_lines_pcd()
        points = np.asarray(pcd_laser.points)
        colors = np.asarray(pcd_laser.colors)
        pcd_laser = point_cloud(points, colors, 'map')
        self.laser_plane_publisher.publish(pcd_laser)
        self.get_logger().info("Publishing point cloud to display the laser plane! -> Topic: laser_plane")

        response.success = True
        response.message = "Scanner calibration successful! Ready to scan."

        self.refresh_calib_imgs_field()
        self.refresh_img_pair_fields()

        return response

    def calibrate_with_import_srv_callback(self, request, response):
        path = request.file

        if self.__origin_img is None or self.__laser_img is None:
            response.success = False
            response.message = "Scanner calibration cancelled! Missing images for laser calibration."

            return response

        self.get_logger().info('Incoming request for scanner calibration with import of camera parameters!')
        self.get_logger().info(f'Holding two images to calibrate laser with shape [{self.__origin_img.shape}, {self.__laser_img.shape}]')

        # scanner object calibrates laser
        self.scanner.calibrate_scanner_with_import(
            src=path,
            calibration_img=self.__origin_img,
            calibration_img_laser=self.__laser_img
        )

        if self.scanner.is_scanner_calibrated() is not True:
            # fill response
            response.success = False
            response.message = "Scanner calibration unsuccessful!"
            return response

        # Publish laser lines of laser calibration
        pcd_laser = self.scanner.make_laser_lines_pcd()
        points = np.asarray(pcd_laser.points)
        colors = np.asarray(pcd_laser.colors)
        pcd_laser = point_cloud(points, colors, 'map')
        self.laser_plane_publisher.publish(pcd_laser)
        self.get_logger().info("Publishing point cloud to display the laser plane! -> Topic: laser_plane")


        # fill response
        response.success = True
        response.message = "Scanner calibration successful! Ready to scan."

        self.refresh_calib_imgs_field()
        self.refresh_img_pair_fields()

        return response

    def image_pair_callback(self, img_pair):

        if img_pair.is_for_laser_calib:
            origin_img = self.cv_bridge.imgmsg_to_cv2(img_pair.origin_img)
            laser_img = self.cv_bridge.imgmsg_to_cv2(img_pair.laser_img)
            
            self.__origin_img = origin_img
            self.__laser_img = laser_img
            self.get_logger().info(f'Recieved image pair to calibrate laser! \n Shape: \n origin_img: {origin_img.shape} \n laser_img: {laser_img.shape}')
        else:
            origin_img = self.cv_bridge.imgmsg_to_cv2(img_pair.origin_img)
            laser_img = self.cv_bridge.imgmsg_to_cv2(img_pair.laser_img)

            if self.scanner.is_scanner_calibrated():
                self.get_logger().info(f'Recieved image pair to generate surface point cloud! \n Shape: \n origin_img: {origin_img.shape} \n laser_img: {laser_img.shape}')
                
                self.scanner.generate_pcd(
                    surface_img=origin_img,
                    surface_img_laser=laser_img,
                )

                points = np.asarray(self.scanner.get_point_cloud().points)
                colors = np.asarray(self.scanner.get_point_cloud().colors)

                pcd = point_cloud(points, colors, 'map')
                self.pcd_publisher.publish(pcd)

                self.get_logger().info(
                    f"Publish generated point cloud: ' {self.scanner.get_point_cloud()}'")
            else:
                self.get_logger().warning("Scanner is not calibrated!")

    def cam_calib_imgs_callback(self, imgs):
        self.__calib_imgs = []
        for index in range(0, len(imgs.imgs)):
            self.__calib_imgs.append(self.cv_bridge.imgmsg_to_cv2(imgs.imgs[index]))
        print(self.__calib_imgs[0].shape)
        self.get_logger().info(f"Recieved list with {len(self.__calib_imgs)} images for intrinsic camera calibration!")

    def refresh_img_pair_fields(self):
        self.__origin_img = None
        self.__laser_img = None

    def refresh_calib_imgs_field(self):
        self.__calib_imgs = None

def point_cloud(points, colors, parent_frame):
    """ Creates a point cloud message.
    Args:
        points: Nx3 array of xyz positions.
        parent_frame: frame in which the point cloud is defined
    Returns:
        sensor_msgs/PointCloud2 message

    Code source:
        https://gist.github.com/pgorczak/5c717baa44479fa064eb8d33ea4587e0

    References:
        https://docs.ros.org/melodic/api/sensor_msgs/html/msg/PointCloud2.html
        https://docs.ros.org/melodic/api/sensor_msgs/html/msg/PointField.html
        https://docs.ros.org/melodic/api/std_msgs/html/msg/Header.html
        :param parent_frame:
        :param points:
        :param colors:

    """
    # In a PointCloud2 message, the point cloud is stored as an byte
    # array. In order to unpack it, we also include some parameters
    # which desribes the size of each individual point.
    ros_dtype = sensor_msgs.PointField.FLOAT32
    dtype = np.float32
    itemsize = np.dtype(dtype).itemsize  # A 32-bit float takes 4 bytes.

    data = np.array(np.hstack([points, colors]), dtype=np.float32)
    # data = points.astype(dtype).tobytes()

    # The fields specify what the bytes represents. The first 4 bytes
    # represents the x-coordinate, the next 4 the y-coordinate, etc.
    fields = [
        sensor_msgs.PointField(name='x', offset=0, datatype=7, count=1),
        sensor_msgs.PointField(name='y', offset=4, datatype=7, count=1),
        sensor_msgs.PointField(name='z', offset=8, datatype=7, count=1),
        sensor_msgs.PointField(name='r', offset=12, datatype=7, count=1),
        sensor_msgs.PointField(name='g', offset=16, datatype=7, count=1),
        sensor_msgs.PointField(name='b', offset=20, datatype=7, count=1)
    ]

    # The PointCloud2 message also has a header which specifies which
    # coordinate frame it is represented in.
    header = std_msgs.Header(frame_id=parent_frame)

    return sensor_msgs.PointCloud2(
        header=header,
        height=1,
        width=points.shape[0],
        is_dense=False,
        is_bigendian=False,
        fields=fields,
        point_step=(itemsize * 6),  # Every point consists of three float32s.
        row_step=(itemsize * 6 * points.shape[0]),
        data=data.tobytes()
    )


def main(args=None):
    rclpy.init(args=args)

    surface_scanner_node = Surface_Scanner_Node()

    rclpy.spin(surface_scanner_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    surface_scanner_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
