// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/ImagePairRequest.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__ImagePairRequest_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__ImagePairRequest_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ImagePairRequest_Request_
{
  using Type = ImagePairRequest_Request_<ContainerAllocator>;

  explicit ImagePairRequest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ImagePairRequest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::ImagePairRequest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::ImagePairRequest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::ImagePairRequest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::ImagePairRequest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::ImagePairRequest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::ImagePairRequest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::ImagePairRequest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::ImagePairRequest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::ImagePairRequest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::ImagePairRequest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__ImagePairRequest_Request
    std::shared_ptr<interfaces::srv::ImagePairRequest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__ImagePairRequest_Request
    std::shared_ptr<interfaces::srv::ImagePairRequest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImagePairRequest_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImagePairRequest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImagePairRequest_Request_

// alias to use template instance with default allocator
using ImagePairRequest_Request =
  interfaces::srv::ImagePairRequest_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


// Include directives for member types
// Member 'origin_img'
// Member 'laser_img'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__srv__ImagePairRequest_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__ImagePairRequest_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ImagePairRequest_Response_
{
  using Type = ImagePairRequest_Response_<ContainerAllocator>;

  explicit ImagePairRequest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : origin_img(_init),
    laser_img(_init)
  {
    (void)_init;
  }

  explicit ImagePairRequest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    interfaces::srv::ImagePairRequest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::ImagePairRequest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::ImagePairRequest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::ImagePairRequest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::ImagePairRequest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::ImagePairRequest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::ImagePairRequest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::ImagePairRequest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::ImagePairRequest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::ImagePairRequest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__ImagePairRequest_Response
    std::shared_ptr<interfaces::srv::ImagePairRequest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__ImagePairRequest_Response
    std::shared_ptr<interfaces::srv::ImagePairRequest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImagePairRequest_Response_ & other) const
  {
    if (this->origin_img != other.origin_img) {
      return false;
    }
    if (this->laser_img != other.laser_img) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImagePairRequest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImagePairRequest_Response_

// alias to use template instance with default allocator
using ImagePairRequest_Response =
  interfaces::srv::ImagePairRequest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct ImagePairRequest
{
  using Request = interfaces::srv::ImagePairRequest_Request;
  using Response = interfaces::srv::ImagePairRequest_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__STRUCT_HPP_
