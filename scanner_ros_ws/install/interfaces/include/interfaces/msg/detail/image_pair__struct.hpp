// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/ImagePair.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__IMAGE_PAIR__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__IMAGE_PAIR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'origin_img'
// Member 'laser_img'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__msg__ImagePair __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__ImagePair __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImagePair_
{
  using Type = ImagePair_<ContainerAllocator>;

  explicit ImagePair_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : origin_img(_init),
    laser_img(_init)
  {
    (void)_init;
  }

  explicit ImagePair_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : origin_img(_alloc, _init),
    laser_img(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _origin_img_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _origin_img_type origin_img;
  using _laser_img_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _laser_img_type laser_img;

  // setters for named parameter idiom
  Type & set__origin_img(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->origin_img = _arg;
    return *this;
  }
  Type & set__laser_img(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->laser_img = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::ImagePair_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::ImagePair_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::ImagePair_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::ImagePair_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::ImagePair_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::ImagePair_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::ImagePair_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::ImagePair_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::ImagePair_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::ImagePair_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__ImagePair
    std::shared_ptr<interfaces::msg::ImagePair_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__ImagePair
    std::shared_ptr<interfaces::msg::ImagePair_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImagePair_ & other) const
  {
    if (this->origin_img != other.origin_img) {
      return false;
    }
    if (this->laser_img != other.laser_img) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImagePair_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImagePair_

// alias to use template instance with default allocator
using ImagePair =
  interfaces::msg::ImagePair_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__IMAGE_PAIR__STRUCT_HPP_
