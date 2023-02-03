#include "normal_estimator.h"

#include "icp/eigen_covariance.h"

NormalEstimator::NormalEstimator(LaserScanType& src_, int max_points_in_leaf)
    : _kd_tree(src_.begin(), src_.end(), max_points_in_leaf) {
  _scan_with_normals.clear();
  // For every point in src_, query the kd-tree for closest point
  for (const auto p_src : src_) {
    // find neighbors
    std::vector<Vector2f*> neighbors_ptr;
    _kd_tree.fastSearch(neighbors_ptr, p_src, 0.3);
    if (neighbors_ptr.size() < 3) continue;
    Eigen::Vector2f mean;
    Eigen::Matrix2f cov;
    std::vector<Vector2f> neighbors;
    for (const auto it : neighbors_ptr) neighbors.push_back(*it);

    computeMeanAndCovariance(mean, cov, neighbors.begin(), neighbors.end());
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix2f> es;
    es.compute(cov);
    Eigen::Vector2f p_normal = es.eigenvectors().col(0);
    if (-p_src.dot(p_normal) < 0) p_normal = -p_normal;
    Vector4f dest_p;
    dest_p << p_src, p_normal;
    _scan_with_normals.push_back(dest_p);
  }
}