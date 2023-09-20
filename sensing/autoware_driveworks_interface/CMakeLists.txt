cmake_minimum_required(VERSION 3.8)
project(autoware_driveworks_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(gmsl_interface src/gmsl_interface_node.cpp)
ament_target_dependencies(gmsl_interface rclcpp std_msgs sensor_msgs)

target_include_directories(gmsl_interface PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(gmsl_interface PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)
  
install(TARGETS
  talker
  listener
  gmsl_interface
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

## autoware ai
# cmake_minimum_required(VERSION 2.8.3)
# project(autoware_driveworks_interface)

# set(CMAKE_CXX_FLAGS "-O2 -s  -Wno-error=unused-parameter")

# find_package(autoware_build_flags REQUIRED)

# find_package(catkin REQUIRED COMPONENTS
#   autoware_msgs
#   roscpp
#   sensor_msgs
#   std_msgs
# )

# find_package(CUDA)

# catkin_package(
#   CATKIN_DEPENDS
#     autoware_msgs
#     sensor_msgs
#     std_msgs
# )
# find_library(DRIVEWORKS_FOUND NAMES driveworks)

# if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "aarch64"
#   AND CUDA_FOUND
#   AND DRIVEWORKS_FOUND
# )
#   if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     set(DRIVEWORKS_LINKER_FLAGS "-Wl,--unresolved-symbols=ignore-in-object-files -Wl,--allow-shlib-undefined")
#   elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#     set(DRIVEWORKS_LINKER_FLAGS "-Wl,-undefined,dynamic_lookup")
#   endif()

#   find_package(Threads REQUIRED)
#   find_package(OpenCV REQUIRED)

#   find_package(catkin REQUIRED COMPONENTS
#     cv_bridge
#     roscpp
#     sensor_msgs
#     std_msgs
#     tf
#   )

#   include_directories(
#     include
#     ${catkin_INCLUDE_DIRS}
#     ${Boost_INCLUDE_DIRS}
#     ${OpenCV_INCLUDE_DIRS}
#   )

#   link_directories(
#     ${catkin_LIBRARY_DIRS}
#     ${PCL_LIBRARY_DIRS}
#     ${OpenCV_LIBRARY_DIRS}
#     /usr/lib/
#     lib
#     /usr/local/driveworks/lib/
#     ${DRIVEWORKS_TOOLKIT_TARGET_DIR}/lib
#     ${CUDA_TOOLKIT_TARGET_DIR}/lib
#     ${CUDA_TOOLKIT_TARGET_DIR}/lib/stubs
#     ${NVIDIA_DRIVE_SDK_TARGET_DIR}/usr/lib
#     ${NVIDIA_TENSORRT_TARGET_DIR}/lib
#   )

#   add_executable(gmsl_interface
#     nodes/gmsl_interface/gmsl_interface_node.cpp
#   )

#   add_dependencies(gmsl_interface
#     ${catkin_EXPORTED_TARGETS}
#   )

#   target_link_libraries(gmsl_interface
#     ${catkin_LIBRARIES}
#     autoware_driveworks
#     driveworks
#     cudart
#     cuda
#     ${DRIVEWORKS_LINKER_FLAGS}
#   )

#   add_executable(tensorrt_interface
#     nodes/tensorrt_interface/tensorrt_interface_node.cpp
#   )

#   add_dependencies(tensorrt_interface
#     ${catkin_EXPORTED_TARGETS}
#   )

#   target_link_libraries(tensorrt_interface
#     ${catkin_LIBRARIES}
#     autoware_driveworks
#     driveworks
#     cudart
#     cuda
#     ${DRIVEWORKS_LINKER_FLAGS}
#   )

#   # Use configure_file instead of file(COPY ...) so that if the input file
#   # changes, it gets copied to the DEVEL space anyway
#   configure_file(lib/libautoware_driveworks.so ${CATKIN_DEVEL_PREFIX}/lib/libautoware_driveworks.so COPYONLY)

#   install(TARGETS tensorrt_interface gmsl_interface
#     ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#     LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#     RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#   )

#   install(DIRECTORY launch/
#     DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
#     PATTERN ".svn" EXCLUDE
#   )

#   install(FILES
#     lib/libautoware_driveworks.so
#     DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/lib/libautoware_driveworks.so
#   )
# else()
#   message("autoware_driveworks_interface won't be built, CUDA and aarch64 are required.")
# endif()