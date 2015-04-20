#ifndef PGM_SHADER_H
#define PGM_SHADER_H

#include "PGM.h"
#include "ExitWithError.h"
#include <math.h>

class PGMshader{
	public:
		PGMshader(PGM startImage, PGM endImage, int iterations);
		vector<PGM> getInterpolatedPGMs() const;
	private:
		void interpolate();
		PGM startImage;
		PGM endImage;
		int iterations;
		vector<PGM> interpolatedPGMs;
};

#endif
