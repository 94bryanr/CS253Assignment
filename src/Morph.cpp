#include "Morph.h"

Morph::Morph(vector<KeyPoint> map, PGM pgm) : 
   	inputPGM(pgm), 
	outputPGM(pgm),
	keyPoints(map)
{
	cout << "Morph Constructor" << endl;
	modifyImage();
	cout << outputPGM.at(0,0) << endl;
	cout << inputPGM.at(0,0) << endl;
}

PGM Morph::getPGM(){
	return outputPGM;
}

void Morph::modifyImage(){
	for(int y = 0; y < inputPGM.getHeight(); y++){
		for(int x = 0; x < inputPGM.getWidth(); x++){
			int inputX = x;
			int inputY = y;

			// Check to see if pixel is destination of key point
			bool destinationPixel = false;
			for (int keyPoint = 0; keyPoint < keyPoints.size(); keyPoint++){
				KeyPoint currentKeyPoint = keyPoints[keyPoint];
				if(x == currentKeyPoint.getDestinationX() && 
						y == currentKeyPoint.getDestinationY()){
					// It is, so give back the original coordinates
					inputX = currentKeyPoint.getOriginalX();
					inputY = currentKeyPoint.getOriginalY();
					cout << "Destination Pixel" << endl;
					destinationPixel = true;
				}
			}

			// Else...
			// Pixel is not a destination of a key point, need weighted average
			if (!destinationPixel){
				vector<double> deltas = averageKeyPoints(x,y);
				int deltaX = round(deltas[0]);
				int deltaY = round(deltas[1]);
				inputX = x - deltaX;
				inputY = y - deltaY;
				cout << "DelX: " << deltaX << " DelY: " << deltaY << endl;
			}
			
			
			unsigned int defaultColor = 0;
			if (inputX < 0 || inputX > inputPGM.getWidth()-1)
				outputPGM.setPixel(x,y,defaultColor);
			else if (inputY < 0 || inputY > inputPGM.getHeight()-1)
				outputPGM.setPixel(x,y,defaultColor);
			else
				outputPGM.setPixel(x,y,inputPGM.at(inputX, inputY));
		}
	}
}

double Morph::weightKeyPoint(int x, int y, KeyPoint keyPoint){
	if(x == keyPoint.getDestinationX() && y == keyPoint.getDestinationY())
		ExitWithError("Can not calculate KeyPoint weight against itself");
	int distanceX = (x-keyPoint.getDestinationX());
	int distanceY = (y-keyPoint.getDestinationY());
	int finalDistance = (distanceX*distanceX) + (distanceY*distanceY);
	double weight = (double)1.0 / (double)finalDistance;
	return weight;
}

vector<double> Morph::averageKeyPoints(int x, int y){
	vector<double> average;
	double finalWeight = 0;
	double sumKeyPointsX = 0;
	double sumKeyPointsY = 0;
	for (int keyPoint = 0; keyPoint < keyPoints.size(); keyPoint++){
		KeyPoint currentKeyPoint = keyPoints[keyPoint];
		double weight = weightKeyPoint(x, y, currentKeyPoint);
		double magnitudeX = weight * currentKeyPoint.getDifferenceX();
		double magnitudeY = weight * currentKeyPoint.getDifferenceY();
		cout << "DiffX: " << currentKeyPoint.getDifferenceX() << endl;
		cout << "DiffY: " << currentKeyPoint.getDifferenceY() << endl;
		finalWeight += weight;
		sumKeyPointsX += magnitudeX;
		sumKeyPointsY += magnitudeY;
		cout << "W: " << weight << " X: " << magnitudeX <<
		   	" Y: " << magnitudeY << endl;
	}

	cout << "FW: " << finalWeight << " FX: " << 
		sumKeyPointsX << " FY: " << sumKeyPointsY << endl;
	double deltaX = sumKeyPointsX/finalWeight;
	double deltaY = sumKeyPointsY/finalWeight;
	average.push_back(deltaX);
	average.push_back(deltaY);
	return average;
}