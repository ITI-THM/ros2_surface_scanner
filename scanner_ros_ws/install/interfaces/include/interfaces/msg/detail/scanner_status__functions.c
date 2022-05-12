// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/ScannerStatus.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/scanner_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
interfaces__msg__ScannerStatus__init(interfaces__msg__ScannerStatus * msg)
{
  if (!msg) {
    return false;
  }
  // is_scanner_active
  return true;
}

void
interfaces__msg__ScannerStatus__fini(interfaces__msg__ScannerStatus * msg)
{
  if (!msg) {
    return;
  }
  // is_scanner_active
}

bool
interfaces__msg__ScannerStatus__are_equal(const interfaces__msg__ScannerStatus * lhs, const interfaces__msg__ScannerStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_scanner_active
  if (lhs->is_scanner_active != rhs->is_scanner_active) {
    return false;
  }
  return true;
}

bool
interfaces__msg__ScannerStatus__copy(
  const interfaces__msg__ScannerStatus * input,
  interfaces__msg__ScannerStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // is_scanner_active
  output->is_scanner_active = input->is_scanner_active;
  return true;
}

interfaces__msg__ScannerStatus *
interfaces__msg__ScannerStatus__create()
{
  interfaces__msg__ScannerStatus * msg = (interfaces__msg__ScannerStatus *)malloc(sizeof(interfaces__msg__ScannerStatus));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__ScannerStatus));
  bool success = interfaces__msg__ScannerStatus__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__ScannerStatus__destroy(interfaces__msg__ScannerStatus * msg)
{
  if (msg) {
    interfaces__msg__ScannerStatus__fini(msg);
  }
  free(msg);
}


bool
interfaces__msg__ScannerStatus__Sequence__init(interfaces__msg__ScannerStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  interfaces__msg__ScannerStatus * data = NULL;
  if (size) {
    data = (interfaces__msg__ScannerStatus *)calloc(size, sizeof(interfaces__msg__ScannerStatus));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__ScannerStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__ScannerStatus__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__msg__ScannerStatus__Sequence__fini(interfaces__msg__ScannerStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__msg__ScannerStatus__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__msg__ScannerStatus__Sequence *
interfaces__msg__ScannerStatus__Sequence__create(size_t size)
{
  interfaces__msg__ScannerStatus__Sequence * array = (interfaces__msg__ScannerStatus__Sequence *)malloc(sizeof(interfaces__msg__ScannerStatus__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__ScannerStatus__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
interfaces__msg__ScannerStatus__Sequence__destroy(interfaces__msg__ScannerStatus__Sequence * array)
{
  if (array) {
    interfaces__msg__ScannerStatus__Sequence__fini(array);
  }
  free(array);
}

bool
interfaces__msg__ScannerStatus__Sequence__are_equal(const interfaces__msg__ScannerStatus__Sequence * lhs, const interfaces__msg__ScannerStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__ScannerStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__ScannerStatus__Sequence__copy(
  const interfaces__msg__ScannerStatus__Sequence * input,
  interfaces__msg__ScannerStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__ScannerStatus);
    interfaces__msg__ScannerStatus * data =
      (interfaces__msg__ScannerStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__ScannerStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__msg__ScannerStatus__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__msg__ScannerStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
