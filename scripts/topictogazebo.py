#!/bin/env python3

#  A simple subscriber to write position values of the joints in Gazebo

import rospy
from gazebo_msgs.srv import SetModelConfigurationRequest, SetModelConfiguration
from sensor_msgs.msg import JointState
from hexbot.msg import pos_msg

class Controller:
    
    def __init__(self):

        rospy.wait_for_service("/gazebo/set_model_configuration")

        self.hexbot_client = rospy.ServiceProxy("/gazebo/set_model_configuration", SetModelConfiguration)
        self.server = rospy.Subscriber("/set_pos_msg", pos_msg, self.bot_callback)

        self.hexbot_name = "hexbot"

        self.request = SetModelConfigurationRequest()
        self.request.model_name = "hexbot"
        self.request.urdf_param_name = "robot_description"
        self.request.joint_names = [
                "thigh_1_joint", "shin_1_joint", "foot_1_joint",
                "thigh_2_joint", "shin_2_joint", "foot_2_joint",
                "thigh_3_joint", "shin_3_joint", "foot_3_joint",
                "thigh_4_joint", "shin_4_joint", "foot_4_joint",
                "thigh_5_joint", "shin_5_joint", "foot_5_joint",
                "thigh_6_joint", "shin_6_joint", "foot_6_joint",
                ]

    def bot_callback(self, msg):

        print(msg)

        self.request.joint_positions = msg.pos
        response = self.hexbot_client(self.request)

        print(response)


if __name__ == "__main__":

    print("started controller")

    rospy.init_node("bot_controller")
    c = Controller()

    rospy.spin()
