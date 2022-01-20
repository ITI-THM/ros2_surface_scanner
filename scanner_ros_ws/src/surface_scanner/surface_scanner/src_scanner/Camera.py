import numpy as np
import cv2 as cv


class Camera:
    """This class holds and calculates all camera data."""

    def __init__(self, src=None):

        if src:
            # unpack file with camera params
            loaded_file = np.load(src)

            # fill camera params
            self.__mtx = loaded_file['mtx']
            self.__dist = loaded_file['dist']
            self.__rvecs = loaded_file['rvecs']
            self.__tvecs = loaded_file['tvecs']
        else:
            self.__mtx = []
            self.__dist = []
            self.__rvecs = []
            self.__tvecs = []

    def get_mtx(self):
        return self.__mtx

    def get_dist(self):
        return self.__dist

    def get_rot(self, index: int):
        rot, _ = cv.Rodrigues(self.__rvecs[index])
        return rot

    def get_trans(self, index: int):
        return self.__tvecs[index]

    def import_camera_params(self, src: str):
        # unpack file with camera params
        loaded_file = np.load(src)

        # fill camera params
        self.__mtx = loaded_file['mtx']
        self.__dist = loaded_file['dist']
        self.__rvecs = loaded_file['rvecs']
        self.__tvecs = loaded_file['tvecs']

        print("INFO: Import camera params finished!")

    def calibrate_camera(self, pictures, save_data_in_npz: bool):

        criteria = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_MAX_ITER, 30, 0.001)

        objp = np.zeros((6 * 8, 3), np.float32)
        objp[:, :2] = np.mgrid[0:8, 0:6].T.reshape(-1, 2)

        obj_points = []  # 3d point in real world space
        img_points = []  # 2d points in image plane.

        img0 = cv.cvtColor(pictures[0], cv.COLOR_BGR2GRAY)

        img_counter = 0

        for pic in pictures:
            # print(f_name)
            gray = cv.cvtColor(pic, cv.COLOR_BGR2GRAY)
            # Find the chess board corners
            ret, corners = cv.findChessboardCorners(gray, (8, 6), None)
            # If found, add object points, image points (after refining them)
            if ret:
                # print(f"yes!!! index at {img_counter}")
                # print(f_name)
                obj_points.append(objp)

                corners2 = cv.cornerSubPix(gray, corners, (11, 11), (-1, -1), criteria)
                img_points.append(corners)

                # Draw and display the corners
                cv.drawChessboardCorners(pic, (8, 6), corners2, ret)
                cv.imwrite(f"/home/tristan/Praktikum/git/ros2_surface_scanner/scanner_ros_ws/src/surface_scanner/data/images/calibration/chessboard_corners/chessboard_corner_{img_counter}.png", pic)
                img_counter += 1

        cv.destroyAllWindows()

        ret, mtx, dist, rvecs, tvecs = cv.calibrateCamera(obj_points, img_points, img0.shape[::-1], None, None)

        self.__mtx = mtx
        self.__dist = dist
        self.__rvecs = rvecs
        self.__tvecs = tvecs

        # print("Camera matrix : \n")
        # print(mtx)
        # print("dist : \n")
        # print(dist)
        # print("rvecs : \n")
        # print(rvecs)
        # print(len(rvecs))
        # print("tvecs : \n")
        # print(tvecs)
        # print(len(tvecs))

        print(f"INFO: Camera calibration finished with camera matrix: \n {self.__mtx}!")

        if save_data_in_npz:
            np.savez_compressed('../data/camera_params/camera_params.npz', mtx=mtx, dist=dist, rvecs=rvecs, tvecs=tvecs)
            print("INFO: Camera-Params saved in 'camera_params.npz'!")
