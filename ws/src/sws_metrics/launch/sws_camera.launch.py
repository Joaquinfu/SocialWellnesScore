from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition, UnlessCondition
from ament_index_python.packages import get_package_share_directory
import os

RS_LAUNCH = os.path.join(
    get_package_share_directory('realsense2_camera'),
    'launch', 'rs_launch.py')

def generate_launch_description():
    usb3 = LaunchConfiguration('usb3')

    return LaunchDescription([
        DeclareLaunchArgument('usb3', default_value='false'),

        # --- USB2 survival profile ---
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(RS_LAUNCH),
            condition=UnlessCondition(usb3),
            launch_arguments={
                'initial_reset': 'true',
                'depth_module.profile': '480x270x6',
                'rgb_camera.profile': '424x240x6',
                'enable_infra1': 'false',
                'enable_infra2': 'false',
                'align_depth.enable': 'true',
                'enable_sync': 'true',
            }.items(),
        ),

        # --- USB3 profile for cable day ---
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(RS_LAUNCH),
            condition=IfCondition(usb3),
            launch_arguments={
                'initial_reset': 'true',
                'depth_module.profile': '640x480x15',
                'rgb_camera.profile': '640x480x15',
                'enable_infra1': 'false',
                'enable_infra2': 'false',
                'align_depth.enable': 'true',
                'enable_sync': 'true',
            }.items(),
        ),
    ])
