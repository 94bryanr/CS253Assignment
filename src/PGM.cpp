#include "PGM.h"
#ifndef USING_STDLIB
    #include <stdlib.h>
    #define USING_STDLIB
#endif

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cerr;

PGM::PGM(unsigned int width, unsigned int height, unsigned int maxAllowedValue, vector<unsigned int> pixelData) :
	width(width), height(height), maxAllowedValue(maxAllowedValue), pixelData(pixelData){

	if (pixelData.size() == 0){
		exitWithError("Pixel data can not be empty.");
	}
	if (pixelData.size() != width * height){
		cerr << width << endl;
		cerr << height << endl;
		cerr << pixelData.size() << endl;
		exitWithError("Pixel data size does not match width and height specification.");
	}

	testForInvalidData();
	calculateFields();	
}

//Make sure all supplied data is valid
void PGM::testForInvalidData(){
	//maxAllowedValue
	if(maxAllowedValue == 256){
		maxAllowedValue = 255;
	}
	else if(maxAllowedValue < 1 || 256 < maxAllowedValue){
		exitWithError("MaxAllowedValue is out of range.");
	}

	//width/height
	if(width < 1){
		exitWithError("Width is out of range.");
	}
	if(height < 1){
		exitWithError("Height is out of range.");
	}

	//pixels
	for(unsigned int currentPixel = 0; currentPixel < pixelData.size(); currentPixel++){
		//cast pixelData[currentPixel] to int because unsigned int is never < 0
		if ((int)pixelData[currentPixel] < 0 || pixelData[currentPixel] > maxAllowedValue){
			exitWithError("Pixel value out of range.");
		}
	}
}

//Fill in data about the image(average pixel, max pixel, total pixels, etc)
void PGM::calculateFields(){
	//width and height and maxAllowedValue are passed into the constructor
	
	//totalPixels
	totalPixels = width * height;

	//max, min, and average
	minPixel = pixelData[0];
	maxPixel = pixelData[0];
	unsigned int runningTotal = 0;
	for(unsigned int current = 0; current < pixelData.size(); current++){
		//min
		if (pixelData[current] < minPixel){
			minPixel = pixelData[current];
		}
		//max
		if (pixelData[current] > maxPixel){
			maxPixel = pixelData[current];
		}
		//average
		runningTotal += pixelData[current];
	}
	averagePixel = (double)runningTotal/(double)totalPixels;
}


unsigned int PGM::getHeight(){
	return height;
}

unsigned int PGM::getWidth(){
	return width;
}

unsigned int PGM::getMaxAllowedValue(){
	return maxAllowedValue;
}

unsigned int PGM::getTotalPixels(){
	return totalPixels;
}

vector<unsigned int> PGM::getPixelData(){
	return pixelData;
}

unsigned int PGM::getMaxPixel(){
	return maxPixel;
}

unsigned int PGM::getMinPixel(){
	return minPixel;
}

double PGM::getAveragePixel(){
	return averagePixel;
}

void PGM::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
