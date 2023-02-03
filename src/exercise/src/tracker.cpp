#include "tracker.h"

#include "constants.h"
#include "icp/eigen_icp_2d.h"
#include "ros_bridge.h"

ScanTracker::ScanTracker(ros::NodeHandle& nh_, const std::string frame_id_,
                         const std::string topic_odom_)
    : _X_moving_in_map(Eigen::Isometry2f::Identity()), _frame_id(frame_id_) {
  _pub_odom = nh_.advertise<nav_msgs::Odometry>(topic_odom_, 10);
}

void ScanTracker::process(const ContainerType& scan_) {
  if (_scan_fixed.size() == 0) {
    _scan_fixed = scan_;
    return;
  }

  ICP solver(_scan_fixed, scan_, 4);
  solver.run(100);

  _X_moving_in_map = _X_moving_in_map * solver.X();

  _scan_fixed = scan_;
}

void ScanTracker::publishState(ros::Time t_) {
  geometry_msgs::TransformStamped tf_msg;
  nav_msgs::Odometry odom_msg;

  isometry2transformStamped(_X_moving_in_map, tf_msg, FRAME_WORLD, _frame_id,
                            t_);
  transformStamped2odometry(tf_msg, odom_msg);

  _pub_odom.publish(odom_msg);
  _tf_br.sendTransform(tf_msg);
}