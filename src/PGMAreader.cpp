#ifndef PGMAREADER
#define PGMAREADER

#include "PGMAreader.h"

using std::endl;
using std::ifstream;
using std::cerr;

PGMAreader::PGMAreader(string filename){ 
	fileStream.open(filename.c_str(), std::ios_base::in);
	if(!fileStream){
		exitWithError("File can not be opened");
	}

	testMagicNumber();
	readFile();
}

PGM PGMAreader::getPGM(){
    //Find beginning and end of pixel data
	vector<int>::const_iterator first = fileData.begin() + 3;
	vector<int>::const_iterator last = fileData.end();

	vector<unsigned int> pixelData(first, last);

	PGM pgm(fileData[0], fileData[1], fileData[2], pixelData);
	return pgm;
}


void PGMAreader::testMagicNumber(){
	char firstChar;
	char secondChar;
	fileStream.get(firstChar);
	fileStream.get(secondChar);
	bool correctMagicNumbers = (firstChar == 'P' && secondChar == '2');
	if(!correctMagicNumbers){
		exitWithError("File does not have magic numbers!");
	}
}

void PGMAreader::readFile(){
	int current;
	while(!fileStream.eof()){
		if(fileStream >> current){
			//Current is an integer
			fileData.push_back(current);
		}
		else if(fileStream.fail() && !fileStream.eof()){
			//We are not reading a digit
			fileStream.clear(); //Clear the fail bit
			string comment;
			if(std::getline(fileStream, comment)){
				//We have read in a comment
				//Check for comment delimiter 
				if(comment[0] != '#'){
					exitWithError("Incorrect comment formatting");
				}
			}
			else{
				exitWithError("Unknown input value");
			}
		}
	}
}

void PGMAreader::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}

#endif
