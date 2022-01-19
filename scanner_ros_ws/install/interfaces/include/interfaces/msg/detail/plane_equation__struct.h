// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/PlaneEquation.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__PLANE_EQUATION__STRUCT_H_
#define INTERFACES__MSG__DETAIL__PLANE_EQUATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/PlaneEquation in the package interfaces.
typedef struct interfaces__msg__PlaneEquation
{
  double plane_equation[4];
} interfaces__msg__PlaneEquation;

// Struct for a sequence of interfaces__msg__PlaneEquation.
typedef struct interfaces__msg__PlaneEquation__Sequence
{
  interfaces__msg__PlaneEquation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__PlaneEquation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__PLANE_EQUATION__STRUCT_H_
