#include "KeyPoint.h"

// Coordinates
KeyPoint::KeyPoint(
		unsigned int originalX, unsigned int originalY,
		unsigned int destinationX, unsigned int destinationY) :
		originalX(originalX), originalY(originalY),
		 destinationX(destinationX), destinationY(destinationY){
		 	differenceX = destinationX - originalX;
			differenceY = destinationY - originalY;
}
