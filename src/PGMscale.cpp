#include "PGMscale.h"
#ifndef USING_STDLIB
    #include <stdlib.h>
    #define USING_STDLIB
#endif

using std::endl;
using std::cerr;

PGMscale::PGMscale(PGM pgm) : scaledPGM(pgm){
	scalePGM();
}

void PGMscale::scalePGM(){
	vector<unsigned int> pixelVector = scaledPGM.getPixelData();

	// Denominator of the scaling equations, only needs to be calculated one time
	unsigned int maximumPixel = scaledPGM.getMaxPixel();
	unsigned int minimumPixel = scaledPGM.getMinPixel();
	unsigned int scaleDenominator = maximumPixel - minimumPixel;
	
	// Image is one solid color
	if(maximumPixel == minimumPixel){
		exitWithError("Max pixel is equivalent to minimum pixel. Scaling is impossible");
	}
	
	// Algorithm to scale each pixel
	for(unsigned int currentPixel = 0; currentPixel < pixelVector.size(); currentPixel++){
		double newValue = (double)( 255.0 * ( pixelVector[currentPixel] - minimumPixel ) ) / (double)scaleDenominator;
		unsigned int roundedValue = round(newValue);
		pixelVector[currentPixel] = roundedValue;
	}

	//Construct the new PGM
	unsigned int newMaxPixel = 255;
	PGM rescaledPGM(scaledPGM.getWidth(), scaledPGM.getHeight(), newMaxPixel, pixelVector);
	scaledPGM = rescaledPGM;
}

PGM PGMscale::getScaledPGM(){
	return scaledPGM;
}

void PGMscale::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
