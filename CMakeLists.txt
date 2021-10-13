cmake_minimum_required(VERSION 2.8.3)

project(hexbot)

find_package(catkin REQUIRED
    roscpp
    gazebo_ros REQUIRED
    std_msgs
    geometry_msgs
    gazebo_msgs
    sensor_msgs
    gazebo_dev
    std_srvs
    urdf
    )

include (FindPkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(XML libxml-2.0)
  pkg_check_modules(OGRE OGRE)
  pkg_check_modules(OGRE-Terrain OGRE-Terrain)
  pkg_check_modules(OGRE-Paging OGRE-Paging)
else()
  message(FATAL_ERROR "pkg-config is required; please install it")
endif()

include_directories(
  include
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  ${OGRE_INCLUDE_DIRS}
  ${OGRE-Terrain_INCLUDE_DIRS}
  ${OGRE-Paging_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

link_directories(
  ${catkin_LIBRARY_DIRS}
  ${OGRE_LIBRARY_DIRS}
  ${OGRE-Terrain_LIBRARY_DIRS}
  ${OGRE-Paging_LIBRARY_DIRS}
  ${GAZEBO_LIBRARY_DIRS}
  )

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES

  CATKIN_DEPENDS
  message_runtime
  gazebo_msgs
  roscpp
  std_srvs
  geometry_msgs
  sensor_msgs
  urdf
  dynamic_reconfigure
  std_msgs
)

# add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

add_executable(hexbot_node src/main.cpp src/controller.cpp)
target_link_libraries(hexbot_node ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
