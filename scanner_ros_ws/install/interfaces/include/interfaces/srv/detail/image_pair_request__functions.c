// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:srv/ImagePairRequest.idl
// generated code does not contain a copyright notice
#include "interfaces/srv/detail/image_pair_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
interfaces__srv__ImagePairRequest_Request__init(interfaces__srv__ImagePairRequest_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
interfaces__srv__ImagePairRequest_Request__fini(interfaces__srv__ImagePairRequest_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
interfaces__srv__ImagePairRequest_Request__are_equal(const interfaces__srv__ImagePairRequest_Request * lhs, const interfaces__srv__ImagePairRequest_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
interfaces__srv__ImagePairRequest_Request__copy(
  const interfaces__srv__ImagePairRequest_Request * input,
  interfaces__srv__ImagePairRequest_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

interfaces__srv__ImagePairRequest_Request *
interfaces__srv__ImagePairRequest_Request__create()
{
  interfaces__srv__ImagePairRequest_Request * msg = (interfaces__srv__ImagePairRequest_Request *)malloc(sizeof(interfaces__srv__ImagePairRequest_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__srv__ImagePairRequest_Request));
  bool success = interfaces__srv__ImagePairRequest_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
interfaces__srv__ImagePairRequest_Request__destroy(interfaces__srv__ImagePairRequest_Request * msg)
{
  if (msg) {
    interfaces__srv__ImagePairRequest_Request__fini(msg);
  }
  free(msg);
}


bool
interfaces__srv__ImagePairRequest_Request__Sequence__init(interfaces__srv__ImagePairRequest_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  interfaces__srv__ImagePairRequest_Request * data = NULL;
  if (size) {
    data = (interfaces__srv__ImagePairRequest_Request *)calloc(size, sizeof(interfaces__srv__ImagePairRequest_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__srv__ImagePairRequest_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__srv__ImagePairRequest_Request__fini(&data[i - 1]);
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
interfaces__srv__ImagePairRequest_Request__Sequence__fini(interfaces__srv__ImagePairRequest_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__srv__ImagePairRequest_Request__fini(&array->data[i]);
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

interfaces__srv__ImagePairRequest_Request__Sequence *
interfaces__srv__ImagePairRequest_Request__Sequence__create(size_t size)
{
  interfaces__srv__ImagePairRequest_Request__Sequence * array = (interfaces__srv__ImagePairRequest_Request__Sequence *)malloc(sizeof(interfaces__srv__ImagePairRequest_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = interfaces__srv__ImagePairRequest_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
interfaces__srv__ImagePairRequest_Request__Sequence__destroy(interfaces__srv__ImagePairRequest_Request__Sequence * array)
{
  if (array) {
    interfaces__srv__ImagePairRequest_Request__Sequence__fini(array);
  }
  free(array);
}

bool
interfaces__srv__ImagePairRequest_Request__Sequence__are_equal(const interfaces__srv__ImagePairRequest_Request__Sequence * lhs, const interfaces__srv__ImagePairRequest_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__srv__ImagePairRequest_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__srv__ImagePairRequest_Request__Sequence__copy(
  const interfaces__srv__ImagePairRequest_Request__Sequence * input,
  interfaces__srv__ImagePairRequest_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__srv__ImagePairRequest_Request);
    interfaces__srv__ImagePairRequest_Request * data =
      (interfaces__srv__ImagePairRequest_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__srv__ImagePairRequest_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__srv__ImagePairRequest_Request__fini(&data[i]);
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
    if (!interfaces__srv__ImagePairRequest_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `origin_img`
// Member `laser_img`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
interfaces__srv__ImagePairRequest_Response__init(interfaces__srv__ImagePairRequest_Response * msg)
{
  if (!msg) {
    return false;
  }
  // origin_img
  if (!sensor_msgs__msg__Image__init(&msg->origin_img)) {
    interfaces__srv__ImagePairRequest_Response__fini(msg);
    return false;
  }
  // laser_img
  if (!sensor_msgs__msg__Image__init(&msg->laser_img)) {
    interfaces__srv__ImagePairRequest_Response__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__srv__ImagePairRequest_Response__fini(interfaces__srv__ImagePairRequest_Response * msg)
{
  if (!msg) {
    return;
  }
  // origin_img
  sensor_msgs__msg__Image__fini(&msg->origin_img);
  // laser_img
  sensor_msgs__msg__Image__fini(&msg->laser_img);
}

bool
interfaces__srv__ImagePairRequest_Response__are_equal(const interfaces__srv__ImagePairRequest_Response * lhs, const interfaces__srv__ImagePairRequest_Response * rhs)
{
  if (!lhs || !rhs) {
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
interfaces__srv__ImagePairRequest_Response__copy(
  const interfaces__srv__ImagePairRequest_Response * input,
  interfaces__srv__ImagePairRequest_Response * output)
{
  if (!input || !output) {
    return false;
  }
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

interfaces__srv__ImagePairRequest_Response *
interfaces__srv__ImagePairRequest_Response__create()
{
  interfaces__srv__ImagePairRequest_Response * msg = (interfaces__srv__ImagePairRequest_Response *)malloc(sizeof(interfaces__srv__ImagePairRequest_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__srv__ImagePairRequest_Response));
  bool success = interfaces__srv__ImagePairRequest_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
interfaces__srv__ImagePairRequest_Response__destroy(interfaces__srv__ImagePairRequest_Response * msg)
{
  if (msg) {
    interfaces__srv__ImagePairRequest_Response__fini(msg);
  }
  free(msg);
}


bool
interfaces__srv__ImagePairRequest_Response__Sequence__init(interfaces__srv__ImagePairRequest_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  interfaces__srv__ImagePairRequest_Response * data = NULL;
  if (size) {
    data = (interfaces__srv__ImagePairRequest_Response *)calloc(size, sizeof(interfaces__srv__ImagePairRequest_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__srv__ImagePairRequest_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__srv__ImagePairRequest_Response__fini(&data[i - 1]);
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
interfaces__srv__ImagePairRequest_Response__Sequence__fini(interfaces__srv__ImagePairRequest_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__srv__ImagePairRequest_Response__fini(&array->data[i]);
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

interfaces__srv__ImagePairRequest_Response__Sequence *
interfaces__srv__ImagePairRequest_Response__Sequence__create(size_t size)
{
  interfaces__srv__ImagePairRequest_Response__Sequence * array = (interfaces__srv__ImagePairRequest_Response__Sequence *)malloc(sizeof(interfaces__srv__ImagePairRequest_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = interfaces__srv__ImagePairRequest_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
interfaces__srv__ImagePairRequest_Response__Sequence__destroy(interfaces__srv__ImagePairRequest_Response__Sequence * array)
{
  if (array) {
    interfaces__srv__ImagePairRequest_Response__Sequence__fini(array);
  }
  free(array);
}

bool
interfaces__srv__ImagePairRequest_Response__Sequence__are_equal(const interfaces__srv__ImagePairRequest_Response__Sequence * lhs, const interfaces__srv__ImagePairRequest_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__srv__ImagePairRequest_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__srv__ImagePairRequest_Response__Sequence__copy(
  const interfaces__srv__ImagePairRequest_Response__Sequence * input,
  interfaces__srv__ImagePairRequest_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__srv__ImagePairRequest_Response);
    interfaces__srv__ImagePairRequest_Response * data =
      (interfaces__srv__ImagePairRequest_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__srv__ImagePairRequest_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__srv__ImagePairRequest_Response__fini(&data[i]);
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
    if (!interfaces__srv__ImagePairRequest_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
