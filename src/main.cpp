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
	Mapping mapping(keypointLocation); //TODO: Will no longer work
	vector<KeyPoint> keyVector = mapping.getKeyPoints(); //TODO: Will no longer work

	// Morph image
	//TODO: Pass 1 argument? Do this multiple times?
	//Morph morph (mapping.getKeyPoints(), startPGM); 
	//morphedPGM = morph.getPGM();
	
	// Output image
	//PGMAwriter writer(pgm, outputLocation);
	//writer.write();
}
