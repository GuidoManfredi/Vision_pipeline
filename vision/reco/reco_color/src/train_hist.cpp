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
	/*
	TrainHist trainer;
	if (is_directory (argv[1])) {
		directory_iterator end_itr;
    for (directory_iterator i (argv[1]); i != end_itr; ++i) {
    	trainer.train_file (i->path().string());
    	trainer.save_training ("/home/gmanfred/Desktop/flags/training_results.xml");
    }
	}
	*/
	/*
	TrainHist trainer;
	//trainer.train_instance ("/home/gmanfred/devel/pcl/dataset/rgbd-dataset/apple/apple_1");
	trainer.train (argv[1]);
	trainer.save_training ("/home/gmanfred/Desktop/training_results.xml");
	*/
	TrainHist trainer;
	float * interval = (float*)malloc(2*sizeof(float));
	interval[0] = 0.0;
	interval[1] = 1.0;
	vector<string> names;
	names.push_back("crop.png");
	names.push_back("maskcrop.png");
	vector<string> sep;
	sep.push_back("_");
	sep.push_back("_");
	trainer.train (argv[1], sep, names, interval);
	return 0;
}

// recursive delete of xml 
// find . -type f -name "*.xml" -delete
// && rm trained_files.txt

//TODO Besoin de marquer les fichiers traités dans un files ? Ou juste regarde
//			si presence d'un fichier resultat ? Mettre le file de fichier traité
//			dans la classe/instance ou pres de l'executable
// TODO voir si possible d'ecrire le descripteur comme parametre du nom. Est-ce
//			que possible de voir si nom existe et si oui ecrire par deçu descripteur correspondant.
// TODO Donner possibilité de traiter seulement un pourcentage des fichiers dans un dossier (int start, int end).
