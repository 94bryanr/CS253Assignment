#include <iostream>
#ifndef USING_PGM
	#define USING_PGM
	#include "../PGM.h"
#endif
#include <fstream>
#include "PGMAwriter.h"
#include "PGMBwriter.h"

class PGMwriter{
	public:
		/// Constructor
		PGMwriter(PGM pgm, string fileLocation);
		/// Write a formatted PGM to the file passed in to the constructor.
		void write();

	private:
		void exitWithError(string errorMessage);
		PGMAwriter* writerA;
		PGMBwriter* writerB;
		char usingWriter;
};
