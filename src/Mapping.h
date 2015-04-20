#ifndef MAPPING_H
#define MAPPING_H

#include "KeyPoint.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ExitWithError.h"
#include <sstream>
#include <vector>
#include "ExtendedKeyPoint.h"

using std::string;
using std::endl;
using std::fstream;
using std::stringstream;
using std::vector;

class Mapping{
	public:
		Mapping(string filename);
		vector<ExtendedKeyPoint> getExtendedKeyPoints();
	private:
		void parse();
		void parseLine(string line);
		fstream fileStream;
		vector<ExtendedKeyPoint> extendedKeyPoints;
		string trim(string toTrim);
};

#endif
