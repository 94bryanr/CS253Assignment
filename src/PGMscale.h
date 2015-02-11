#include <iostream>
#ifndef USING_PGM
	#define USING_PGM
	#include "PGM.h"
#endif
#include <math.h>

class PGMscale{
	public:
		PGMscale(PGM pgm);
		PGM getScaledPGM();
	private:
		PGM scaledPGM;
		void scalePGM();
		void exitWithError(string errorMessage);
};
