#include "ExtendedKeyPoint.h"

///Add a key point to the vector of extended key points
void ExtendedKeyPoint::addKeyPoint(KeyPoint keyPoint){
	keyPoints.push_back(keyPoint);
}

int ExtendedKeyPoint::size(){
	return keyPoints.size();
}
