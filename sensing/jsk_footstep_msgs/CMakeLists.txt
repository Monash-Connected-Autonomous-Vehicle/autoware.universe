cmake_minimum_required(VERSION 3.5)
project(jsk_footstep_msgs)


# Load ament_cmake and all dependencies required for this package
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(action_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Define custom message files
set(custom_msg_files
  "msg/Footstep.msg"
  "msg/FootstepArray.msg"
)

# Generate ROS 2 interfaces for custom messages
rosidl_generate_interfaces(${PROJECT_NAME}
  ${custom_msg_files}
  ADD_LINTER_TESTS
  DEPENDENCIES
    std_msgs
    geometry_msgs
    action_msgs
)

# Define dependencies for this package
ament_export_dependencies(
  std_msgs
  geometry_msgs
  action_msgs
  rosidl_default_runtime
)

# Install ROS 2 interfaces
ament_package()
