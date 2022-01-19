// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/CameraCalibrationImgs.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'imgs'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__msg__CameraCalibrationImgs __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__CameraCalibrationImgs __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CameraCalibrationImgs_
{
  using Type = CameraCalibrationImgs_<ContainerAllocator>;

  explicit CameraCalibrationImgs_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit CameraCalibrationImgs_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _imgs_type =
    std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::Image_<ContainerAllocator>>>;
  _imgs_type imgs;

  // setters for named parameter idiom
  Type & set__imgs(
    const std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::Image_<ContainerAllocator>>> & _arg)
  {
    this->imgs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::CameraCalibrationImgs_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::CameraCalibrationImgs_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::CameraCalibrationImgs_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::CameraCalibrationImgs_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::CameraCalibrationImgs_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::CameraCalibrationImgs_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::CameraCalibrationImgs_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::CameraCalibrationImgs_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::CameraCalibrationImgs_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::CameraCalibrationImgs_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__CameraCalibrationImgs
    std::shared_ptr<interfaces::msg::CameraCalibrationImgs_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__CameraCalibrationImgs
    std::shared_ptr<interfaces::msg::CameraCalibrationImgs_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CameraCalibrationImgs_ & other) const
  {
    if (this->imgs != other.imgs) {
      return false;
    }
    return true;
  }
  bool operator!=(const CameraCalibrationImgs_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CameraCalibrationImgs_

// alias to use template instance with default allocator
using CameraCalibrationImgs =
  interfaces::msg::CameraCalibrationImgs_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__STRUCT_HPP_
