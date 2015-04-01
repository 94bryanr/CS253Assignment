#ifndef KeyPoint_H
#define KeyPoint_H

#include <iostream>
using std::endl;
using std::cout;

class KeyPoint{
	public:
		KeyPoint(unsigned int originalX, unsigned int originalY,
				unsigned int destinationX, unsigned int destinationY);
		unsigned int getOriginalX();
		unsigned int getOriginalY();
		unsigned int getDestinationX();
		unsigned int getDestinationY();
		int getDifferenceX();
		int getDifferenceY();
	private:
		unsigned int originalX;
		unsigned int originalY;
		unsigned int destinationX;
		unsigned int destinationY;
		unsigned int differenceX;
		unsigned int differenceY;
};

#endif
