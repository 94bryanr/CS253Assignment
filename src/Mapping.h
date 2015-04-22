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
#include "Coordinate.h"

using std::string;
using std::endl;
using std::fstream;
using std::stringstream;
using std::vector;

class Mapping{
	public:
		Mapping(string filename);
		int getIntermediates();
		vector<KeyPoint> getSourceKeyPoints(int line);
		vector<KeyPoint> getDestinationKeyPoints(int line);
	private:
		void parse();
		void parseLine(string line);
		fstream fileStream;
		string trim(string toTrim);
		//Each larger vector is a line, each smaller vector are the KeyPoints for that line
		vector<vector<KeyPoint> > sourceKeyPoints;
		vector<vector<KeyPoint> > destinationKeyPoints;
		int intermediates;
		int coordinatesPerLine;
};

#endif
