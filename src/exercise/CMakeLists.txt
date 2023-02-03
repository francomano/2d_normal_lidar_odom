cmake_minimum_required(VERSION 3.16)
project(normal_lidar_odometry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

find_package(Eigen3 REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    sensor_msgs
    nav_msgs
    geometry_msgs
    tf2
    tf2_ros
    visualization_msgs
)

catkin_package(
    INCLUDE_DIRS
    "include/"
    CATKIN_DEPENDS
    roscpp
    sensor_msgs
    nav_msgs
    geometry_msgs
    visualization_msgs
    tf2
    tf2_ros
)

add_library(icp SHARED src/icp/eigen_icp_2d.cpp)
target_include_directories(icp PUBLIC include/icp)
target_link_libraries(icp PUBLIC Eigen3::Eigen)

add_library(ros_bridge SHARED src/ros_bridge.cpp)
target_include_directories(ros_bridge PUBLIC ${catkin_INCLUDE_DIRS} include)
target_link_libraries(ros_bridge PUBLIC ${catkin_LIBRARIES} Eigen3::Eigen)

add_library(tracker SHARED src/tracker.cpp)
target_include_directories(tracker PUBLIC ${catkin_INCLUDE_DIRS} include)
target_link_libraries(tracker PUBLIC ${catkin_LIBRARIES} ros_bridge icp)

# Add compilation rules for nicp and normal_tracker libraries
add_library(nicp SHARED src/nicp/eigen_nicp_2d.cpp src/nicp/normal_estimator.cpp)
target_include_directories(nicp PUBLIC include/ include/nicp)
target_link_libraries(nicp PUBLIC Eigen3::Eigen icp)

add_library(normal_tracker SHARED src/normal_tracker.cpp)
target_include_directories(normal_tracker PUBLIC include)
target_link_libraries(normal_tracker PUBLIC nicp ${catkin_LIBRARIES} ros_bridge)

# Executable rules
add_executable(lidar_icp_node bin/lidar_icp_node.cpp)
target_link_libraries(lidar_icp_node PRIVATE tracker ros_bridge)

# Add compilation rules for lidar_nicp_node