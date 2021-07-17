cmake_minimum_required(VERSION 2.8.3)

project(mtrn4230_gazebo)


find_package(catkin REQUIRED
  COMPONENTS
    std_srvs
    gazebo_msgs
    geometry_msgs
    tf2
    roscpp
)

catkin_package(
  # INCLUDE_DIRS
  #   include
  # LIBRARIES
  CATKIN_DEPENDS  
    std_srvs
    gazebo_msgs
    geometry_msgs
    tf2
    roscpp  
 
)

include_directories( 
  ${catkin_INCLUDE_DIRS}
)

if (CATKIN_ENABLE_TESTING)
  find_package(roslaunch REQUIRED)
endif()

install(DIRECTORY launch controller DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

