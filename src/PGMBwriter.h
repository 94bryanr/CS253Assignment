#ifndef PGMBWRITER_H
#define PGMBWRITER_H

#include <iostream>
#include "PGM.h"
#include <fstream>

class PGMBwriter{
	public:
		/// Constructor
		PGMBwriter(PGM pgm, string fileLocation);
		/// Write a formatted PGM to the file passed in to the constructor.
		void write();

	private:
		/// PGM object that will be parsed and written to a file
		PGM pgm;
		/// Location to write output file to.
		string fileLocation;
};

#endif
