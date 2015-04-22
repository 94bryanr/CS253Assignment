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
#include "PGMshader.h"

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
	// N = intermediate frames
	unsigned int N = mapping.getIntermediates();


	// Build each j image
	for (unsigned int imageIndex = 0; imageIndex < N; imageIndex++){
		vector<unsigned int> image;
		//Build source image
		vector<KeyPoint> sourceKeyPointMap = mapping.getSourceKeyPoints(imageIndex);
		Morph sourceMorph(sourceKeyPointMap, startPGM);
		//Build destination image
		vector<KeyPoint> destinationKeyPointMap = mapping.getDestinationKeyPoints(imageIndex);
		Morph destinationMorph(destinationKeyPointMap, endPGM);

		//Interpolate
		PGMshader interpolater(sourceMorph.getPGM(), destinationMorph.getPGM(), imageIndex, N);
		PGM currentPGM = interpolater.getInterpolatedPGM();

		//Output image
		stringstream ss;
        ss << (imageIndex + 1);
		PGMAwriter writer(currentPGM, ss.str() + ".pgm");
		writer.write();
	}
}
