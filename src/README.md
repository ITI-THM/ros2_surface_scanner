# The surface_scanner package

## Start the Scanner
To launch the whole surface scanner use the launch-file:
>```
>ros2 launch ros2_surface_scanner/launch/surface_scanner_launch.py
>```
This will start three nodes, the **surface_scanner_node**, **camera_node** and **rviz2**.

## Calibration
Now you have to calibrate the scanner. The calibration consists of an **intrinsic** and an **extrinsic** calibration. For the intrinsic calibration, a chessboard must be recorded from 10 different positions. For the extrinsic one, the special calibration board with the ChArUco board must be placed under the sensor.
>```
>ros2 run surface_scanner intr_calib_imgs
>```

>```
>ros2 run surface_scanner extr_calib_imgs
>```

>```
>ros2 run surface_scanner calibrate
>```

>```
>ros2 run surface_scanner calibrate_with_import <path to camera parameters>
>```


## Use the Scanner
>```
>ros2 run surface_scanner surface_line
>```
### Test Set-Up

>```
>ros2 run surface_scanner start_scan
>```