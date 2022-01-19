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
  // origin_img
  sensor_msgs__msg__Image__fini(&msg->origin_img);
  // laser_img
  sensor_msgs__msg__Image__fini(&msg->laser_img);
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
