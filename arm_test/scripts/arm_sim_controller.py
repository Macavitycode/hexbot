#!/usr/bin/python3

import rospy
from gazebo_msgs.srv import SetModelConfigurationRequest, SetModelConfiguration
from sensor_msgs.msg import JointState

class controller:

    def __init__(self):

        rospy.wait_for_service("/gazebo/set_model_configuration")

        self.arm_client = rospy.ServiceProxy("/gazebo/set_model_configuration", SetModelConfiguration)
        self.arm_server = rospy.Subscriber("/set_joint_state", JointState, self.arm_callback)

        self.arm_name = "arm"

        self.request = SetModelConfigurationRequest()

        self.request.model_name = "arm"
        self.request.urdf_param_name = "robot_description"
        self.request.joint_names = ["rotation1", "rotation2"]


    def arm_callback(self, msg):
        
        self.request.joint_positions = msg.position
        reponse = self.arm_client(self.request)
        
        print(reponse)


if __name__ == '__main__':

    rospy.init_node("arm_controller")
    c = controller()
    rospy.spin()
