#include "ros/ros.h"
#include "hexbot/vel_msg.h"

int main(int argc, char **argv) {

    // ROS objects
    ros::init(argc, argv, "simple_pub");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<hexbot::vel_msg>("vel_msgs", 1);
    ros::Rate loop_rate(10);

    // the message to be published
    hexbot::vel_msg msg;

    msg.velocities = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (ros::ok()) {

        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();

    }


    return 0;
}
