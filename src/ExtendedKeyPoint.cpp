#include "ExtendedKeyPoint.h"

///Add a key point to the vector of extended key points
void ExtendedKeyPoint::addKeyPoint(KeyPoint keyPoint){
	keyPoints.push_back(keyPoint);
}

//Returns Keypoint(Xsource, Ysource, Xindex, Yindex)
KeyPoint ExtendedKeyPoint::getSourceKeyPoint(int index){

}

//Returns Keypoint(Xindex, Yindex, Xdest, Ydest)
KeyPoint ExtendedKeyPoint::getDestinationKeyPoint(int index){

}

int ExtendedKeyPoint::size(){
	return keyPoints.size();
}
