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
 	bool initialized();
 private:
	cv::Mat hist_;
  cv::RotatedRect last_trackbox_;
  cv::Rect last_detection_;
  bool tracker_initalized;
 
  int hue_size_, sat_size_, val_min_, val_max_;
  float hue_range_[2];
  float sat_range_[2];
  const float* pranges_[2];
};

#endif
