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

using std::cout;
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
	for (unsigned long i = 0; i < keyVector.size(); i++){
		cout << "OX: " << keyVector[i].getOriginalX() << endl;
		cout << "OY: " << keyVector[i].getOriginalY() << endl;
		cout << "DX: " << keyVector[i].getDestinationX() << endl;
		cout << "DY: " << keyVector[i].getDestinationY() << endl;
		cout << endl;
	}

	// Morph image
	Morph morph (mapping.getKeyPoints(), pgm);
	pgm = morph.getPGM();
	cout << "Morphed " << pgm.at(0,0) << endl;
	
	//Output files
	if (outputLocation.substr(outputLocation.length()-5).compare(".pgma" ) == 0){
		cout << "Writing an ASCII file" << endl;
		PGMAwriter writer(pgm, outputLocation);
		writer.write();
	}
	else if (outputLocation.substr(outputLocation.length()-4).compare(".pgm") == 0){
		cout << "Writing a Binary file" << endl;
		PGMBwriter writer(pgm, outputLocation);
		writer.write();
	}
	else{
		ExitWithError("Bad output filename. Need filetype");
	}

}
