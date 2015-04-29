#include "Morph.h"

Morph::Morph(const vector<KeyPoint> &map, const PGM &pgm) : 
   	inputPGM(pgm), outputPGM(pgm), keyPoints(map)
{
	if(map.size() == 0){
		ExitWithError("Need at least 1 key point");
	}
	imageHeight = inputPGM.getHeight();
	imageWidth = inputPGM.getWidth();
	modifyImage();
}

//TODO: Run on each image
//TODO: Use image height and width
void Morph::modifyImage(){
	for(unsigned int y = 0; y < imageHeight; y++){
		for(unsigned int x = 0; x < imageWidth; x++){
			int inputX = x;
			int inputY = y;

			// Check to see if pixel is destination of key point
			bool destinationPixel = false;
			for (unsigned int keyPoint = 0; keyPoint < keyPoints.size(); keyPoint++){
				KeyPoint currentKeyPoint = keyPoints[keyPoint];
				if(x == currentKeyPoint.getDestinationX() && 
						y == currentKeyPoint.getDestinationY()){
					// It is, so give back the original coordinates
					inputX = currentKeyPoint.getOriginalX();
					inputY = currentKeyPoint.getOriginalY();
					destinationPixel = true;
				}
			}

			// Else...
			// Pixel is not a destination of a key point, need weighted average
			if (!destinationPixel){
				// TODO: Most expensive operation
				vector<double> deltas = averageKeyPoints(x,y);
				inputX = x - round(deltas[0]);
				inputY = y - round(deltas[1]);
			}
			
			unsigned int defaultColor = 0; //Default color (boundary color) is black
			if (inputX < 0 || inputX > ((int)imageWidth-1))
				outputPGM.setPixel(x,y,defaultColor);
			else if (inputY < 0 || inputY > ((int)imageHeight-1))
				outputPGM.setPixel(x,y,defaultColor);
			else
				outputPGM.setPixel(x,y,inputPGM.at(inputX, inputY));
		}
	}
}

//Run on each keypoint, at each x,y, on each image
double Morph::weightKeyPoint(unsigned int x, unsigned int y, KeyPoint &keyPoint) const{
	if(x == keyPoint.getDestinationX() && y == keyPoint.getDestinationY())
		ExitWithError("Can not calculate KeyPoint weight against itself");
	int distanceX = (x-keyPoint.getDestinationX());
	int distanceY = (y-keyPoint.getDestinationY());
	double weight = (double)1.0 / (double)((distanceX*distanceX) + (distanceY*distanceY));

	return weight;
}

//Run on each x,y on each keypoint
vector<double> Morph::averageKeyPoints(unsigned int x, unsigned int y){
	double finalWeight = 0;
	double sumKeyPointsX = 0;
	double sumKeyPointsY = 0;
	for (unsigned long keyPoint = 0; keyPoint < keyPoints.size(); keyPoint++){
		KeyPoint &currentKeyPoint = keyPoints[keyPoint];
		//Runs weightKeyPoint on each keyPoint and current x,y 
		double weight = weightKeyPoint(x, y, currentKeyPoint);
		double magnitudeX = weight * currentKeyPoint.getDifferenceX();
		double magnitudeY = weight * currentKeyPoint.getDifferenceY();
		finalWeight += weight;
		sumKeyPointsX += magnitudeX;
		sumKeyPointsY += magnitudeY;
	}
	vector<double> average;
	average.reserve(2);
	//Delta X
	average.push_back(sumKeyPointsX/finalWeight);
	//Delta Y
	average.push_back(sumKeyPointsY/finalWeight);
	return average;
}
