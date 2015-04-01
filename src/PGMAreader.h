#ifndef PGMAREADER_H
#define PGMAREADER_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "PGM.h"
#include "ExitWithError.h"

using std::fstream;
using std::string;
using std::vector;

class PGMAreader{
	public:
		/// Constructor.
		PGMAreader(string filename);
		/// Get the PGM file object after reading in ASCII PGM file.
		PGM getPGM();

	private:
		/// File stream, opens file passed in to constructor.
		fstream fileStream;
		/// Vector of ALL file data, including width, height, max.
		vector<int> fileData;
		/// Check to see if 'P2' are the first characters of the file.
		void testMagicNumber();
		/// Opens the filestream and constructs the fileData vector.
		void readFile();
};

#endif
