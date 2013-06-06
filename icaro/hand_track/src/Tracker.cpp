#include "Tracker.h"

using namespace cv;
using namespace std;
////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
////////////////////////////////////////////////////////////////////////////////
Tracker::Tracker () {
	histsize_ = 32;
	vmin_ = 20;
	vmax_ = 230;
	vthresh_ = 40;
	hue_ranges_[0] = 0;
	hue_ranges_[1] = 180;
	p_hue_ranges_ = hue_ranges_;
}

RotatedRect Tracker::camshift (Mat img, Rect detection) {
	Mat hsv, hist, backproj, mask, hue;
	cvtColor(img, hsv, CV_BGR2HSV);
  inRange(hsv, Scalar(0, vthresh_, MIN(vmin_,vmax_)),
          Scalar(180, 256, MAX(vmin_, vmax_)), mask);
  int ch[] = {0, 0};
  hue.create(hsv.size(), hsv.depth());
  mixChannels(&hsv, 1, &hue, 1, ch, 1);
  
  Mat roi(hue, detection), maskroi(mask, detection);
  calcHist(&roi, 1, 0, maskroi, hist, 1, &histsize_, &p_hue_ranges_);
  normalize(hist, hist, 0, 255, CV_MINMAX);
  
	calcBackProject(&hue, 1, 0, hist, backproj, &p_hue_ranges_);
	backproj &= mask;
	last_trackbox_ = CamShift(backproj, detection,
                            TermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ));
  return last_trackbox_;
}

RotatedRect Tracker::camshift_track (Mat img) {
	Rect detection = last_trackbox_.boundingRect ();
	last_trackbox_ = camshift (img, detection);
  return last_trackbox_;
}
////////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
////////////////////////////////////////////////////////////////////////////////

