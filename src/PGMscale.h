#include <iostream>
#ifndef USING_PGM
	#define USING_PGM
	#include "PGM.h"
#endif
#include <math.h>

class PGMscale{
	public:
		/// Constructor.
		PGMscale(PGM pgm);
		/// Get the PGM file object after scaling.
		PGM getScaledPGM();
	private:
		/// Scaled PGM file object.
		PGM scaledPGM;
		/// Run the scaling algorithm on each pixel of the input PGM, reset maxAllowedValue
		void scalePGM();
		/// Exit the operating system with a -1 and output error message to cerr.
		void exitWithError(string errorMessage);
};
