#ifndef MORPH_H
#define MORPH_H

#include "PGM.h"
#include "Mapping.h"
#include <iostream>
#include "KeyPoint.h"
#include <math.h>

using std::endl;

class Morph{
	public:
		Morph(const vector<KeyPoint> &map, const PGM &pgm);
		inline PGM getPGM(){return outputPGM;};
	private:
		PGM inputPGM;
		PGM outputPGM;
		vector<KeyPoint> keyPoints;
		unsigned int imageHeight;
		unsigned int imageWidth;
		unsigned int keyPointSize;
		void modifyImage();
		double weightKeyPoint(unsigned int x, unsigned int y, KeyPoint &keyPoint) const;
		vector<double> averageKeyPoints(unsigned int x, unsigned int y);
};

#endif
