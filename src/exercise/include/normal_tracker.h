#pragma once
#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>

#include <Eigen/Dense>

class NormalScanTracker {
 public:
  NormalScanTracker(ros::NodeHandle& nh_, const std::string frame_id_,
                    const std::string topic_odom_, float keyframe_max_dist_,
                    float keyframe_max_rot_);

  using PointType = Eigen::Vector4f;
  using ContainerType =
      std::vector<PointType, Eigen::aligned_allocator<PointType>>;
  void process(const ContainerType& scan_);

  void publishState(ros::Time t_);

  inline const Eigen::Isometry2f X() const {
    return Eigen::Isometry2f::Identity();
  }

 protected:
  void publishKeyframe(const Eigen::Isometry2f keyframe_);
  Eigen::Isometry2f _X_keyframe_in_map, _X_moving_in_keyframe;

  // TODO: Might need to add some variables
  float _keyframe_max_dist;
  float _keyframe_max_rot;
  ContainerType _scan_key;
  Eigen::Isometry2f NormalFrameToKFOdometry(Eigen::Isometry2f iso);
  //ROS
  std::string _frame_id;
  ros::Publisher _pub_odom;
  tf2_ros::TransformBroadcaster _tf_br;

  // Viz related stuff
  std::vector<Eigen::Vector2f> _keyframe_pos_vect;
  ros::Publisher _pub_viz;
};