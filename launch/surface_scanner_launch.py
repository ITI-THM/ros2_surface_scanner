from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='surface_scanner',
            executable='surface_scanner_node',
            name='scanner'
        ),
        Node(
            package='surface_scanner',
            executable='camera_node',
            name='camera'
        ),
        Node(
            package='rviz2',
            executable='rviz2',
            name='pcd_subscriber'
        )
    ])
