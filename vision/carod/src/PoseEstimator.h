#ifndef CAROD_POSE_ESTIMATOR_H_
#define CAROD_POSE_ESTIMATOR_H_

#include <vector>

#include "opencv2/calib3d/calib3d.hpp"
#include "rpnp.h"
//#include "NonLinearLS.h"
#include "Random.h"

#define PNP_POINTS 4

class PoseEstimator {
 public:
  PoseEstimator (cv::Mat K);
  void compute_pnp_ransac (std::vector<cv::Point3d> p3d, std::vector<cv::KeyPoint> kpts,
                            std::vector<int> p3d_idx,
                            std::vector<int> kpts_idx,
                            double max_reprojection_error, int max_its);
  void compute_pnp_standalone (std::vector<cv::Point3d> p3d, std::vector<cv::KeyPoint> kpts,
                                  std::vector<int> p3d_idx,
                                  std::vector<int> kpts_idx);
  void refine (std::vector<cv::Point3d> p3d, std::vector<cv::KeyPoint> kpts,
               std::vector<int> p3d_idx,
               std::vector<int> kpts_idx);
  std::vector<int> get_inliers(std::vector<cv::Point3d> p3d, std::vector<cv::KeyPoint> kpts,
                                std::vector<int> p3d_idx, std::vector<int> kpts_idx,
                                double R[3][3], double t[3],
                                double max_reprojection_error);
  int get_number_outliers(std::vector<cv::Point3d> p3d, std::vector<cv::KeyPoint> kpts,
                          std::vector<int> p3d_idx, std::vector<int> kpts_idx,
                          double R[3][3], double t[3],
                          double max_reprojection_error);
  cv::Mat get_P ();

 private:
  void add_correspondences (std::vector<cv::Point3d> p3d, std::vector<cv::KeyPoint> kpts,
                             std::vector<int> p3d_idx, std::vector<int> kpts_idx);
  void add_random_correspondences (int number_points,
                                   std::vector<cv::Point3d> p3d, std::vector<cv::KeyPoint> kpts,
                                   std::vector<int> p3d_idx, std::vector<int> kpts_idx);
  double dot(const double * v1, const double * v2) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
  }

  cv::Mat K_;
  rpnp PNP_;

  double R_[3][3];
  double t_[3];

  std::vector<int> inlier_model_indices_, inlier_scene_indices_;
};

#endif
