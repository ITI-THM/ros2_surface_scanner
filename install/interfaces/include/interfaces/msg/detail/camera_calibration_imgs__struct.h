// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/CameraCalibrationImgs.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__STRUCT_H_
#define INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'imgs'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in msg/CameraCalibrationImgs in the package interfaces.
typedef struct interfaces__msg__CameraCalibrationImgs
{
  sensor_msgs__msg__Image__Sequence imgs;
} interfaces__msg__CameraCalibrationImgs;

// Struct for a sequence of interfaces__msg__CameraCalibrationImgs.
typedef struct interfaces__msg__CameraCalibrationImgs__Sequence
{
  interfaces__msg__CameraCalibrationImgs * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__CameraCalibrationImgs__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__STRUCT_H_
