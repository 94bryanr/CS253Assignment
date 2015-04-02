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
	string inputImage = argv[1];
	string inputKeyPoints = argv[2];
	string outputLocation = argv[3];

	// Parse in PGM files
	PGMreader reader(inputImage);
	PGM pgm = reader.getPGM();

	// Get Mapping
	Mapping mapping(inputKeyPoints);
	vector<KeyPoint> keyVector = mapping.getKeyPoints();

	// Morph image
	Morph morph (mapping.getKeyPoints(), pgm);
	pgm = morph.getPGM();
	
	//Output files
	if (outputLocation.substr(outputLocation.length()-5).compare(".pgma" ) == 0){
		PGMAwriter writer(pgm, outputLocation);
		writer.write();
	}
	else if (outputLocation.substr(outputLocation.length()-4).compare(".pgm") == 0){
		PGMBwriter writer(pgm, outputLocation);
		writer.write();
	}
	else{
		ExitWithError("Bad output filename. Need filetype");
	}

}
