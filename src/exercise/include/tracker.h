#pragma once
#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>

#include <Eigen/Dense>
#include <vector>

class ScanTracker {
 public:
  ScanTracker(ros::NodeHandle& nh_, const std::string frame_id_,
              const std::string topic_odom_);

  using PointType = Eigen::Vector2f;
  using ContainerType =
      std::vector<PointType, Eigen::aligned_allocator<PointType>>;
  /**
   * @brief Process the incoming PointCloud scan_.
   * The tracker attempts to align scan_ over _scan_fixed to compute ego-motion
   *
   * @param scan_
   */
  void process(const ContainerType& scan_);

  void publishState(ros::Time t_);

  inline const Eigen::Isometry2f& X() const { return _X_moving_in_map; }

 protected:
  Eigen::Isometry2f _X_moving_in_map;
  ContainerType _scan_fixed;
  // ROS Related
  std::string _frame_id;
  ros::Publisher _pub_odom;
  tf2_ros::TransformBroadcaster _tf_br;
};