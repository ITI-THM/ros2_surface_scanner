// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/ImagePairRequest.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__STRUCT_H_
#define INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ImagePairRequest in the package interfaces.
typedef struct interfaces__srv__ImagePairRequest_Request
{
  uint8_t structure_needs_at_least_one_member;
} interfaces__srv__ImagePairRequest_Request;

// Struct for a sequence of interfaces__srv__ImagePairRequest_Request.
typedef struct interfaces__srv__ImagePairRequest_Request__Sequence
{
  interfaces__srv__ImagePairRequest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__ImagePairRequest_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'origin_img'
// Member 'laser_img'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in srv/ImagePairRequest in the package interfaces.
typedef struct interfaces__srv__ImagePairRequest_Response
{
  sensor_msgs__msg__Image origin_img;
  sensor_msgs__msg__Image laser_img;
} interfaces__srv__ImagePairRequest_Response;

// Struct for a sequence of interfaces__srv__ImagePairRequest_Response.
typedef struct interfaces__srv__ImagePairRequest_Response__Sequence
{
  interfaces__srv__ImagePairRequest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__ImagePairRequest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__STRUCT_H_
