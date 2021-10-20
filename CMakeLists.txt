cmake_minimum_required(VERSION 2.8.3)
project(hexbot)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
    roscpp
    rosparam
    gazebo_ros REQUIRED
    std_msgs
    geometry_msgs
    gazebo_msgs
    sensor_msgs
    gazebo_dev
    std_srvs
    urdf
    message_generation
    message_runtime

    controller_manager
    joint_state_controller
    robot_state_publisher
    )

include (FindPkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(XML libxml-2.0)
else()
  message(FATAL_ERROR "pkg-config is required; please install it")
endif()

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_message_files(
    FILES
    vel_msg.msg
)

generate_messages(
    DEPENDENCIES
)

link_directories(
    ${catkin_LIBRARY_DIRS}
    ${GAZEBO_LIBRARY_DIRS}
)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES

    CATKIN_DEPENDS
    message_generation
    message_runtime
    gazebo_msgs
    roscpp
    rosparam
    std_srvs
    geometry_msgs
    sensor_msgs
    urdf
    dynamic_reconfigure
    std_msgs

    controller_manager
    joint_state_controller
    robot_state_publisher
)

# add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
add_executable(hexbot_pub src/publisher.cpp)
add_executable(hexbot_sub src/subscriber.cpp)
add_executable(hexbot_param src/write_from_param.cpp)
target_link_libraries(hexbot_pub ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
target_link_libraries(hexbot_sub ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
target_link_libraries(hexbot_param ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

# For Gazebo Plugin
# add_library(set_speed_joint_plugin src/set_speed_joint_plugin.cpp)
# target_link_libraries(set_speed_joint_plugin ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

