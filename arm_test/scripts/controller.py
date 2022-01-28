#!/usr/bin/python3

import rospy

from sensor_msgs.msg import JointState

from std_msgs.msg import Header

class Proportional:

    def __init__(self, ka, kx, publish_rate):

        print("Initializing Node")

        # Initializes the Node.
        rospy.init_node("publisher_node")

        # Initializes a publihser within the node
        self.controlPub = rospy.Publisher("/set_joint_state", JointState, queue_size=10)

        self.ka = ka
        self.kx = kx

        period = rospy.Duration(publish_rate)

        self.timer = rospy.Timer(period, self.control)


    def control(self, event):

        new_msg = JointState()

        new_msg.header = Header()
        new_msg.header.seq += 1
        new_msg.header.stamp = rospy.Time.now()

        #  new_msg.name = ["rotation1", "rotation2"]
        #  new_msg.position = [1, 0]
        new_msg.velocity = [10, 20]
        #  new_msg.effort = [2, 2]
        
        print("Sent msg:\n", new_msg)

        self.controlPub.publish(new_msg)



if __name__ == '__main__':

    p = Proportional(1, 1, 1)
    rospy.spin()
