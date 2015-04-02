#include "PGM.h"

using std::endl;
using std::vector;
using std::string;
using std::cerr;

PGM::PGM(unsigned int width, unsigned int height, unsigned int maxAllowedValue, vector<unsigned int> pixelData) :
	width(width), height(height), maxAllowedValue(maxAllowedValue), pixelData(pixelData){
	
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
		ExitWithError("MaxAllowedValue is out of range.");
	}

	//pixels
	for(unsigned int currentPixel = 0; currentPixel < pixelData.size(); currentPixel++){
		//cast pixelData[currentPixel] to int because unsigned int is never < 0
		if ((int)pixelData[currentPixel] < 0 || pixelData[currentPixel] > maxAllowedValue){
			ExitWithError("Pixel value out of range.");
		}
	}

	//pixel data size
	if (pixelData.size() != width * height){
		cerr << "Width: " <<  width << endl;
		cerr << "Height: " << height << endl;
		cerr << "Pixels: " << pixelData.size() << endl;
		ExitWithError("Pixel data size does not match width and height specification.");
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

unsigned int PGM::at(unsigned int x, unsigned int y){
	if(x > (width-1))
		ExitWithError("PGM at, x value out of bounds");
	if(y > (height-1))
		ExitWithError("PGM at, y value out of bounds");
	return pixelData[getArrayLocation(x,y)];
}

void PGM::setPixel(unsigned int x, unsigned int y, unsigned int newValue){
	if (newValue > maxAllowedValue)
		ExitWithError("Set Pixel, new value out of range");
	pixelData[getArrayLocation(x,y)] = newValue;
}

unsigned int PGM::getArrayLocation(unsigned int x, unsigned int y){
	if(x > width-1)
		ExitWithError("GetArrayLocation, x coordinate out of range");
	else if(y > height-1)
		ExitWithError("GetArrayLocation, y coordinate out of range");
 	return (width*y) + x;
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
