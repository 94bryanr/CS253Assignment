#ifndef KeyPoint_H
#define KeyPoint_H

class KeyPoint{
	public:
		KeyPoint(unsigned int originalX, unsigned int originalY,
				unsigned int destinationX, unsigned int destinationY);
		unsigned int getOriginalX();
		unsigned int getOriginalY();
		unsigned int getDestinationX();
		unsigned int getDestinationY();
		unsigned int getDifferenceX();
		unsigned int getDifferenceY();
	private:
		unsigned int originalX;
		unsigned int originalY;
		unsigned int destinationX;
		unsigned int destinationY;
		unsigned int differenceX;
		unsigned int differenceY;
};

#endif
