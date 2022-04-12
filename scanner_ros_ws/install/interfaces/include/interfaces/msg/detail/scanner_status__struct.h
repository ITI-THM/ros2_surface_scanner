// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/ScannerStatus.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SCANNER_STATUS__STRUCT_H_
#define INTERFACES__MSG__DETAIL__SCANNER_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ScannerStatus in the package interfaces.
typedef struct interfaces__msg__ScannerStatus
{
  bool is_scanner_active;
} interfaces__msg__ScannerStatus;

// Struct for a sequence of interfaces__msg__ScannerStatus.
typedef struct interfaces__msg__ScannerStatus__Sequence
{
  interfaces__msg__ScannerStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__ScannerStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__SCANNER_STATUS__STRUCT_H_
