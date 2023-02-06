#include <geometry_msgs/TransformStamped.h>
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <ros/subscriber.h>
#include <sensor_msgs/LaserScan.h>
#include <tf2_ros/transform_broadcaster.h>

#include "constants.h"
#include "nicp/normal_estimator.h"
#include "normal_tracker.h"
#include "ros_bridge.h"
#include "tracker.h"

// Scan callback definition
void scan_callback(const sensor_msgs::LaserScan::ConstPtr&);

std::shared_ptr<NormalScanTracker> tracker_ptr = nullptr;

int main(int argc, char** argv) {
  // Initialize ROS system
  ros::init(argc, argv, "lidar_nicp_node");
  // Create a NodeHandle to manage the node.
  // The "~" is used to configure the NodeHandle namespace equal to
  // the node's name.
  ros::NodeHandle nh("~");

  // TODO: Create a new NormalScanTracker
  // tracker_ptr = ...;
  tracker_ptr = std::make_shared<NormalScanTracker>(nh, FRAME_LASER, TOPIC_ODOM,2.0,0.5);
  // TODO: Subscribe to the topic scan and register scan_callback as message
  ros::Subscriber scan_subscriber = nh.subscribe(TOPIC_SCAN, 10, scan_callback);
  // callback

  ROS_INFO("Node started. Waiting for scans.");

  // Spin the node
  ros::spin();
  return 0;
}

// Scan callback implementation
void scan_callback(const sensor_msgs::LaserScan::ConstPtr& msg_) {
  ScanTracker::ContainerType scan;
  scan2eigen(msg_, scan);

  // Augment scan with normals computed by the NormalEstimator
  std::vector<Eigen::Vector4f, Eigen::aligned_allocator<Eigen::Vector4f>>
      scan_normals;
  NormalEstimator ne(scan, 10); //the NormalTracker receives an augmented scan with normals
  ne.get(scan_normals);

  if (!tracker_ptr) {
    ROS_WARN("No instance of tracker exists. Skipping scan.");
    return;
  }
  // Feed scan_normals to NormalScanTracker
  tracker_ptr->process(scan_normals);
  // Publish tracker state
  tracker_ptr->publishState(msg_->header.stamp);
}
