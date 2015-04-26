#include "PGMshader.h"

PGMshader::PGMshader(PGM startImage, PGM endImage, int currentImage, int iterations) :
	startImage(startImage), endImage(endImage), iterations(iterations), currentImage(currentImage), interpolatedPGM(startImage)
{
	if(startImage.getWidth() != endImage.getWidth()){
		ExitWithError("PGMshader: Unequal image widths");
	}
	if(startImage.getHeight() != endImage.getHeight()){
		ExitWithError("PGMshader: Unequal image heights");
	}
	interpolate();
}

void PGMshader::interpolate(){
	int j = currentImage + 1;
	int N = iterations;
	double sourceScalar = double(N - j + 1) / double(N + 1);
	double destinationScalar = double(j)/double(N + 1);
	vector<unsigned int> pixelData;

	// Iterate through x and y of source and destination images to fill in shaded image
	unsigned int width = startImage.getWidth();
	for(unsigned int y = 0; y < startImage.getHeight(); y++){
		for(unsigned int x = 0; x < width; x++){
			double sourceWeight = sourceScalar * double(startImage.at(x,y));
			double destinationWeight = destinationScalar * double(endImage.at(x,y));
			int finalPixel = round(sourceWeight + destinationWeight);
			pixelData.push_back(finalPixel);
		}
	}
	PGM interpolated(startImage.getWidth(), startImage.getHeight(), 256, pixelData);
	interpolatedPGM = interpolated;
}

PGM PGMshader::getInterpolatedPGM() const{
	return interpolatedPGM;
}
