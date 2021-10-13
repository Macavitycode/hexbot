cmake_minimum_required(VERSION 2.8.3)

project(hexbot)

find_package(catkin REQUIRED
    roscpp
    gazebo_ros REQUIRED
    std_msgs
    geometry_msgs
    gazebo_msgs
    )

catkin_package(CATKIN_DEPENDS roscpp)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
)

link_directories(${GAZEBO_LIBRARY_DIRS})

list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

# foreach(dir config launch meshes urdf)
#     install(DIRECTORY ${dir}/
#         DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
# endforeach(dir)

add_executable(hexbot_node src/main.cpp src/controller.cpp)
target_link_libraries(hexbot_node ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
