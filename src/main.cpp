#include <iostream>
#include "PGM.h"
#include "PGMreader.h"
#include "PGMwriter.h"
#include <stdlib.h>
#include <sstream>
#include "KeyPoint.h"
#include "Mapping.h"
#include "ExitWithError.h"
#include "Morph.h"

void exitWithError(string errorMessage);

using std::endl;
using std::vector;
using std::istringstream;

int main(int argc, char* argv[]){
	if(argc != 4){
		ExitWithError("Incorrect number of arguments");
	}

	// Get arguments
	string startImageLocation = argv[1];
	string endImageLocation = argv[2];
	string keypointLocation = argv[3];

	// Parse in start PGM
	PGMreader startReader(startImageLocation);
	PGM startPGM = startReader.getPGM();

	// Parse in end PGM
	PGMreader endReader(endImageLocation);
	PGM endPGM = endReader.getPGM();

	// Get Mapping
	Mapping mapping(keypointLocation);
	vector<ExtendedKeyPoint> keyVector = mapping.getExtendedKeyPoints();

	// Morph image
	//For each image
	// N = intermediate frames
	int N = keyVector.at(0).size();
	std::cout << "N: " << N << endl;
	for (int imageIndex = 0; imageIndex < N; imageIndex++){
		//Morph using keypoints from each EKP.at(imageindex)
		vector<KeyPoint> map;
		//Fill out map
		for(int keyPointIndex = 0; keyPointIndex < int(keyVector.size()); keyPointIndex++){
			map.push_back(keyVector.at(keyPointIndex).getKeyPoint(imageIndex));
		}
		PGM currentImage = startPGM;
		Morph morph (map, currentImage); 
		PGM morphedPGM = morph.getPGM();
		
		//Interpolate
		
		
		// Output image
		PGMAwriter writer(morphedPGM, std::to_string(imageIndex+1) + ".pgm");
		writer.write();
	}
}
