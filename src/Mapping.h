#ifndef MAPPING_H
#define MAPPING_H

#include "KeyPoint.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ExitWithError.h"
#include <sstream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::fstream;
using std::stringstream;
using std::vector;

class Mapping{
	public:
		Mapping(string filename);
		vector<KeyPoint> getKeyPoints();
	private:
		void parse();
		fstream fileStream;
		vector<KeyPoint> keyPoints;
		string trim(string toTrim);
};

#endif
