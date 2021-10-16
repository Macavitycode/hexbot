#include "ros/ros.h"
#include "hexbot/vel_msg.h"
#include "std_msgs/Float64.h"

void msg_from_param(hexbot::vel_msg& msg);

int main(int argc, char **argv) {

    ros::init(argc, argv, "write_from_param");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<hexbot::vel_msg>("vel_msgs", 1);
    ros::Rate loop_rate(10);

    // the message to be published
    hexbot::vel_msg msg;

    while (ros::ok()) {

        // update params
        msg_from_param(msg);

        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}


void msg_from_param(hexbot::vel_msg &msg) {
    ros::param::get("/hexbot/leg1/hip1",   msg.velocities[0]);
    ros::param::get("/hexbot/leg1/knee1",  msg.velocities[1]);
    ros::param::get("/hexbot/leg1/ankle1", msg.velocities[2]);

    ros::param::get("/hexbot/leg2/hip2",   msg.velocities[3]);
    ros::param::get("/hexbot/leg2/knee2",  msg.velocities[4]);
    ros::param::get("/hexbot/leg2/ankle2", msg.velocities[5]);

    ros::param::get("/hexbot/leg3/hip3",   msg.velocities[6]);
    ros::param::get("/hexbot/leg3/knee3",  msg.velocities[7]);
    ros::param::get("/hexbot/leg3/ankle3", msg.velocities[8]);

    ros::param::get("/hexbot/leg4/hip4",   msg.velocities[9]);
    ros::param::get("/hexbot/leg4/knee4",  msg.velocities[10]);
    ros::param::get("/hexbot/leg4/ankle4", msg.velocities[11]);

    ros::param::get("/hexbot/leg5/hip5",   msg.velocities[12]);
    ros::param::get("/hexbot/leg5/knee5",  msg.velocities[13]);
    ros::param::get("/hexbot/leg5/ankle5", msg.velocities[14]);

    ros::param::get("/hexbot/leg6/hip6",   msg.velocities[15]);
    ros::param::get("/hexbot/leg6/knee6",  msg.velocities[16]);
    ros::param::get("/hexbot/leg6/ankle6", msg.velocities[17]);
}
