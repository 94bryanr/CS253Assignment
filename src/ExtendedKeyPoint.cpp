#include "ExtendedKeyPoint.h"

///Add a key point to the vector of extended key points
void ExtendedKeyPoint::addKeyPoint(KeyPoint keyPoint){
	keyPoints.push_back(keyPoint);
}

///Get key point at index
KeyPoint ExtendedKeyPoint::getKeyPoint(int index){
	if (index < int(keyPoints.size())){
		return keyPoints[index];
	}
	else{
		ExitWithError("Index out of Bounds, getExtendedKeyPoint(int index): Extended Key Point");
	}

	//Suppress the "Function may reach end of non-void statement" compiler warning
	KeyPoint compilerSilencer(1,2,3,4);
	return compilerSilencer;
}

int ExtendedKeyPoint::size(){
	return keyPoints.size();
}
