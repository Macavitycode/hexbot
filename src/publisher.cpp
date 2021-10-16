#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "hexbot/vel_msg.h"

struct vel_msgs {
    std_msgs::Float64 vel_msg[18];
};

int main(int argc, char **argv)
{
  // ROS objects
  ros::init(argc, argv, "my_publisher");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<hexbot::vel_msg>("vel_msgs", 1);
  ros::Rate loop_rate(0.5);

  // the message to be published
  hexbot::vel_msg msg;

  msg.velocities = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while (ros::ok())
  {
    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
