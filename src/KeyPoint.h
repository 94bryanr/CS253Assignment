#ifndef KeyPoint_H
#define KeyPoint_H

#include <iostream>
#include "ExitWithError.h"
using std::endl;

class KeyPoint{
	public:
		KeyPoint(unsigned int originalX, unsigned int originalY,
				unsigned int destinationX, unsigned int destinationY);
		inline unsigned int getOriginalX(){return originalX;};
		inline unsigned int getOriginalY(){return originalY;};
		inline unsigned int getDestinationX(){return destinationX;};
		inline unsigned int getDestinationY(){return destinationY;};
		inline int getDifferenceX(){return differenceX;};
		inline int getDifferenceY(){return differenceY;};
	private:
		unsigned int originalX;
		unsigned int originalY;
		unsigned int destinationX;
		unsigned int destinationY;
		unsigned int differenceX;
		unsigned int differenceY;
};

#endif
