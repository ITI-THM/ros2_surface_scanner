// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interfaces:srv/CalibrateLaserImport.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__FUNCTIONS_H_
#define INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "interfaces/srv/detail/calibrate_laser_import__struct.h"

/// Initialize srv/CalibrateLaserImport message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaces__srv__CalibrateLaserImport_Request
 * )) before or use
 * interfaces__srv__CalibrateLaserImport_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__srv__CalibrateLaserImport_Request__init(interfaces__srv__CalibrateLaserImport_Request * msg);

/// Finalize srv/CalibrateLaserImport message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__srv__CalibrateLaserImport_Request__fini(interfaces__srv__CalibrateLaserImport_Request * msg);

/// Create srv/CalibrateLaserImport message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaces__srv__CalibrateLaserImport_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
interfaces__srv__CalibrateLaserImport_Request *
interfaces__srv__CalibrateLaserImport_Request__create();

/// Destroy srv/CalibrateLaserImport message.
/**
 * It calls
 * interfaces__srv__CalibrateLaserImport_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__srv__CalibrateLaserImport_Request__destroy(interfaces__srv__CalibrateLaserImport_Request * msg);


/// Initialize array of srv/CalibrateLaserImport messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaces__srv__CalibrateLaserImport_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__srv__CalibrateLaserImport_Request__Sequence__init(interfaces__srv__CalibrateLaserImport_Request__Sequence * array, size_t size);

/// Finalize array of srv/CalibrateLaserImport messages.
/**
 * It calls
 * interfaces__srv__CalibrateLaserImport_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__srv__CalibrateLaserImport_Request__Sequence__fini(interfaces__srv__CalibrateLaserImport_Request__Sequence * array);

/// Create array of srv/CalibrateLaserImport messages.
/**
 * It allocates the memory for the array and calls
 * interfaces__srv__CalibrateLaserImport_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
interfaces__srv__CalibrateLaserImport_Request__Sequence *
interfaces__srv__CalibrateLaserImport_Request__Sequence__create(size_t size);

/// Destroy array of srv/CalibrateLaserImport messages.
/**
 * It calls
 * interfaces__srv__CalibrateLaserImport_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__srv__CalibrateLaserImport_Request__Sequence__destroy(interfaces__srv__CalibrateLaserImport_Request__Sequence * array);

/// Initialize srv/CalibrateLaserImport message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaces__srv__CalibrateLaserImport_Response
 * )) before or use
 * interfaces__srv__CalibrateLaserImport_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__srv__CalibrateLaserImport_Response__init(interfaces__srv__CalibrateLaserImport_Response * msg);

/// Finalize srv/CalibrateLaserImport message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__srv__CalibrateLaserImport_Response__fini(interfaces__srv__CalibrateLaserImport_Response * msg);

/// Create srv/CalibrateLaserImport message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaces__srv__CalibrateLaserImport_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
interfaces__srv__CalibrateLaserImport_Response *
interfaces__srv__CalibrateLaserImport_Response__create();

/// Destroy srv/CalibrateLaserImport message.
/**
 * It calls
 * interfaces__srv__CalibrateLaserImport_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__srv__CalibrateLaserImport_Response__destroy(interfaces__srv__CalibrateLaserImport_Response * msg);


/// Initialize array of srv/CalibrateLaserImport messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaces__srv__CalibrateLaserImport_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__srv__CalibrateLaserImport_Response__Sequence__init(interfaces__srv__CalibrateLaserImport_Response__Sequence * array, size_t size);

/// Finalize array of srv/CalibrateLaserImport messages.
/**
 * It calls
 * interfaces__srv__CalibrateLaserImport_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__srv__CalibrateLaserImport_Response__Sequence__fini(interfaces__srv__CalibrateLaserImport_Response__Sequence * array);

/// Create array of srv/CalibrateLaserImport messages.
/**
 * It allocates the memory for the array and calls
 * interfaces__srv__CalibrateLaserImport_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
interfaces__srv__CalibrateLaserImport_Response__Sequence *
interfaces__srv__CalibrateLaserImport_Response__Sequence__create(size_t size);

/// Destroy array of srv/CalibrateLaserImport messages.
/**
 * It calls
 * interfaces__srv__CalibrateLaserImport_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__srv__CalibrateLaserImport_Response__Sequence__destroy(interfaces__srv__CalibrateLaserImport_Response__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__FUNCTIONS_H_
