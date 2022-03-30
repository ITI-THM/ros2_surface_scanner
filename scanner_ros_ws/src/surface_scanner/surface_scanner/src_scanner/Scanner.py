import os
import numpy as np
import cv2 as cv
import open3d as o3d
from cv2 import aruco
from cv_bridge import CvBridge  # Package to convert between ROS and OpenCV Images
from .Camera import Camera
from .Laser import Laser, bild2world, cam2world, world2cam, plane_fit_with_svd
from .Laser_Line import LaserLine

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


class Scanner:

    def __init__(self):

        self.__camera: Camera = Camera()
        self.__laser: Laser = Laser()
        self.__surface: o3d.geometry.PointCloud = o3d.geometry.PointCloud()
        self.__surface_points = np.empty((3, 0))
        self.__surface_colors = np.empty((0, 3))
        self.__calibrated: bool = False
        self.__x_step: int = 0

    def calibrate_scanner(self,
                          pictures,
                          safe_data_in_npz: bool,
                          calibration_img,
                          calibration_img_laser):

        self.__camera.calibrate_camera(pictures=pictures, save_data_in_npz=safe_data_in_npz)
        control_flag = self.__calibrate_laser(calibration_img=calibration_img,
                               calibration_img_with_laser=calibration_img_laser)
        
        self.__calibrated = control_flag
        self.__x_step = 0

    def calibrate_scanner_with_import(self,
                                      src: str,
                                      calibration_img,
                                      calibration_img_laser):
        self.__camera.import_camera_params(src=src)
        control_flag = self.__calibrate_laser(calibration_img=calibration_img,
                               calibration_img_with_laser=calibration_img_laser)

        self.__calibrated = control_flag
        self.__x_step = 0

    def generate_pcd(self, surface_img, surface_img_laser, threshold=50, print_in_plot=False):
        assert surface_img is not None, "WARNING: Image at 'surface_img' could not be loaded!"
        assert surface_img_laser is not None, "WARNING: Image at 'surface_img_laser' could not be loaded!"

        # undistort surface images
        surface_img = cv.undistort(surface_img, self.__camera.get_mtx(), self.__camera.get_dist(), None)
        surface_img_laser = cv.undistort(surface_img_laser, self.__camera.get_mtx(), self.__camera.get_dist(), None)

        surface_line = LaserLine(
            original_img=surface_img,
            img_with_laser=surface_img_laser,
            rvec=self.__laser.get_up().get_rvec(),
            tvec=self.__laser.get_up().get_tvec(),
            threshold=threshold
        )

        points_surface = bild2world(
            pts=surface_line.get_laser_points(),
            rot_matrix=surface_line.get_rvec(),
            trans=surface_line.get_tvec(),
            cam_matrix=self.__camera.get_mtx(),
            plane=self.__laser.get_plane_eq()
        )

        # Include the x-displacement
        points_surface[0] = points_surface[0] - (self.__x_step * 0.001)

        points_surface_cam = world2cam(
            pts=points_surface,
            rot_matrix=surface_line.get_rvec(),
            trans=surface_line.get_tvec()
        )

        self.__surface_points = np.append(self.__surface_points, points_surface_cam, axis=1)
        self.__surface_colors = np.append(self.__surface_colors, self.__get_pixel_colors(
            pts_laser=surface_line.get_laser_points().T, 
            img_original=surface_img), axis=0
        )

        if print_in_plot:
            self.__generate_plot(surface_points=points_surface_cam)

        self.refresh_pcd(points=self.__surface_points.T, colors=self.__surface_colors)

        # self.__surface.points = o3d.utility.Vector3dVector(points_surface_cam.T)

        # self.__get_pixel_colors(pts_laser=surface_line.get_laser_points().T, img_original=surface_img)

        self.__x_step += 1
        print("INFO: Finished point cloud generation!")

    def display_pcd(self, with_laser: bool = False):
        if len(self.__surface.points) != 0:
            coordinate_axis = o3d.geometry.TriangleMesh.create_coordinate_frame(
                size=30,
                origin=[0, 0, 0]
            )
            if with_laser:
                pcd_laser = self.make_laser_lines_pcd()
                o3d.visualization.draw_geometries([self.__surface, pcd_laser, coordinate_axis])
            else:
                o3d.visualization.draw_geometries([self.__surface, coordinate_axis])
        else:
            print("WARNING: Point cloud is empty!")

    def __generate_plot(self, surface_points):
        # 3D Bild ausgeben
        plt.figure(figsize=(10, 10))
        plt.subplot(111, projection='3d')
        ax = plt.gca()
        ax.set_xlabel('X-Achse', fontsize='large', fontweight='bold')
        ax.set_ylabel('Y-Achse', fontsize='large', fontweight='bold')
        ax.set_zlabel('Z-Achse', fontsize='large', fontweight='bold')
        plt.title('Laserlinien', fontsize='xx-large', fontweight='bold')

        points = self.__laser.get_plane_points()
        plt.plot(points[0, :], points[1, :], points[2, :],
                 '.', label='Laser')

        plt.plot(surface_points[0, :], surface_points[1, :], surface_points[2, :],
                 '.', label='Surface')

        plane = self.__laser.get_plane_eq()
        x, y = np.meshgrid(range(-100, 101), range(-100, 101))
        z = ((-1 * plane[3]) - (plane[0] * x) - (plane[1] * y)) / plane[2]

        # plot the plane
        ax.plot_surface(x, y, z, alpha=0.5)

        # rotate the axes and update.
        ax.view_init(20, 70)

        plt.legend()
        plt.show()

    def __calibrate_laser(self,
                          calibration_img,
                          calibration_img_with_laser):

        # Read in the pictures of ChArUco_Board with and without laser
        charuco_board = calibration_img
        assert charuco_board is not None, "Image at 'charuco_board' could not be loaded!"

        charuco_board_laser = calibration_img_with_laser
        assert charuco_board_laser is not None, "Image at 'charuco_board_laser' could not ne loaded!"

        # undistort calibration images
        charuco_board = cv.undistort(charuco_board, self.__camera.get_mtx(), self.__camera.get_dist(), None)
        charuco_board_laser = cv.undistort(charuco_board_laser, self.__camera.get_mtx(), self.__camera.get_dist(), None)

        # generate output images
        #--------------------------------------------------------------------------------------        
        cv.imwrite('./out/extrinsic_calibration/charuco_board.png', charuco_board)
        cv.imwrite('./out/extrinsic_calibration/charuco_board_laser.png', charuco_board_laser)
        #--------------------------------------------------------------------------------------  

        # Create parameter for detecting the boards
        aruco_dict_primary = aruco.Dictionary_get(aruco.DICT_4X4_50)
        aruco_dict_secondary = aruco.Dictionary_get(aruco.DICT_5X5_50)
        aruco_params = aruco.DetectorParameters_create()
        board_primary = aruco.CharucoBoard_create(squaresX=7, squaresY=5, squareLength=0.025, markerLength=0.019,
                                                  dictionary=aruco_dict_primary)
        board_secondary = aruco.CharucoBoard_create(squaresX=7, squaresY=5, squareLength=0.025, markerLength=0.019,
                                                    dictionary=aruco_dict_secondary)

        # Get pose of the first board
        control, rvec_primary, tvec_primary, charuco_mask_primary = self.__get_pose_in_charuco_board(
            aruco_params=aruco_params,
            board=board_primary,
            dictionary=aruco_dict_primary,
            img=charuco_board,
            primary=True
        )

        if control is False:
            print("WARNING: Something went wrong with detecting the ChArUco-Board!")
            return False

        # Get pose of the second board
        control, rvec_secondary, tvec_secondary, charuco_mask_secondary = self.__get_pose_in_charuco_board(
            aruco_params=aruco_params,
            board=board_secondary,
            dictionary=aruco_dict_secondary,
            img=charuco_board,
            primary=False
        )

        if control is False:
            print("WARNING: Something went wrong with detecting the ChArUco-Board!")
            return False

        # generade output images
        #--------------------------------------------------------------------------------------------------------------------------------------------
        charuco_drawn_primary = charuco_board.copy()
        aruco.drawAxis(charuco_drawn_primary, self.__camera.get_mtx(), self.__camera.get_dist(), rvec_primary, tvec_primary, 0.1)
        charuco_drawn_secondary = charuco_board.copy()
        aruco.drawAxis(charuco_drawn_secondary, self.__camera.get_mtx(), self.__camera.get_dist(), rvec_secondary, tvec_secondary, 0.1)
        cv.imwrite('./out/extrinsic_calibration/charuco_primary.png', charuco_drawn_primary)
        cv.imwrite('./out/extrinsic_calibration/charuco_secondary.png', charuco_drawn_secondary)

        charuco_cut_primary = cv.bitwise_and(charuco_board_laser, charuco_board_laser, mask=charuco_mask_primary)
        copy = aruco.drawAxis(charuco_cut_primary.copy(), self.__camera.get_mtx(), self.__camera.get_dist(), rvec_primary, tvec_primary, 0.1)
        cv.imwrite('./out/extrinsic_calibration/charuco_cut_primary.png', copy)
        laserline_primary = cv.subtract(charuco_cut_primary, cv.bitwise_and(charuco_board, charuco_board, mask=charuco_mask_primary))
        aruco.drawAxis(laserline_primary, self.__camera.get_mtx(), self.__camera.get_dist(), rvec_primary, tvec_primary, 0.1)
        cv.imwrite('./out/extrinsic_calibration/laserline_primary.png', laserline_primary)

        charuco_cut_secondary = cv.bitwise_and(charuco_board_laser, charuco_board_laser, mask=charuco_mask_secondary)
        copy = aruco.drawAxis(charuco_cut_secondary.copy(), self.__camera.get_mtx(), self.__camera.get_dist(), rvec_secondary, tvec_secondary, 0.1)
        cv.imwrite('./out/extrinsic_calibration/charuco_cut_secondary.png', copy)
        laserline_secondary = cv.subtract(charuco_cut_secondary, cv.bitwise_and(charuco_board, charuco_board, mask=charuco_mask_secondary))
        aruco.drawAxis(laserline_secondary, self.__camera.get_mtx(), self.__camera.get_dist(), rvec_secondary, tvec_secondary, 0.1)
        cv.imwrite('./out/extrinsic_calibration/laserline_secondary.png', laserline_secondary)
        #--------------------------------------------------------------------------------------------------------------------------------------------

        # fill in laser-line parameter in laser
        self.__laser.set_up(
            LaserLine(
                rvec=rvec_primary,
                tvec=tvec_primary,
                original_img=charuco_board,
                img_with_laser=charuco_board_laser,
                mask=charuco_mask_primary
            )
        )
        # print("INFO: 'up' ready!")

        self.__laser.set_down(
            LaserLine(
                rvec=rvec_secondary,
                tvec=tvec_secondary,
                original_img=charuco_board,
                img_with_laser=charuco_board_laser,
                mask=charuco_mask_secondary
            )
        )
        # print("INFO: 'down' ready!")

        self.__laser.make_plane_eq(camera_matrix=self.__camera.get_mtx())
        plane_eq = self.__laser.get_plane_eq()
        print(f"INFO: Laser-plane calibrated with equation: \n '{plane_eq[0]} * X  +  {plane_eq[1]} * Y  + { plane_eq[2]} * Z  =  {plane_eq[3]}'!")
        return True

    def __get_pose_in_charuco_board(self, aruco_params, board, dictionary, img, primary: bool):
        # Control-Flag to ensure everything went right
        control_flag: bool = False

        # Create black img to set up mask
        charuco_mask = np.zeros((img.shape[0], img.shape[1], 1), np.uint8)
        # Find ChArUco-Markers in img
        corners, ids, rejected_img_points = aruco.detectMarkers(image=img,
                                                                dictionary=dictionary,
                                                                parameters=aruco_params)
        if ids is not None:
            # Find the chessboard-corners
            charuco_retval, charuco_corners, charuco_ids = aruco.interpolateCornersCharuco(markerCorners=corners,
                                                                                           markerIds=ids,
                                                                                           image=img,
                                                                                           board=board)
            if charuco_ids is not None:
                # Create as mask that only shows the board
                hull = cv.convexHull(charuco_corners)
                cv.fillPoly(charuco_mask, np.int32([hull]), 255)

                # generate output images
                #-----------------------------------------------------------------------------------------------
                charuco_drawn = img.copy()
                cv.polylines(charuco_drawn, np.int32([hull]), True, (0, 255, 255), 5)
                aruco.drawDetectedCornersCharuco(charuco_drawn, charuco_corners , charuco_ids ,(0, 255, 0))
                
                if primary:
                    cv.imwrite('./out/extrinsic_calibration/charuco_convex_hull_primary.png', charuco_drawn)
                else:
                    cv.imwrite('./out/extrinsic_calibration/charuco_convex_hull_secondary.png', charuco_drawn)
                #-----------------------------------------------------------------------------------------------




            rvec = np.array([])
            tvec = np.array([])

            # Estimate pose and calculate rotation and translation
            retval, rvec, tvec = aruco.estimatePoseCharucoBoard(charucoCorners=charuco_corners,
                                                                charucoIds=charuco_ids,
                                                                board=board,
                                                                cameraMatrix=self.__camera.get_mtx(),
                                                                distCoeffs=self.__camera.get_dist(),
                                                                rvec=rvec,
                                                                tvec=tvec)
            if retval is True:
                # return params
                control_flag = True
                rvec, _ = cv.Rodrigues(rvec)
                return control_flag, rvec, tvec, charuco_mask
            else:
                return control_flag, [], [], charuco_mask
        else:
            return control_flag, [], [], charuco_mask

    def __get_pixel_colors(self, pts_laser, img_original):

        """
        Method generates weighted color-values for every point of the Laser-Line by checking the original image (image
        without laser).
        :param pts_laser: the Laser-Points
        :param img_original: the original image read in with opencv
        """

        color_values = np.empty((0, 3))

        for pts in pts_laser:
            # calculate decimal places
            decimal_place = pts[0] - int(pts[0])
            decimal_place_reverse = 1 - decimal_place

            # get colors
            color_rounded_pix = np.flip(np.array([img_original[int(pts[1])][int(pts[0])] / 255]))
            if int(pts[0]) >= img_original.shape[1] - 1:
                color_next_pix = color_rounded_pix
            else:
                color_next_pix = np.flip(np.array([img_original[int(pts[1])][int(pts[0]) + 1] / 255]))

            # calculate the weighted color
            weighted_color = (color_rounded_pix * decimal_place_reverse) + (color_next_pix * decimal_place)

            # append to color_values
            color_values = np.append(
                color_values,
                weighted_color,
                axis=0
            )

        return color_values

        # set the colors in the point cloud
        # self.__surface.colors = o3d.utility.Vector3dVector(color_values)

    def make_laser_lines_pcd(self):

        # generate sample laser plane 200 x 200
        x_values = np.array(range(-100, 100, 2)) / 1000
        y_values = np.array(range(-100, 100, 2)) / 1000
        plane_eq = self.__laser.get_plane_eq()

        x, y = np.meshgrid(x_values, y_values)

        x = x.reshape(-1)
        y = y.reshape(-1)

        z = (-plane_eq[3] - (plane_eq[0] * x) - (plane_eq[1] * y)) / plane_eq[2]

        xyz = np.vstack([x, y, z]).T

        # add the generated laser lines
        sample_plane_with_laser_lines = np.append(xyz, self.__laser.get_plane_points().T, axis=0)

        sample_plane_with_laser_lines = world2cam(
            pts=sample_plane_with_laser_lines.T,
            rot_matrix=self.__laser.get_up().get_rvec(),
            trans=self.__laser.get_up().get_tvec()
        )

        pcd_laser = o3d.geometry.PointCloud()
        pcd_laser.points = o3d.utility.Vector3dVector(sample_plane_with_laser_lines.T)
        pcd_laser.paint_uniform_color([1, 0, 0])
        return pcd_laser

    def get_point_cloud(self):
        return self.__surface

    def is_scanner_calibrated(self):
        return self.__calibrated

    def refresh_pcd(self, points, colors):
        self.__surface.points = o3d.utility.Vector3dVector(points)
        self.__surface.colors = o3d.utility.Vector3dVector(colors)

    def reset_pcd(self):
        self.__x_step = 0
        self.__surface = o3d.geometry.PointCloud()
