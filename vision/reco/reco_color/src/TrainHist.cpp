#include "TrainHist.h"

using namespace std;
using namespace cv;
using namespace boost::filesystem;

////////////////////////////////////////////////////////////////////////////////
//	PUBLIC METHODS
////////////////////////////////////////////////////////////////////////////////
TrainHist::TrainHist () {
	_trained_files = "trained_files.txt";
	_training_results = "training_results.xml";
}

bool TrainHist::train (string dir) {
	if (_name.empty()) _name = path2name (dir);
	train_directory (dir);
	return true;
}

bool TrainHist::save_training (string path) {
	FileStorage fw;
	if (!fw.open(path, FileStorage::APPEND)){
		cout << "save_training : couldn't open " << path << endl;
		return false;
	}
	Mat desc = merge (_vec_descriptors);
	fw << "name" << _name;
	fw << "descriptor" << desc;
	//fw << _name << desc;
	fw.release();
	return true;
}

bool TrainHist::load_training (string path) {
	FileStorage fs;
	if (!fs.open(path, FileStorage::READ)){
		cout << "load_training : couldn't open " << path << endl;
		return false;
	}
	// fs["name"] >> _name;
	Mat desc;
	fs["descriptor"] >> desc;
	_vec_descriptors.push_back(desc);
	fs.release();
	cout << "Loaded training results for " << path << endl;
	return true;
}

void TrainHist::clear_training () {
	_vec_descriptors.clear ();
	_name = "";
}
////////////////////////////////////////////////////////////////////////////////
//	PRIVATE METHODS
////////////////////////////////////////////////////////////////////////////////
bool TrainHist::train_directory (string dir) {
	// Check if dir is a directory
	if (!is_directory (dir)) {
		cout << dir << " not a directory." << endl;
		return false;
	}
	// if this directory has already been trained, load the results
	if (already_trained(dir)) {
		string training_results = dir + _training_results;
		load_training (training_results);
	} else {
		// train it
		directory_iterator end_itr;
		for (directory_iterator i (dir); i != end_itr; ++i) {
			if (is_directory(i->path().string()))
				train_directory (i->path().string());
			else if (is_image (i->path().string()))
				train_file (i->path().string());
		}
		mark_as_trained (dir);
		// save name of the current instance/class
		_name = path2name (dir);
		save_training (dir+_training_results);
	}
	return true;
}

bool TrainHist::train_file (string file) {
	string maskfile = get_mask (file);
	Mat descriptor = extract (file, maskfile);
	_vec_descriptors.push_back (descriptor);
	mark_as_trained (file);
	return true;
}

Mat TrainHist::extract (string file, string maskfile) {
	Mat mask = imread(maskfile);
  Mat img = imread(file);
  Mat desc = hist.classic_histogram (img, mask, 3);
  cout << desc.cols << " " << desc.rows << endl;
  return desc;
}

Mat TrainHist::merge (vector<Mat> descriptors) {
	Mat desc = descriptors[0];
	for (size_t i=1; i<descriptors.size(); ++i)
		desc += descriptors[i];
	normalize (desc, desc, 0, 1, NORM_MINMAX, -1, Mat() );
	return desc;
}

string TrainHist::path2name (string path) {
	vector<string> splitted;
	boost::split (splitted, path, boost::algorithm::is_any_of("/"));
	string filename = splitted[splitted.size()-1];
	boost::split (splitted, filename, boost::algorithm::is_any_of("."));
	//cout << splitted[0] << endl;
	return splitted[0];
}

void TrainHist::mark_as_trained (string path) {
	ofstream myfile (_trained_files.c_str(), std::ifstream::app);
	if (!myfile.is_open ())	{
		cout << "Couldn't open file " << _trained_files.c_str() << ". Aborting." << endl;
		return;
	}
  
  myfile << path2name(path) << endl;
  myfile.close();
  
 	//cout << "Marked " << path << " as trained." << endl;
}

bool TrainHist::already_trained (string path) {
	ifstream myfile (_trained_files.c_str(), std::ifstream::in);
	if (!myfile.is_open ())	{
		cout << "Warning : already_trained: couldn't open file " << _trained_files.c_str() << ". Skipping." << endl;
		return false;
	}

	string line;
	string name = path2name(path);
	while (getline (myfile, line)) {
		if (line == name) {
			myfile.close();
			cout << path << " already trained." << endl;
			return true;
		}
	}
	myfile.close();
	return false;
}

bool TrainHist::is_image (string file) {
	vector<string> splitted;
	boost::split (splitted, file, boost::algorithm::is_any_of("_"));
	if (splitted[splitted.size()-1] == "crop.png")
		return true;
	else
		return false;
}

string TrainHist::get_mask (string file) {
	vector<string> splitted;
	boost::split (splitted, file, boost::algorithm::is_any_of("_"));
	splitted[splitted.size()-1] = "mask" + splitted[splitted.size()-1];
	string mask;
	for (size_t i=0; i < splitted.size(); ++i)
		mask += splitted[i];
	return mask;
}

/*
bool TrainHist::train_class (string class_dir) {
	_name = path2name (class_dir);
	if (is_directory (class_dir)) {
		directory_iterator end_itr;
    for (directory_iterator i (class_dir); i != end_itr; ++i)
    	train_instance (i->path().string());
	}
	else {
		cout << class_dir << " not a directory." << endl;
		return false;
	}
	
	save_training (class_dir+"/training_results.xml", FileStorage::WRITE);
	return true;
}

bool TrainHist::train_instance (string instance_dir) {
	if (_name.empty()) _name = path2name (instance_dir);
	train_directory (instance_dir);
	return true;
}
*/

/*
bool TrainHist::train_list (string list) {
	ifstream file (list.c_str());
	if (!file.is_open ())	{
		cout << "Couldn't open list file " << list.c_str() << ". Aborting." << endl;
		return -1;
	}

	string path;
	while (getline (file, path)) {
		if (is_directory (path))
			train_directory (path);
		else
			train_file (path);
	}
	
	return true;
}
*/
