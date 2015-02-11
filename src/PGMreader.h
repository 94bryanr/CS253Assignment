#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#ifndef USING_PGM
	#define USING_PGM
	#include "PGM.h"
#endif

using std::fstream;
using std::string;
using std::vector;

class PGMreader{
	public:
		void test();
		PGMreader(string filename);
		PGM getPGM();

	private:
		fstream fileStream;
		vector<int> fileData;
		void testMagicNumber();
		void readFile();
		void checkForComment();
		void getNextValue();
		void exitWithError(string errorMessage);
};
