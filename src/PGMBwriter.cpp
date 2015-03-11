#ifndef PGMBWRITER
#define PGMBWRITER

#include "PGMBwriter.h"

using std::endl;
using std::cerr;
using std::fstream;

PGMBwriter::PGMBwriter(PGM pgm, string fileLocation)
   	: pgm(pgm), fileLocation(fileLocation)  {

}

void PGMBwriter::write(){
	fstream outputStream(fileLocation.c_str(), std::ios::out | std::ios::binary);
	if(!outputStream){
		exitWithError("Can not open file for writing");
	}

	//Magic Numbers
	outputStream << "P5";
	
	//Width, height, max
	for(int i = 3; i >= 0; i--){
		outputStream << ( (char) (pgm.getWidth() >> (i*8)) );
	}
	for(int i = 3; i >= 0; i--){
		outputStream << ( (char) (pgm.getHeight() >> (i*8)) );
	}
	for(int i = 3; i >= 0; i--){
		outputStream << ( (char) (pgm.getMaxAllowedValue() >> (i*8)) );
	}

	//Pixels
	vector<unsigned int> pixelData = pgm.getPixelData();
	for (unsigned int location = 0; location < pgm.getTotalPixels(); location++){
		outputStream << (char)pixelData[location];
	}
	outputStream.flush();
}

void PGMBwriter::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}

#endif
