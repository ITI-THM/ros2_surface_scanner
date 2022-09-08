import numpy as np
import cv2 as cv


class Camera:
    """
    This class holds and calculates all camera data.
    Camera data are the camera matrix, the distortion coefficients, the rotation vectors and translation vectors
    """

    def __init__(self, src=None):

        if src:
            # unpack file with camera params
            loaded_file = np.load(src)

            # fill camera params
            self.__cam_mtx = loaded_file['mtx']
            self.__dist = loaded_file['dist']
            self.__rvecs = loaded_file['rvecs']
            self.__tvecs = loaded_file['tvecs']
        else:
            self.__cam_mtx = []
            self.__dist = []
            self.__rvecs = []
            self.__tvecs = []

    def get_cam_mtx(self):
        return self.__cam_mtx

    def get_dist(self):
        return self.__dist

    def get_rot_mtx_at(self, index: int):
        rot, _ = cv.Rodrigues(self.__rvecs[index])
        return rot

    def get_tvec_at(self, index: int):
        return self.__tvecs[index]

    def import_camera_params(self, src: str):

        '''
        Gets a source file (src) and imports the camera data.
        Source file should be an .npz-file
        '''

        # unpack file with camera params
        loaded_file = np.load(src)

        # fill camera params
        self.__cam_mtx = loaded_file['mtx']
        self.__dist = loaded_file['dist']
        self.__rvecs = loaded_file['rvecs']
        self.__tvecs = loaded_file['tvecs']

        print("INFO: Import camera params finished!")

    def calibrate_camera(self, pictures, save_data_in_npz: bool = False):

        '''
        Method to calibrate the camera. Gets a list of calibration images and calculates
        the camera data.
        Camera calibration method is acorrding to https://docs.opencv.org/4.5.5/dc/dbb/tutorial_py_calibration.html
        Boolean flag 'save_data_in_npz' can be set to save the camera data in .npz-file
        '''

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
                cv.imwrite(f"./src/ros2_surface_scanner/surface_scanner/out/intinsic_calibration/chessboard_corner_{img_counter}.png", pic)
                img_counter += 1

        cv.destroyAllWindows()

        ret, mtx, dist, rvecs, tvecs = cv.calibrateCamera(obj_points, img_points, img0.shape[::-1], None, None)

        self.__cam_mtx = mtx
        self.__dist = dist
        self.__rvecs = rvecs
        self.__tvecs = tvecs

        print(f"INFO: Camera calibration finished with camera matrix: \n {self.__cam_mtx}!")

        if save_data_in_npz:
            np.savez_compressed('./src/ros2_surface_scanner/surface_scanner/out/intinsic_calibration/camera_params.npz', mtx=mtx, dist=dist, rvecs=rvecs, tvecs=tvecs)
            print("INFO: Camera-Params saved in 'camera_params.npz'!")
