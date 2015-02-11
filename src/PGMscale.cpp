#include "PGMscale.h"

using std::endl;
using std::cerr;

PGMscale::PGMscale(PGM pgm) : scaledPGM(pgm){
	scalePGM();
}

void PGMscale::scalePGM(){
	vector<int> pixelVector = scaledPGM.getPixelData();

	// Denominator of the scaling equations, only needs to be calculated one time
	int maximumPixel = scaledPGM.getMaxPixel();
	int minimumPixel = scaledPGM.getMinPixel();
	int scaleDenominator = maximumPixel - minimumPixel;
	
	// Image is one solid color
	if(maximumPixel == minimumPixel){
		exitWithError("Max pixel is equivalent to minimum pixel. Scaling is impossible");
	}
	
	// Algorithm to scale each pixel
	for(int currentPixel = 0; currentPixel < pixelVector.size(); currentPixel++){
		double newValue = (double)( 255.0 * ( pixelVector[currentPixel] - minimumPixel ) ) / (double)scaleDenominator;
		int roundedValue = round(newValue);
		pixelVector[currentPixel] = roundedValue;
	}

	//Construct the new PGM
	PGM rescaledPGM(scaledPGM.getWidth(), scaledPGM.getHeight(), 255, pixelVector);
	scaledPGM = rescaledPGM;
}

PGM PGMscale::getScaledPGM(){
	return scaledPGM;
}

void PGMscale::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
