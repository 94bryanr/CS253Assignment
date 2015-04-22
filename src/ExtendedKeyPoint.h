#ifndef EXTENDED_KEY_POINT_H
#define EXTENDED_KEY_POINT_H

#include "KeyPoint.h"
#include "ExitWithError.h"
#include <vector>
using std::vector;

class ExtendedKeyPoint{
	public:
		void addKeyPoint(KeyPoint keyPoint);
		KeyPoint getKeyPoint(int index);
		int size();
		KeyPoint getSourceKeyPoint(int index);
		KeyPoint getDestinationKeyPoint(int index);
	private:
		vector<KeyPoint> keyPoints;
};

#endif
