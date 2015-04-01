#ifndef PGMREADER_H
#define PGMREADER_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "PGM.h"
#include "PGMAreader.h"
#include "PGMBreader.h"
#include "ExitWithError.h"

using std::fstream;
using std::string;
using std::vector;

class PGMreader{
	public:
		/// Constructor.
		PGMreader(string filename);
		/// Get the PGM file object after reading in ASCII PGM file.
		PGM getPGM();
		/// Get the type of file that was given to the reader
		char getType();

	private:
		/// Holds the PGM reader
		PGMAreader* readerA;
		PGMBreader* readerB;
		char chosenReader;
};

#endif
