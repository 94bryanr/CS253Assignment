#include <iostream>
#include "PGM.h"
#include "PGMreader.h"
#include "PGMscale.h"
#include "PGMwriter.h"
#include "PGMframer.h"
#include <stdlib.h>
#include <sstream>

void exitWithError(string errorMessage);

using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istringstream;

int main(int argc, char* argv[]){
	if(argc != 4){
		exitWithError("Incorrect number of arguments");
	}

	//Get arguments
	string fileOne = argv[1];
	string fileTwo = argv[2];
	istringstream ss(argv[3]);
	int intermediateFrames;
	if (!(ss >> intermediateFrames))
		exitWithError("Invalid Input for Intermediate Frames");
	if (intermediateFrames < 0)
		exitWithError("Invalid Number of Intermediate Frames");

	// Parse in PGM files
	PGMreader readerOne(fileOne);
	PGM pgmOne = readerOne.getPGM();
	PGMreader readerTwo(fileTwo);
	PGM pgmTwo = readerTwo.getPGM();

	// Make interpolated list
	PGMframer framer (pgmOne, pgmTwo, intermediateFrames);
	vector<PGM> PGMList = framer.getPGMVector();

	//Output files
	char outputType = readerOne.getType();
	for  (int file = 0; file < PGMList.size(); file++){
		string fileLocation = std::to_string(file) + ".pgm";
		if (outputType == 'a'){
			PGMAwriter writer(PGMList[file], fileLocation);
			writer.write();
		}
		if (outputType == 'b'){
			PGMBwriter writer(PGMList[file], fileLocation);
			writer.write();
		}
	}
}

void exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
