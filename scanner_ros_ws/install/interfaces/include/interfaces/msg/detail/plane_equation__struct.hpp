// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/PlaneEquation.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__PLANE_EQUATION__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__PLANE_EQUATION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__PlaneEquation __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__PlaneEquation __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PlaneEquation_
{
  using Type = PlaneEquation_<ContainerAllocator>;

  explicit PlaneEquation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 4>::iterator, double>(this->plane_equation.begin(), this->plane_equation.end(), 0.0);
    }
  }

  explicit PlaneEquation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : plane_equation(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 4>::iterator, double>(this->plane_equation.begin(), this->plane_equation.end(), 0.0);
    }
  }

  // field types and members
  using _plane_equation_type =
    std::array<double, 4>;
  _plane_equation_type plane_equation;

  // setters for named parameter idiom
  Type & set__plane_equation(
    const std::array<double, 4> & _arg)
  {
    this->plane_equation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::PlaneEquation_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::PlaneEquation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::PlaneEquation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::PlaneEquation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::PlaneEquation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::PlaneEquation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::PlaneEquation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::PlaneEquation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::PlaneEquation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::PlaneEquation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__PlaneEquation
    std::shared_ptr<interfaces::msg::PlaneEquation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__PlaneEquation
    std::shared_ptr<interfaces::msg::PlaneEquation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlaneEquation_ & other) const
  {
    if (this->plane_equation != other.plane_equation) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlaneEquation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlaneEquation_

// alias to use template instance with default allocator
using PlaneEquation =
  interfaces::msg::PlaneEquation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__PLANE_EQUATION__STRUCT_HPP_
