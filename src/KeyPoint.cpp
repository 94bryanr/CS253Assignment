#include "KeyPoint.h"

// Coordinates
KeyPoint::KeyPoint(
		unsigned int originalX, unsigned int originalY,
		unsigned int destinationX, unsigned int destinationY) :
		originalX(originalX), originalY(originalY),
		 destinationX(destinationX), destinationY(destinationY){
		 	differenceX = destinationX - originalX;
			differenceY = destinationY - originalX;
}

unsigned int KeyPoint::getOriginalX(){
	return originalX;
}

unsigned int KeyPoint::getOriginalY(){
	return originalY;
}

unsigned int KeyPoint::getDestinationX(){
	return destinationX;
}

unsigned int KeyPoint::getDestinationY(){
	return destinationY;
}

unsigned int KeyPoint::getDifferenceX(){
	return differenceX;
}

unsigned int KeyPoint::getDifferenceY(){
	return differenceY;
}
