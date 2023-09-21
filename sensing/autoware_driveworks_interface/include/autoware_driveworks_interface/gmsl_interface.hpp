#ifndef GMSL_CAMERA_CORE_H
#define GMSL_CAMERA_CORE_H

// ROS 2 includes
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"

namespace gmsl_camera
{
class GMSLCameraNode
{
public:
  GMSLCameraNode();
  ~GMSLCameraNode();

  void run();
  void g_runSetter(bool);
  int argc_;
  char **argv_;

private:
  // Handle for ROS 2
  rclcpp::Node::SharedPtr node_;

  bool gTakeScreenshot = false;
  int gScreenshotCount = 0;
  uint32_t imageWidth;
  uint32_t imageHeight;

  // Initializer for ROS 2
  void initForROS();
  void initForDW();
};
} // namespace gmsl_camera

#endif
