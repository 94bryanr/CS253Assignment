#ifndef PGMWRITER_H
#define PGMWRITER_H

#include <iostream>
#include "PGM.h"
#include <fstream>
#include "PGMAwriter.h"
#include "PGMBwriter.h"
#include "ExitWithError.h"

class PGMwriter{
	public:
		/// Constructor
		PGMwriter(PGM pgm, string fileLocation);
		/// Write a formatted PGM to the file passed in to the constructor.
		void write();

	private:
		PGMAwriter* writerA;
		PGMBwriter* writerB;
		char usingWriter;
};

#endif
