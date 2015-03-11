#ifndef PGMBREADER_H
#define PGMBREADER_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "PGM.h"

using std::fstream;
using std::string;
using std::vector;

class PGMBreader{
	public:
		/// Constructor.
		PGMBreader(string filename);
		/// Get the PGM file object after reading in Binary PGM file.
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
		/// Exits the program by returning -1 to the system and outputting an error to cerr.
		void exitWithError(string errorMessage);
};

#endif
