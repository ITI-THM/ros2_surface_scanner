// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/ImagePair.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__IMAGE_PAIR__STRUCT_H_
#define INTERFACES__MSG__DETAIL__IMAGE_PAIR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'origin_img'
// Member 'laser_img'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in msg/ImagePair in the package interfaces.
typedef struct interfaces__msg__ImagePair
{
  bool is_for_laser_calib;
  sensor_msgs__msg__Image origin_img;
  sensor_msgs__msg__Image laser_img;
} interfaces__msg__ImagePair;

// Struct for a sequence of interfaces__msg__ImagePair.
typedef struct interfaces__msg__ImagePair__Sequence
{
  interfaces__msg__ImagePair * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__ImagePair__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__IMAGE_PAIR__STRUCT_H_
