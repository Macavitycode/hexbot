#include "hexbot/pos_msg.h"
#include "ros/ros.h"

int main(int argc, char **argv) {

  // ROS objects
  ros::init(argc, argv, "simple_pub");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<hexbot::pos_msg>("pos_msgs", 1);
  ros::Rate loop_rate(10);

  // the message to be published
  hexbot::pos_msg msg;

  msg.pos = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while (ros::ok()) {
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
