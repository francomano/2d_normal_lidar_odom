

USAGE: open 4 terminals
for each terminal source /opt/ros/noetic/setup.bash  
1st terminal) roscore
2nd terminal) source devel/setup.bash  
  rosrun normal_lidar_odometry lidar_nicp_node ~scan:=/robot_0/base_scan  
3rd terminal) rosbag play src/test_data/scans.bag 
4th terminal) cd src/exercise 
  rviz -d config.rviz 


