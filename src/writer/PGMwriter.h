#include <iostream>
#ifndef USING_PGM
	#define USING_PGM
	#include "../PGM.h"
#endif
#include <fstream>

class PGMwriter{
	public:
		/// Constructor
		PGMwriter(PGM pgm, string fileLocation);
		/// Write a formatted PGM to the file passed in to the constructor.
		void write();

	private:
		/// PGM object that will be parsed and written to a file
		PGM pgm;
		/// Location to write output file to.
		string fileLocation;
		/// Exit operating system with -1 and output error to cerr.
		void exitWithError(string errorMessage);
};
