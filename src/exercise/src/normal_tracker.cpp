#include "normal_tracker.h"

#include <visualization_msgs/MarkerArray.h>

#include <iostream>

#include "constants.h"
#include "nicp/eigen_nicp_2d.h"
#include "ros_bridge.h"

// TODO (Look at README.md and tracker.cpp)
NormalScanTracker::NormalScanTracker(ros::NodeHandle& nh_,
                                     const std::string frame_id_,
                                     const std::string topic_odom_,
                                     float keyframe_max_dist_,
                                     float keyframe_max_rot_)
    : _X_keyframe_in_map(Eigen::Isometry2f::Identity()),
      _X_moving_in_keyframe(Eigen::Isometry2f::Identity()) {
  _pub_viz = nh_.advertise<visualization_msgs::MarkerArray>("/info", 10);
}

// TODO (Look at README.md and tracker.cpp)
void NormalScanTracker::process(const ContainerType& scan_) { return; }

// TODO Might need to add some functions (Look at README.md and tracker.cpp)

void NormalScanTracker::publishKeyframe(const Eigen::Isometry2f keyframe_) {
  _keyframe_pos_vect.push_back(keyframe_.translation());
  // Send two markers, one for keyframe vertices and one for keyframe
  // connections
  visualization_msgs::Marker keyframe_nodes, keyframe_lines;
  keyframe_nodes.header.frame_id = FRAME_WORLD;
  keyframe_nodes.header.stamp = ros::Time(0);
  keyframe_nodes.ns = "keyframe_nodes";
  keyframe_nodes.id = 0;
  keyframe_nodes.type = visualization_msgs::Marker::CUBE_LIST;
  keyframe_nodes.action = visualization_msgs::Marker::ADD;
  keyframe_nodes.pose.position.x = 0;
  keyframe_nodes.pose.position.y = 0;
  keyframe_nodes.pose.position.z = 0;
  keyframe_nodes.pose.orientation.x = 0;
  keyframe_nodes.pose.orientation.y = 0;
  keyframe_nodes.pose.orientation.z = 0;
  keyframe_nodes.pose.orientation.w = 1.0;
  keyframe_nodes.scale.x = 0.4;
  keyframe_nodes.scale.y = 0.4;
  keyframe_nodes.scale.z = 0.4;
  keyframe_nodes.color.a = 1.0;
  keyframe_nodes.color.r = 1.0;
  keyframe_nodes.color.g = 0.0;
  keyframe_nodes.color.b = 0.0;

  keyframe_lines.header.frame_id = FRAME_WORLD;
  keyframe_lines.header.stamp = ros::Time(0);
  keyframe_lines.ns = "keyframe_lines";
  keyframe_lines.id = 1;
  keyframe_lines.type = visualization_msgs::Marker::LINE_STRIP;
  keyframe_lines.action = visualization_msgs::Marker::ADD;
  keyframe_lines.pose.position.x = 0;
  keyframe_lines.pose.position.y = 0;
  keyframe_lines.pose.position.z = 0;
  keyframe_lines.pose.orientation.x = 0;
  keyframe_lines.pose.orientation.y = 0;
  keyframe_lines.pose.orientation.z = 0;
  keyframe_lines.pose.orientation.w = 1.0;
  keyframe_lines.scale.x = 0.2;
  keyframe_lines.scale.y = 0.0;
  keyframe_lines.scale.z = 0.0;
  keyframe_lines.color.a = 1.0;
  keyframe_lines.color.r = 0.0;
  keyframe_lines.color.g = 1.0;
  keyframe_lines.color.b = 0.0;

  for (const auto kf_p : _keyframe_pos_vect) {
    geometry_msgs::Point kf_point;
    kf_point.x = kf_p.x();
    kf_point.y = kf_p.y();
    kf_point.z = 0;
    keyframe_nodes.points.push_back(kf_point);
    keyframe_lines.points.push_back(kf_point);
  }

  visualization_msgs::MarkerArray msg;
  msg.markers.push_back(keyframe_nodes);
  msg.markers.push_back(keyframe_lines);
  _pub_viz.publish(msg);
}