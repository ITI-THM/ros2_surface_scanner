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
            'subscriber_node = surface_scanner.Handler_Node:main',
            'calibrate = surface_scanner.Calibrate_Client:calibrate_client_function',
            'calibrate_with_import = surface_scanner.Calibrate_Client:calibrate_client_import_function',
            'pcd_subscriber = surface_scanner.pcd_subscriber_node:main',
            'start_scan = surface_scanner.Calibrate_Client:trigger_send_img_pair_stream_function',
            'extr_calib_imgs = surface_scanner.Calibrate_Client:trigger_take_img_pair_function',
            'intr_calib_imgs = surface_scanner.Calibrate_Client:trigger_take_cam_calib_imgs_function',
            'surface_line = surface_scanner.Calibrate_Client:trigger_surface_line_function',
        ],
    },
)
