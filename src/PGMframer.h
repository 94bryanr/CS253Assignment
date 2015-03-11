#ifndef PGMFRAMER_H
#define PGMFRAMER_H

#include <iostream>
#include <vector>
#include "PGM.h"
#include <math.h>

using std::vector;
using std::string;

class PGMframer{
	public:
		PGMframer(PGM imageOne, PGM imageTwo, unsigned int intermediateFrames);
		vector<PGM> getPGMVector();
	private:
		void interpolate();
		PGM imageOne;
		PGM imageTwo;
		int width;
		int height;
		int intermediateFrames;
		vector<PGM> PGMList;
		void checkSizes();
		void exitWithError(string errorMessage);
};

#endif
