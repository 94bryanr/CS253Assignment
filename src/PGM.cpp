#include "PGM.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cerr;

PGM::PGM(int width, int height, int maxAllowedValue, vector<int> pixelData) :
	width(width), height(height), maxAllowedValue(maxAllowedValue), pixelData(pixelData){

	if (pixelData.size() == 0){
		exitWithError("Pixel data can not be empty.");
	}
	if (pixelData.size() != width * height){
		exitWithError("Pixel data size does not match width and height specification.");
	}

	testForInvalidData();
	calculateFields();	
}

//Fill in data about the image(average pixel, max pixel, total pixels, etc)
void PGM::calculateFields(){
	//width and height and maxAllowedValue are passed into the constructor
	
	//totalPixels
	totalPixels = width * height;

	//max, min, and average
	minPixel = pixelData[0];
	maxPixel = pixelData[0];
	int runningTotal = 0;
	for(int current : pixelData){
		//min
		if (current < minPixel){
			minPixel = current;
		}
		//max
		if (current > maxPixel){
			maxPixel = current;
		}
		//average
		runningTotal += current;
	}
	averagePixel = (double)runningTotal/(double)totalPixels;
}

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
	for(int currentPixel : pixelData){
		if (currentPixel < 0 || currentPixel > maxAllowedValue){
			exitWithError("Pixel value out of range.");
		}
	}
}

int PGM::getHeight(){
	return height;
}

int PGM::getWidth(){
	return width;
}

int PGM::getMaxAllowedValue(){
	return maxAllowedValue;
}

int PGM::getTotalPixels(){
	return totalPixels;
}

vector<int> PGM::getPixelData(){
	return pixelData;
}

int PGM::getMaxPixel(){
	return maxPixel;
}

int PGM::getMinPixel(){
	return minPixel;
}

double PGM::getAveragePixel(){
	return averagePixel;
}

void PGM::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
