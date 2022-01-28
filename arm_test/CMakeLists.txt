cmake_minimum_required(VERSION 2.8.3)

project(arm_sim)

find_package(catkin REQUIRED COMPONENTS 
    rospy 
    urdf 
    gazebo_ros 
    gazebo_msgs 
    std_msgs
    sensor_msgs
)

catkin_package()
