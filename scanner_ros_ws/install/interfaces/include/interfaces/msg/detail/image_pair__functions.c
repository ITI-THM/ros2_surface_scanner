// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/ImagePair.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/image_pair__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `origin_img`
// Member `laser_img`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
interfaces__msg__ImagePair__init(interfaces__msg__ImagePair * msg)
{
  if (!msg) {
    return false;
  }
  // is_for_laser_calib
  // origin_img
  if (!sensor_msgs__msg__Image__init(&msg->origin_img)) {
    interfaces__msg__ImagePair__fini(msg);
    return false;
  }
  // laser_img
  if (!sensor_msgs__msg__Image__init(&msg->laser_img)) {
    interfaces__msg__ImagePair__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__msg__ImagePair__fini(interfaces__msg__ImagePair * msg)
{
  if (!msg) {
    return;
  }
  // is_for_laser_calib
  // origin_img
  sensor_msgs__msg__Image__fini(&msg->origin_img);
  // laser_img
  sensor_msgs__msg__Image__fini(&msg->laser_img);
}

bool
interfaces__msg__ImagePair__are_equal(const interfaces__msg__ImagePair * lhs, const interfaces__msg__ImagePair * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_for_laser_calib
  if (lhs->is_for_laser_calib != rhs->is_for_laser_calib) {
    return false;
  }
  // origin_img
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->origin_img), &(rhs->origin_img)))
  {
    return false;
  }
  // laser_img
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->laser_img), &(rhs->laser_img)))
  {
    return false;
  }
  return true;
}

bool
interfaces__msg__ImagePair__copy(
  const interfaces__msg__ImagePair * input,
  interfaces__msg__ImagePair * output)
{
  if (!input || !output) {
    return false;
  }
  // is_for_laser_calib
  output->is_for_laser_calib = input->is_for_laser_calib;
  // origin_img
  if (!sensor_msgs__msg__Image__copy(
      &(input->origin_img), &(output->origin_img)))
  {
    return false;
  }
  // laser_img
  if (!sensor_msgs__msg__Image__copy(
      &(input->laser_img), &(output->laser_img)))
  {
    return false;
  }
  return true;
}

interfaces__msg__ImagePair *
interfaces__msg__ImagePair__create()
{
  interfaces__msg__ImagePair * msg = (interfaces__msg__ImagePair *)malloc(sizeof(interfaces__msg__ImagePair));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__ImagePair));
  bool success = interfaces__msg__ImagePair__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__ImagePair__destroy(interfaces__msg__ImagePair * msg)
{
  if (msg) {
    interfaces__msg__ImagePair__fini(msg);
  }
  free(msg);
}


bool
interfaces__msg__ImagePair__Sequence__init(interfaces__msg__ImagePair__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  interfaces__msg__ImagePair * data = NULL;
  if (size) {
    data = (interfaces__msg__ImagePair *)calloc(size, sizeof(interfaces__msg__ImagePair));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__ImagePair__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__ImagePair__fini(&data[i - 1]);
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
interfaces__msg__ImagePair__Sequence__fini(interfaces__msg__ImagePair__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__msg__ImagePair__fini(&array->data[i]);
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

interfaces__msg__ImagePair__Sequence *
interfaces__msg__ImagePair__Sequence__create(size_t size)
{
  interfaces__msg__ImagePair__Sequence * array = (interfaces__msg__ImagePair__Sequence *)malloc(sizeof(interfaces__msg__ImagePair__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__ImagePair__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
interfaces__msg__ImagePair__Sequence__destroy(interfaces__msg__ImagePair__Sequence * array)
{
  if (array) {
    interfaces__msg__ImagePair__Sequence__fini(array);
  }
  free(array);
}

bool
interfaces__msg__ImagePair__Sequence__are_equal(const interfaces__msg__ImagePair__Sequence * lhs, const interfaces__msg__ImagePair__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__ImagePair__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__ImagePair__Sequence__copy(
  const interfaces__msg__ImagePair__Sequence * input,
  interfaces__msg__ImagePair__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__ImagePair);
    interfaces__msg__ImagePair * data =
      (interfaces__msg__ImagePair *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__ImagePair__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__msg__ImagePair__fini(&data[i]);
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
    if (!interfaces__msg__ImagePair__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
