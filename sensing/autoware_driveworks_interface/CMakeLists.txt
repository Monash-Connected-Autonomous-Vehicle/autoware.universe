cmake_minimum_required(VERSION 3.5)
project(autoware_driveworks_interface)

# Defaults to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find ROS 2 dependencies
find_package(ament_cmake_auto REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(autoware_msgs REQUIRED)

# Find CUDA
find_package(CUDA REQUIRED)
set(CUDA_TOOLKIT_ROOT_DIR "/path/to/your/cuda/toolkit")  # Replace with the actual path

# Find DriveWorks
find_library(DRIVEWORKS_FOUND NAMES driveworks)

if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "aarch64"
  AND CUDA_FOUND
  AND DRIVEWORKS_FOUND
)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(DRIVEWORKS_LINKER_FLAGS "-Wl,--unresolved-symbols=ignore-in-object-files -Wl,--allow-shlib-undefined")
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(DRIVEWORKS_LINKER_FLAGS "-Wl,-undefined,dynamic_lookup")
  endif()

  find_package(Threads REQUIRED)
  find_package(OpenCV REQUIRED)

  # Add your package's source files here
  add_executable(gmsl_interface
    nodes/gmsl_interface/gmsl_interface_node.cpp
  )

  ament_target_dependencies(gmsl_interface
    rclcpp
    std_msgs
    sensor_msgs
    autoware_msgs
  )

  target_include_directories(gmsl_interface PUBLIC
    include
  )

  link_directories(
    ${PCL_LIBRARY_DIRS}
    ${OpenCV_LIBRARY_DIRS}
    /usr/lib/
    lib
    /usr/local/driveworks/lib/
    ${DRIVEWORKS_TOOLKIT_TARGET_DIR}/lib
    ${CUDA_TOOLKIT_TARGET_DIR}/lib
    ${CUDA_TOOLKIT_TARGET_DIR}/lib/stubs
    ${NVIDIA_DRIVE_SDK_TARGET_DIR}/usr/lib
  )

  target_link_libraries(gmsl_interface
    autoware_driveworks
    driveworks
    cudart
    cuda
    ${DRIVEWORKS_LINKER_FLAGS}
  )

  install(TARGETS
    gmsl_interface
    DESTINATION lib/${PROJECT_NAME}
  )

endif()

ament_package()
