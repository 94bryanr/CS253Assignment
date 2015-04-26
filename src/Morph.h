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
		Morph(const vector<KeyPoint> map, PGM pgm);
		PGM getPGM();
	private:
		PGM inputPGM;
		PGM outputPGM;
		vector<KeyPoint> keyPoints;
		void modifyImage();
		double weightKeyPoint(unsigned int x, unsigned int y, KeyPoint keyPoint);
		vector<double> averageKeyPoints(unsigned int x, unsigned int y);
};

#endif
