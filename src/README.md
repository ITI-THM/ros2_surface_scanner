# The surface_scanner package

## Nodes
### surface_scanner_node
Responsible for all calculations. Stores all data.
#### Subscribed Topics
* **`/CameraCalibrationImgs`**

    List of 10 images for intrinsic calibration.
* **`/ImagePair`**

    Two images for extrinsic calibration or to reconstruct surface line.
* **`/ScannerStatus`**

    Boolean flag that shows the scanner status (is scanning, is not scanning)
#### Published Topics
* **`/pointcloud`** ([sensor_msgs/PointCloud2])

    The resulting pointcloud.
#### Services
* **`calibrate_scanner`**

    Calibrates the scanner. Only usable if the scanner has recieved the calibration (intrinsic and extrinsic) images. Calibration result can be checked via Rviz2.
* **`calibrate_with_import`**

    Calibrates the scanner by importing the camera data. Only usable if the scanner has recieved the extrinsic calibration images. Path to the intrisic camera data as **.npz**-file is required. Calibration result can be checked via Rviz2.

### camera_node
The optical sensor of the triangolation sensor. Takes images for calibration and to reconstruct the surface. The pictures will be send to the surface_scanner_node via special topics.
#### Published Topics
* **`/CameraCalibrationImgs`**

    Images for intrinsic calibration.
* **`/ImagePair`**

    Two images for extrinsic calibration or to reconstruct surface line.
#### Services
* **`send_cam_calib_imgs`**

    Used to take 10 images for intrinsic camera calibration. The image list will be published via **/CameraCalibrationImgs**-Topic.
* **`send_laser_calib_imgs`**

    Used to take an image pair of the special calibration board. The image pair will be published via **/ImagePair**-Topic.

* **`send_img_pair_surface`**

    Used to take an image pair of the surface. The image pair will be published via **/ImagePair**-Topic.

### rviz2
Used as point cloud subscriber
#### Subscribed Topics
* **`/pointcloud`** ([sensor_msgs/PointCloud2])

    [Rviz2](http://wiki.ros.org/rviz) shows the resulting pointcloud. Here you can review the results of the ongoing scan.

## Usage
### Start the Scanner
To launch the whole surface scanner use the launch-file:
```
ros2 launch ros2_surface_scanner/launch/surface_scanner_launch.py
```
This will start three nodes, the **surface_scanner_node**, **camera_node** and **rviz2**.

### Calibration
Now you have to calibrate the scanner. The calibration consists of an **intrinsic** and an **extrinsic** calibration. For the intrinsic calibration, a chessboard must be recorded from 10 different positions. For the extrinsic one, the special calibration board with the ChArUco board must be placed under the sensor.
```
ros2 run surface_scanner intr_calib_imgs
```

```
ros2 run surface_scanner extr_calib_imgs
```

```
ros2 run surface_scanner calibrate
```

```
ros2 run surface_scanner calibrate_with_import <path to camera parameters>
```


### Use the Scanner
```
ros2 run surface_scanner surface_line
```
#### Test Set-Up

```
ros2 run surface_scanner start_scan
```