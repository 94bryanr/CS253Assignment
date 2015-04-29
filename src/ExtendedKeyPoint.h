#ifndef EXTENDED_KEY_POINT_H
#define EXTENDED_KEY_POINT_H

#include "KeyPoint.h"
#include "ExitWithError.h"
#include <vector>
using std::vector;

class ExtendedKeyPoint{
	public:
		inline void addKeyPoint(KeyPoint keyPoint){keyPoints.push_back(keyPoint);};
		inline int size(){return keyPoints.size();};
	private:
		vector<KeyPoint> keyPoints;
};

#endif
