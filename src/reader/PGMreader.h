#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#ifndef USING_PGM
	#define USING_PGM
	#include "../PGM.h"
#endif
#include "PGMAreader.h"
#include "PGMBreader.h"

using std::fstream;
using std::string;
using std::vector;

class PGMreader{
	public:
		/// Constructor.
		PGMreader(string filename);
		/// Get the PGM file object after reading in ASCII PGM file.
		PGM getPGM();

	private:
		/// Holds the PGM reader
		PGMBreader reader;
};
