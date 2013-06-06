#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include "hand_detect/Rectangle.h"
#include "Detector.h"

namespace enc = sensor_msgs::image_encodings;
using namespace std;
using namespace cv;

string cascade_file = "/home/gmanfred/devel/ros/icaro/hand_detect/cascades/poing.xml";
Detector det (cascade_file);
bool detect = false;
Mat current_img;

void images_cb (const sensor_msgs::ImageConstPtr& msg) {
	cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(msg, enc::BGR8);
  }
  catch (cv_bridge::Exception& e) {
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
  }
	current_img = cv_ptr->image;
}

bool detect_hands (hand_detect::Rectangle::Request &req,
									hand_detect::Rectangle::Response &res) {
	vector<Rect> hands = det.detect (current_img);
	for (size_t i=0; i<hands.size (); ++i) {
		res.x[i] = hands[i].x;
		res.y[i] = hands[i].y;
		res.width[i] = hands[i].width;
		res.height[i] = hands[i].height;
	}	
	return true;
}

int main (int argc, char** argv) {

	if (argc != 2) {
		cout << "Usage : hand_detect images_topic" << endl;
		return 1;
	}

  ros::init(argc, argv, "hand_detect");
  ros::NodeHandle n;

	ros::Subscriber sub_images = n.subscribe(argv[1], 10, images_cb);
  ros::ServiceServer srv_hands = n.advertiseService("/detect_hands", detect_hands);
  

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// TESTING CODE
////////////////////////////////////////////////////////////////////////////////
void test ();
void draw (Mat img, vector<Rect> hands);

const static Scalar colors[] =  { CV_RGB(0,0,255),
																	CV_RGB(0,128,255),
																	CV_RGB(0,255,255),
																	CV_RGB(0,255,0),
																	CV_RGB(255,128,0),
																	CV_RGB(255,255,0),
																	CV_RGB(255,0,0),
																	CV_RGB(255,0,255)} ;

void test () {
	Detector det ("/home/gmanfred/devel/ros/icaro/hand_detect/cascades/poing.xml");
	
  VideoCapture cap(0); // open the default camera
  if(!cap.isOpened())  // check if we succeeded
      return;

  Mat edges;
  namedWindow("hand",1);
  for(;;) {
      Mat frame;
      cap >> frame; // get a new frame from camera
      vector<Rect> hands;
	    hands = det.detect (frame);
	    draw (frame, hands);
      imshow("hand", frame);
      if(waitKey(30) >= 0) break;
  }
}

void draw (Mat img, vector<Rect> hands) {
	Scalar color;
	for (size_t i=0; i<hands.size(); ++i) {
    Scalar color = colors[i%8];
    rectangle (img, hands[i], color, 3, 8, 0 );
  }
}
