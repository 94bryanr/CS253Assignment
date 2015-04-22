#ifndef EXTENDED_KEY_POINT_H
#define EXTENDED_KEY_POINT_H

#include "KeyPoint.h"
#include "ExitWithError.h"
#include <vector>
using std::vector;

class ExtendedKeyPoint{
	public:
		void addKeyPoint(KeyPoint keyPoint);
		int size();
	private:
		vector<KeyPoint> keyPoints;
};

#endif
