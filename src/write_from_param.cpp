#include "hexbot/pos_msg.h"
#include "ros/ros.h"
#include "std_msgs/Float64.h"

void msg_from_param(hexbot::pos_msg &msg);

int main(int argc, char **argv) {

  ros::init(argc, argv, "write_from_param");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<hexbot::pos_msg>("pos_msgs", 1);
  ros::Rate loop_rate(10);

  // the message to be published
  hexbot::pos_msg msg;

  while (ros::ok()) {

    // update params
    msg_from_param(msg);

    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

void msg_from_param(hexbot::pos_msg &msg) {
  ros::param::get("/hexbot/leg1/hip1", msg.pos[0]);
  ros::param::get("/hexbot/leg1/knee1", msg.pos[1]);
  ros::param::get("/hexbot/leg1/ankle1", msg.pos[2]);

  ros::param::get("/hexbot/leg2/hip2", msg.pos[3]);
  ros::param::get("/hexbot/leg2/knee2", msg.pos[4]);
  ros::param::get("/hexbot/leg2/ankle2", msg.pos[5]);

  ros::param::get("/hexbot/leg3/hip3", msg.pos[6]);
  ros::param::get("/hexbot/leg3/knee3", msg.pos[7]);
  ros::param::get("/hexbot/leg3/ankle3", msg.pos[8]);

  ros::param::get("/hexbot/leg4/hip4", msg.pos[9]);
  ros::param::get("/hexbot/leg4/knee4", msg.pos[10]);
  ros::param::get("/hexbot/leg4/ankle4", msg.pos[11]);

  ros::param::get("/hexbot/leg5/hip5", msg.pos[12]);
  ros::param::get("/hexbot/leg5/knee5", msg.pos[13]);
  ros::param::get("/hexbot/leg5/ankle5", msg.pos[14]);

  ros::param::get("/hexbot/leg6/hip6", msg.pos[15]);
  ros::param::get("/hexbot/leg6/knee6", msg.pos[16]);
  ros::param::get("/hexbot/leg6/ankle6", msg.pos[17]);
}
