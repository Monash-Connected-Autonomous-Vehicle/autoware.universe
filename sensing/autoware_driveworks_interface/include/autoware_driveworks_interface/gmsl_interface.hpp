#ifndef GMSL_CAMERA_CORE_H
#define GMSL_CAMERA_CORE_H

// ROS includes
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
  // handle
  //ros::NodeHandle nh_; // ?
  //ros::NodeHandle private_nh_; // ?

  bool gTakeScreenshot = false;
  int gScreenshotCount = 0;
  uint32_t imageWidth;
  uint32_t imageHeight;

  // initializer
  void initForROS();
  void initForDW();
};
}
#endif


// Autoware ai: 
/*

#ifndef GMSL_CAMERA_CORE_H
#define GMSL_CAMERA_CORE_H

// ROS includes
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

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
  // handle
  ros::NodeHandle nh_;
  ros::NodeHandle private_nh_;

  bool gTakeScreenshot = false;
  int gScreenshotCount = 0;
  uint32_t imageWidth;
  uint32_t imageHeight;

  // initializer
  void initForROS();
  void initForDW();
};
}
#endif

*/