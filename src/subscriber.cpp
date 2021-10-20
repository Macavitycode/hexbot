/* 
 * Read from the /vel_msgs topic and send values to Gazebo to control joint 
 * velocities through services
 */

#include "ros/ros.h"
#include "hexbot/vel_msg.h"
#include "gazebo/gazebo.hh"

void spawnCallback(const hexbot::vel_msg& msg){
    ROS_INFO("%f", msg.velocities[0]);
}

int main(int argc, char **argv){

    ros::init(argc, argv, "simple_sub");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("vel_msgs", 10, spawnCallback);
    ros::spin();

    return 0;
}
