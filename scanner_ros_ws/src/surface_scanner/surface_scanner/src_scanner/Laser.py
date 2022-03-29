import numpy as np
import cv2 as cv
import open3d as o3d
from .Laser_Line import LaserLine
import pyransac3d as pyrsc


def world2cam(pts, trans, rot_matrix):
    return rot_matrix @ pts + trans


def cam2world(pts, trans, rot_matrix):
    return np.linalg.inv(rot_matrix) @ (pts - trans)


def bild2world(pts, trans, rot_matrix, cam_matrix, plane=None):
    rot_inv = np.linalg.inv(rot_matrix)
    dir_vec = rot_inv @ np.linalg.inv(cam_matrix) @ pts
    pt_on_line = rot_inv @ trans
    # print(pt_on_line)
    if plane is not None:
        # print(plane)
        n = plane[:-1]
        n_pt = n @ pt_on_line
        n_dir = n @ dir_vec
        s = (n_pt - plane[3]) / n_dir
    else:
        s = pt_on_line[2] / dir_vec[2, :]
    return s * dir_vec - pt_on_line


def plane_fit_with_pyransac3d(points):
    plane = pyrsc.Plane()

    best_eq, best_inliers = plane.fit(points.T, 5)

    return best_eq


def plane_fit_with_svd(points):
    svd = np.linalg.svd(points - np.mean(points, axis=1, keepdims=True))

    plane = svd[0][:, -1]
    random_point = points.T[np.random.randint(0, points.shape[1])]

    # insert one random point to get D for plane equation like Ax + By + Cz + D = 0
    plane = np.append(
        plane, # A B C
        - random_point @ plane # D
    )

    return plane


class Laser:

    def __init__(self):

        self.__up: LaserLine = LaserLine()
        self.__down: LaserLine = LaserLine()
        self.__points = np.array([])
        self.__plane_eq = np.array([])

    def get_plane_eq(self):
        if len(self.__plane_eq) == 0:
            print("Warning!!! Plane-equation is not defined!")
            pass
        return self.__plane_eq

    def get_plane_points(self):
        return self.__points

    def get_up(self):
        return self.__up

    def set_up(self, up: LaserLine):
        self.__up = up

    def get_down(self):
        return self.__down

    def set_down(self, down: LaserLine):
        self.__down = down

    def display_laser_points(self, save_point_cloud=False):
        assert len(self.__points) != 0, "Plane points are not calculated! -> Calibrate Laser!"

        pcd = o3d.geometry.PointCloud()
        pcd.points = o3d.utility.Vector3dVector(self.__points.T)
        if save_point_cloud:
            o3d.io.write_point_cloud("../data/point_clouds/point_cloud_laser.ply", pcd)
        # make coordinate axis
        coordinate_axis = o3d.geometry.TriangleMesh.create_coordinate_frame(
            size=3,
            origin=[0, 0, 0]
        )
        o3d.visualization.draw_geometries([pcd, coordinate_axis])

    def make_plane_eq(self, camera_matrix):

        if len(self.__up.get_laser_points()) == 0 or len(self.__down.get_laser_points()) == 0:
            print("Warning! Laser-lines are not defined!")
            pass
        self.__calculate_plane_points(camera_matrix=camera_matrix)
        self.__fit_plane()

    def __calculate_plane_points(self, camera_matrix):

        pts_up = bild2world(
            pts=self.__up.get_laser_points(),
            cam_matrix=camera_matrix,
            rot_matrix=self.__up.get_rvec(),
            trans=self.__up.get_tvec()
        )

        pts_down = bild2world(
            pts=self.__down.get_laser_points(),
            cam_matrix=camera_matrix,
            rot_matrix=self.__down.get_rvec(),
            trans=self.__down.get_tvec()
        )

        # pts_up_cam = world2cam(
        #     pts=pts_up,
        #     trans=self.__up.get_tvec(),
        #     rot_matrix=self.__up.get_rvec()
        # )

        # switch down coordinates into up-coordinatsystem

        pts_down_cam = world2cam(
            pts=pts_down,
            trans=self.__down.get_tvec(),
            rot_matrix=self.__down.get_rvec()
        )

        pts_down_up = cam2world(
            pts=pts_down_cam,
            trans=self.__up.get_tvec(),
            rot_matrix=self.__up.get_rvec()
        )

        self.__points = np.append(pts_up, pts_down_up, axis=1)

    def __fit_plane(self):
        self.__plane_eq = plane_fit_with_svd(self.__points)
        # self.__plane_eq = plane_fit_with_pyransac3d(self.__points)
        # maybe some other algorithms to fit a plane in points
