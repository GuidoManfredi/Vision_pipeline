#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Histogram.h"

class TrainHist
{
 public:
 	TrainHist ();
 	/**
 	 * Input : a directory containing a directory for each instance of the class.
 	 		OR an instance directory containing various training files.
 	 * Output : a boolean telling if everything went right.
 	**/ 	
 	bool train (std::string class_dir);
 	/**
 	 * Input : a path to a xml file containing objects names and descriptors.
 	 *	       The new object name and descriptor will be added to the list.
 	 * Output : a boolean telling if everything went right.
 	 **/
 	bool save_training (std::string path);
 	/**
 	 * Input : a path to a xml file containing ONE object name and descriptors.
 	 *	       They will be added to the current list.
 	 * Output : a boolean telling if everything went right.
 	 **/
 	bool load_training (std::string path);
 	/**
 	 * Erase the name and all descriptors of the current object;
 	 **/
 	void clear_training ();
 private:
 	/**
 	 * Check if dir is a directory. If no name has been asined to the object, use
 	 * the dir name as name. Check if the directory has already been trained. If not
 	 * train it, mark it as trained and save the results in the directory.
 	 **/
 	bool train_directory (std::string dir);
 	bool train_file (std::string file);
 	/**
 	 * Input : a filename containing the required type of data, depending on
 	 *				 which type of information to extract.
 	 * Output : depends on information to extract. Some data to be processed by
 	 *					the recognition nodes so they can send back a descriptor.
 	 **/
	cv::Mat extract (std::string file, std::string mask);
	cv::Mat merge (std::vector<cv::Mat> descriptors);
	std::string path2name (std::string path);
	bool already_trained (std::string path);
	void mark_as_trained (std::string path);
	std::string get_mask (std::string file);
	bool is_image (std::string file);
	
	Histogram hist;
	std::vector<cv::Mat> _vec_descriptors;
	std::string _name;
	// Name of the file containing the names of already trained files and folders
	std::string _trained_files;
	std::string _training_results;
};
