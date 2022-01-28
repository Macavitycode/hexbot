/*
 * Read from the /pos_msgs topic and send values to Gazebo to control joint
 * pos through services
 */

#include "gazebo/gazebo.hh"
#include "hexbot/pos_msg.h"
#include "ros/ros.h"

void spawnCallback(const hexbot::pos_msg &msg) { ROS_INFO("%f", msg.pos[0]); }

int main(int argc, char **argv) {

  ros::init(argc, argv, "simple_sub");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("pos_msgs", 10, spawnCallback);
  ros::spin();

  return 0;
}
