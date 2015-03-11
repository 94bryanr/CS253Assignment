#include "PGMframer.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cerr;

PGMframer::PGMframer(PGM imageOne, PGM imageTwo, unsigned int intermediateFrames) : 
	imageOne(imageOne), imageTwo(imageTwo), intermediateFrames(intermediateFrames) {
	
	checkSizes();
	interpolate();
}

vector<PGM> PGMframer::getPGMVector(){
	return PGMList;
}

void PGMframer::checkSizes(){
	//Make sure the images are the same size
	if(imageOne.getWidth() != imageTwo.getWidth()){
		exitWithError("Image Widths do not Match");
	}
	if(imageOne.getHeight() != imageTwo.getHeight()){
		exitWithError("Image Heights do not Match");
	}

	//Set height and width for interpolation
	width = imageOne.getWidth();
	height = imageOne.getHeight();
}

void PGMframer::interpolate(){
	unsigned int currentImageIndex = 0;
	unsigned int totalImages = intermediateFrames + 2;
	unsigned int framesLeft = intermediateFrames + 2;
	vector<unsigned int> imageOnePixelData = imageOne.getPixelData();
	vector<unsigned int> imageTwoPixelData = imageTwo.getPixelData();

	//Iterate through frames
	while( framesLeft > 0){
		//Populate pixelData
		vector<unsigned int> pixelData;
		int totalPixels = width * height;
		int pixelIndex = 0;
		//Iterate through pixels
		while(totalPixels > 0){
			//Scaling Algorithm
			int imageOnePixel = imageOnePixelData[pixelIndex];
			double scalar = (double)currentImageIndex / (double)(totalImages-1);
			int difference = imageTwoPixelData[pixelIndex] - imageOnePixelData[pixelIndex];
			int currentPixel = round(  (double)imageOnePixel + (scalar * (double)difference)  );

			bool print = false;
			if (print){
				cout << "Scalar: " << scalar << " ::: ";
				cout << "Diff: " << difference << " ::: ";
				cout << "IMG1Pix: " << imageOnePixelData[pixelIndex] << " ::: ";
				cout << "IMG2Pix: " << imageTwoPixelData[pixelIndex] << " ::: ";
				cout << "Current: " << currentPixel << endl;
			}

			//Add to current PGM pixel data
			pixelData.push_back(currentPixel);
			totalPixels--;
			pixelIndex++;
		}
		
		//Construct a new PGM
		PGM currentPGM (width, height, 255, pixelData);

		//Add PGM to vector
		PGMList.push_back(currentPGM);

		currentImageIndex++;
		framesLeft--;
	}
}

void PGMframer::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
