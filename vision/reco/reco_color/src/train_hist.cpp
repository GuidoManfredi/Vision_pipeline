#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "TrainHist.h"

using namespace cv;
using namespace std;
using namespace boost::filesystem;

int main (int argc, char** argv) {
	if (argc != 2) {
		cout << "Usage train_hist directory" << endl;
		return 1;
	}
	
	TrainHist trainer;
	float * interval = (float*)malloc(2*sizeof(float));
	interval[0] = 0.0;
	interval[1] = 1.0;
	vector<string> names, sep;
	names.push_back("crop.png");
	sep.push_back("_");
	names.push_back("maskcrop.png");
	sep.push_back("_");
	trainer.train (argv[1], sep, names, interval);
	return 0;
}
// recursive delete of xml 
// find . -type f -name "*.xml" -delete
// TODO Donner possibilité de traiter seulement un pourcentage des fichiers dans un dossier (int start, int end).
