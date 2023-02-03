#include <geometry_msgs/TransformStamped.h>
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <ros/subscriber.h>
#include <sensor_msgs/LaserScan.h>
#include <tf2_ros/transform_broadcaster.h>

#include "constants.h"
#include "normal_tracker.h"
#include "ros_bridge.h"
#include "tracker.h"

// Scan callback definition
void scan_callback(const sensor_msgs::LaserScan::ConstPtr&);

std::shared_ptr<ScanTracker> tracker_ptr = nullptr;

int main(int argc, char** argv) {
  // Initialize ROS system
  ros::init(argc, argv, "lidar_icp_node");
  // Create a NodeHandle to manage the node.
  // The "~" is used to configure the NodeHandle namespace equal to
  // the node's name.
  ros::NodeHandle nh("~");

  tracker_ptr = std::make_shared<ScanTracker>(nh, FRAME_LASER, TOPIC_ODOM);

  // Subscribe to the topic "~/scan" (globally resolved as
  // "scan_matcher_node/scan").
  // The topic should contain sensor_msgs::LaserScan messages.
  // We configure scan_callback to handle the received messages
  ros::Subscriber scan_subscriber = nh.subscribe(TOPIC_SCAN, 10, scan_callback);

  ROS_INFO("Node started. Waiting for scans.");
  ros::spin();

  return 0;
}

// Scan callback implementation
void scan_callback(const sensor_msgs::LaserScan::ConstPtr& msg_) {
  ScanTracker::ContainerType scan;
  scan2eigen(msg_, scan);

  // Feed scan to ScanTracker
  tracker_ptr->process(scan);
  // Publish tracker state
  tracker_ptr->publishState(msg_->header.stamp);
}