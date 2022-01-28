#!/usr/bin/python3

import rospy

from hexbot.msg import pos_msg
from std_msgs.msg import Float32
from math import sin


class Proportional:

    def __init__(self, ka, kx, publish_rate):

        print("Initializing Node")

        self.val = 0

        # Initializes the Node.
        rospy.init_node("publisher_node")

        # Initializes a publihser within the node
        self.controlPub = rospy.Publisher("/set_pos_msg", pos_msg, queue_size=10)

        period = rospy.Duration(publish_rate)
        self.timer = rospy.Timer(period, self.timer_callback)


    def timer_callback(self, event):

        new_msg = pos_msg()

        new_msg.pos = [sin(self.val)] * 18
        
        print("Sent msg:\n", new_msg)

        self.controlPub.publish(new_msg)

        self.val += 0.001



if __name__ == '__main__':

    p = Proportional(1, 1, 0.001)
    rospy.spin()
