#include "normal_tracker.h"

#include <visualization_msgs/MarkerArray.h>

#include <iostream>
#include <cmath>
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
      _X_moving_in_keyframe(Eigen::Isometry2f::Identity()), 
      _keyframe_max_dist(keyframe_max_dist_),
      _keyframe_max_rot(keyframe_max_rot_),
      _frame_id(frame_id_){
  _pub_viz = nh_.advertise<visualization_msgs::MarkerArray>("/info", 10);
  _pub_odom = nh_.advertise<nav_msgs::Odometry>(topic_odom_, 10);
}

// TODO (Look at README.md and tracker.cpp)
void NormalScanTracker::process(const ContainerType& scan_) { 
  if (_scan_key.size() == 0) {
    _scan_key = scan_;
    return;
  }

  NICP solver(_scan_key, scan_, 4);
  solver.run(100);

  Eigen::Isometry2f iso=solver.X();
  Eigen::Isometry2f X=NormalFrameToKFOdometry(iso);

  _X_keyframe_in_map = X;

  _scan_key = scan_;
 }

// TODO Might need to add some functions (Look at README.md and tracker.cpp)
Eigen::Isometry2f NormalScanTracker::NormalFrameToKFOdometry(Eigen::Isometry2f iso) {
    _X_moving_in_keyframe = iso;

    float delta_t = _X_moving_in_keyframe.translation().norm();
    Eigen::Transform<float, 2, 1>::LinearPart linear=_X_moving_in_keyframe.linear();
    Eigen::Matrix2f R=linear.matrix();
    float c = R(0, 0);
    float s = R(0, 1);
    float delta_r = atan2(s, c);
    

    if (delta_t > _keyframe_max_dist || delta_r > _keyframe_max_rot)
        _X_keyframe_in_map = _X_keyframe_in_map * _X_moving_in_keyframe;
        _X_moving_in_keyframe.setIdentity();

    return _X_keyframe_in_map * _X_moving_in_keyframe;
}

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
void NormalScanTracker::publishState(ros::Time t_) {   //this function was added but it needs mod
  geometry_msgs::TransformStamped tf_msg;
  nav_msgs::Odometry odom_msg;

  isometry2transformStamped(_X_keyframe_in_map, tf_msg, FRAME_WORLD, _frame_id,
                            t_);
  transformStamped2odometry(tf_msg, odom_msg);

  publishKeyframe(_X_keyframe_in_map);
  _pub_odom.publish(odom_msg);
  _tf_br.sendTransform(tf_msg);
}