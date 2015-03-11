#ifndef PGMAWRITER
#define PGMAWRITER

#include "PGMAwriter.h"
#include <stdlib.h>

using std::endl;
using std::cerr;
using std::fstream;

PGMAwriter::PGMAwriter(PGM pgm, string fileLocation)
   	: pgm(pgm), fileLocation(fileLocation)  {

}

void PGMAwriter::write(){
	fstream outputStream(fileLocation.c_str(), std::ios::out);
	if(!outputStream){
		exitWithError("Can not open file for writing");
	}

	//Magic Numbers
	outputStream << "P2" << endl;
	
	//Width, height, max
	outputStream << pgm.getWidth() << " " << pgm.getHeight() << " " << pgm.getMaxAllowedValue() << endl;

	//Pixels
	vector<unsigned int> pixelData = pgm.getPixelData();
	for (unsigned int location = 0; location < pgm.getTotalPixels(); location++){
		outputStream << pixelData[location] << " ";
		//Outputs the pixels with line formatting
		if( ( (location+1) % pgm.getWidth() ) == 0 ){
			outputStream << endl;
		}
	}
}

void PGMAwriter::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}

#endif
