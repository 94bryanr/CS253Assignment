#ifndef MORPH_H
#define MORPH_H

#include "PGM.h"
#include "Mapping.h"
#include <iostream>
#include "KeyPoint.h"

using std::cout;
using std::endl;

class Morph{
	public:
		Morph(vector<KeyPoint> map, PGM pgm);
		PGM getPGM();
	private:
		PGM inputPGM;
		vector<KeyPoint> keyPoints;
		void modifyImage();
		double weightKeyPoint(
				int x, int y, KeyPoint keyPoint);
};

#endif
