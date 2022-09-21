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
            executable='camera_node_rasp',
            name='camera'
        )
    ])