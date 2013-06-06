#ifndef HAND_TRACK_TRACKER_H_
#define HAND_TRACK_TRACKER_H_

#include <opencv2/opencv.hpp>

class Tracker 
{
 public:
 	Tracker ();
 	cv::RotatedRect camshift (cv::Mat img, cv::Rect detection);
 	// This version uses the last detection as initializing rectangle.
 	cv::RotatedRect camshift_track (cv::Mat img);
 private:
  cv::RotatedRect last_trackbox_;
 
  int histsize_, vmin_, vmax_, vthresh_;
  float hue_ranges_[2];
  const float* p_hue_ranges_;
};

#endif
