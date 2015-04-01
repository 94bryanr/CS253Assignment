#ifndef PGMAWRITER_H
#define PGMAWRITER_H

#include <iostream>
#include "PGM.h"
#include <fstream>
#include "ExitWithError.h"

class PGMAwriter{
	public:
		/// Constructor
		PGMAwriter(PGM pgm, string fileLocation);
		/// Write a formatted PGM to the file passed in to the constructor.
		void write();

	private:
		/// PGM object that will be parsed and written to a file
		PGM pgm;
		/// Location to write output file to.
		string fileLocation;
};

#endif
