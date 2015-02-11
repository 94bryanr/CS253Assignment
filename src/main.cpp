#include<iostream>
#ifndef USING_PGM
	#define USING_PGM
	#include "PGM.h"
#endif
#include "PGMreader.h"
#include "PGMscale.h"
#include "PGMwriter.h"
#ifndef USING_STDLIB
    #include <stdlib.h>
    #define USING_STDLIB
#endif

void exitWithError(string errorMessage);

using std::cout;
using std::endl;
using std::vector;
using std::cerr;

int main(int argc, char* argv[]){
	if(argc != 3){
		exitWithError("Incorrect number of arguments");
	}
	string fileName = argv[1];
	string outputFileLocation = argv[2];

	// Parse in our PGM file
	PGMreader reader(fileName);
	PGM pgm = reader.getPGM();

	// Scale the PGM
	PGMscale scaler(pgm);
	PGM scaledPGM = scaler.getScaledPGM();

	// Write the PGM to a file
	PGMwriter writer(scaledPGM, outputFileLocation);
	writer.write();
}

void exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
