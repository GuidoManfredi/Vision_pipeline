#include "TrainHist.h"

using namespace std;
using namespace cv;
using namespace boost::filesystem;

////////////////////////////////////////////////////////////////////////////////
//	PUBLIC METHODS
////////////////////////////////////////////////////////////////////////////////
TrainHist::TrainHist () {
	_training_results = "training_results.xml";
}

bool train (std::string dir,
						std::vector<std::string> separators,
						std::vector<std::string> names,
						int[2] interval) {
	if (_name.empty()) _name = path2name (dir);
	return train_directory (dir, separators, names, interval);
}

bool TrainHist::train (string dir) {
	if (_name.empty()) _name = path2name (dir);
	train_directory (dir);
	return true;
}

bool TrainHist::save_training (string path, bool override) {
	FileStorage fw;
	int mode;
	override? (mode=FileStorage::WRITE) : (mode=FileStorage::APPEND);

	if (!fw.open(path, mode)){
		cout << "save_training : couldn't open " << path << endl;
		return false;
	}
	fw << _name << _descriptor;
	fw.release();
	return true;
}

bool TrainHist::load_training (string path) {
	string name = path2name(path);
	string result_path = path2rest(path) + _training_results;
	FileStorage fs;
	if (!fs.open(result_path, FileStorage::READ)){
		cout << "load_training : couldn't open " << path << endl;
		return false;
	}
	Mat desc;
	fs[name] >> desc;
	fs.release();
	_descriptor = merge (_descriptor, desc);
	cout << "Loaded training results for " << path << endl;
	return true;
}

void TrainHist::clear_training () {
	_descriptor = Mat();
	_name = "";
}
////////////////////////////////////////////////////////////////////////////////
//	PRIVATE METHODS
////////////////////////////////////////////////////////////////////////////////
bool TrainHist::train_directory (std::string dir,
										 							std::vector<std::string> separators,
 																	std::vector<std::string> names,
										 							int* interval) {
	// Check if dir is a directory
	if (!is_directory (dir)) {
		cout << dir << " not a directory." << endl;
		return false;
	}
	// if this directory has already been trained, load the results
	if (already_trained(dir)) {
		load_training (dir);
	} else {
		// train it
		// sort, directory iteration is not ordered
    Vec_path v; // so we can sort them later
    copy(directory_iterator(dir), directory_iterator(), back_inserter(v));
    sort(v.begin(), v.end());
		// compute number of files
		/*
    int n = v.size ();
    int iStart = n*fStart;
    int iEnd = n*fEnd;
    */
    for (int i = interval[0]; i < interval[1]; ++i)
    {
			if (is_directory(v[i].string()))
				train_directory (v[i].string());
			else if (is_image (v[i].string()))
				train_file (v[i].string());
		}
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

bool TrainHist::already_trained (string path) {
	bool res = false;
	string name = path2name(path);
	string result_path = path2rest(path) + _training_results;
	FileStorage fs;
	// if no training file, not trained
	if (!fs.open(result_path, FileStorage::READ))
		return res;
	// if name doesn't match anything, not trained
	if (fs[name].type() == FileNode::NONE)
		res = false;
	else {
		cout << name << " already trained." << endl;
		res = true;
	}
	fs.release();
	return res;
}

string TrainHist::path2name (string path) {
	vector<string> splitted;
	boost::split (splitted, path, boost::algorithm::is_any_of("/"));
	string filename = splitted[splitted.size()-1];
	boost::split (splitted, filename, boost::algorithm::is_any_of("."));
	return splitted[0];
}

string TrainHist::path2rest (string path) {
	vector<string> splitted;
	boost::split (splitted, path, boost::algorithm::is_any_of("/"));
	string rest;
	for (size_t i=0; i<splitted.size()-1; ++i) // all but last part
		rest += splitted[i] + "/";
	return rest;
}
////////////////////////////////////////////////////////////////////////////////
//  Modify these functions depending on the type of descriptor. The rest should
//	generic as long as the descriptor can be written in a cv::Mat class.
////////////////////////////////////////////////////////////////////////////////
Mat TrainHist::extract (string file, string maskfile) {
	Mat mask = imread(maskfile);
  Mat img = imread(file);
  Mat desc = hist.classic_histogram (img, mask, 3);
  cout << desc.cols << " " << desc.rows << endl;
  return desc;
}

Mat TrainHist::merge (Mat descriptor1, Mat descriptor2) {
	Mat desc = descriptors1 + descriptor2;
	normalize (desc, desc, 0, 1, NORM_MINMAX, -1, Mat() );
	return desc;
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


/*
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
*/
