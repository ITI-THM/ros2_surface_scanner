import os
from glob import glob
from setuptools import setup

package_name = 'surface_scanner'
submodules = 'surface_scanner/src_scanner'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name, submodules],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*.launch.py'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='tristan',
    maintainer_email='tris.wolfram@googlemail.com',
    description='package for a laser-line-scanner',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'surface_scanner_node = surface_scanner.Surface_Scanner_Node:main',
            'camera_node = surface_scanner.Camera_Node:main',
            'camera_node_rasp = surface_scanner.Camera_Node_Rasp:main',
            'calibrate = surface_scanner.Calibrate_Client:calibrate_client_function',
            'calibrate_with_import = surface_scanner.Calibrate_Client:calibrate_client_import_function',
            'pcd_subscriber = surface_scanner.pcd_subscriber_node:main',
            'start_scan = surface_scanner.Calibrate_Client:trigger_send_img_pair_stream_function',
            'extr_calib_imgs = surface_scanner.Calibrate_Client:trigger_take_img_pair_calib_function',
            'intr_calib_imgs = surface_scanner.Calibrate_Client:trigger_take_cam_calib_imgs_function',
            'surface_line = surface_scanner.Calibrate_Client:trigger_surface_line_function',
            'start_img_stream = surface_scanner.Calibrate_Client:start_img_stream_function',
            'stop_img_stream = surface_scanner.Calibrate_Client:stop_img_stream_function',
        ],
    },
)
