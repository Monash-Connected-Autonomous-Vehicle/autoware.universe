#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <cstdio>
#include <signal.h>

#include "rclcpp/rclcpp.hpp"
#include "gmsl_interface.hpp"

gmsl_camera::GMSLCameraNode *gmsl_ptr;

void sig_int_handler(int sig)
{
  (void)sig;
  gmsl_ptr->g_runSetter(false);
}


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("gmsl_camera_interface");
  gmsl_camera::GMSLCameraNode gmsl;
  gmsl_ptr = &gmsl;  
  
  gmsl.argc_ = argc;
  gmsl.argv_ = argv;

  struct sigaction action;
  memset(&action, 0, sizeof(action));
  action.sa_handler = sig_int_handler;

  sigaction(SIGHUP, &action, NULL);  // controlling terminal closed, Ctrl-D
  sigaction(SIGINT, &action, NULL);  // Ctrl-C
  sigaction(SIGQUIT, &action, NULL); // Ctrl-\, clean quit with core dump
  sigaction(SIGABRT, &action, NULL); // abort() called.

  gmsl.run();
  return 0;
}

/*




int main(int argc, char **argv)
{
 
  
}

*/