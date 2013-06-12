#include "Tracker.h"

using namespace cv;
using namespace std;
////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
////////////////////////////////////////////////////////////////////////////////
Tracker::Tracker () {
	hue_size_ = 36;
	sat_size_ = 50;
	val_min_ = 30;
	val_max_ = 226;

  hue_range_[0] = 0;
  hue_range_[1] = 180;
  sat_range_[0] = 0;
  sat_range_[1] = 255;
  pranges_[0] = hue_range_;
  pranges_[1] = sat_range_;
	
	tracker_initalized = false;
}

RotatedRect Tracker::camshift (Mat img, Rect detection) {
	Mat hsv, backproj, mask;
	const int hist_size[] = {hue_size_, sat_size_};
	int ch[2] = {0, 1};
	
	cvtColor(img, hsv, CV_BGR2HSV);
  inRange(hsv, Scalar(0, 0, MIN(val_min_,val_max_)),
          Scalar(180, 256, MAX(val_min_, val_max_)), mask);
          
  Mat roi(hsv, detection), maskroi(mask, detection);
  calcHist(&roi, 1, ch, maskroi, hist_, 1, hist_size, pranges_);
  normalize(hist_, hist_, 0, 255, CV_MINMAX);
  
	calcBackProject(&hsv, 1, ch, hist_, backproj, pranges_);
	backproj &= mask;
	last_trackbox_ = CamShift(backproj, detection,
                            TermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ));

	last_detection_ = last_trackbox_.boundingRect ();
                            
	tracker_initalized = true;
  return last_trackbox_;
}

RotatedRect Tracker::camshift_track (Mat img) {
	Mat hsv, backproj, mask;
	int ch[2] = {0, 1};
	
	cvtColor(img, hsv, CV_BGR2HSV);
  inRange(hsv, Scalar(0, 0, MIN(val_min_,val_max_)),
          Scalar(180, 256, MAX(val_min_, val_max_)), mask);
  
	calcBackProject(&hsv, 1, ch, hist_, backproj, pranges_);
	backproj &= mask;
	
	Rect detection = last_trackbox_.boundingRect ();
	last_trackbox_ = CamShift(backproj, detection,
                            TermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ));
  return last_trackbox_;
}

bool Tracker::initialized () {
	return tracker_initalized;
}
////////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
////////////////////////////////////////////////////////////////////////////////

/*
RotatedRect Tracker::camshift (Mat img, Rect detection) {
	Mat hsv, backproj, mask, hue;
	cvtColor(img, hsv, CV_BGR2HSV);
  inRange(hsv, Scalar(0, vthresh_, MIN(vmin_,vmax_)),
          Scalar(180, 256, MAX(vmin_, vmax_)), mask);
  int ch[] = {0, 0};
  hue.create(hsv.size(), hsv.depth());
  mixChannels(&hsv, 1, &hue, 1, ch, 1);

  Mat roi(hue, detection), maskroi(mask, detection);
  calcHist(&roi, 1, 0, maskroi, hist_, 1, &histsize_, &p_hue_ranges_);
  normalize(hist_, hist_, 0, 255, CV_MINMAX);
  
	calcBackProject(&hue, 1, 0, hist_, backproj, &p_hue_ranges_);
	backproj &= mask;
	last_trackbox_ = CamShift(backproj, detection,
                            TermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ));

	last_detection_ = last_trackbox_.boundingRect ();
                            
	tracker_initalized = true;
  return last_trackbox_;
}
*/

