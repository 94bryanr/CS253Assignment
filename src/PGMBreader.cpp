#ifndef PGMBREADER
#define PGMBREADER
#include "PGMBreader.h"

using std::endl;
using std::ifstream;
using std::cout;

PGMBreader::PGMBreader(string filename){ 
	fileStream.open(filename.c_str(), std::ios_base::in | std::ios_base::binary);
	fileStream.unsetf(std::ios_base::skipws);
	if(!fileStream){
		ExitWithError("File can not be opened");
	}

	testMagicNumber();
	readFile();
}

PGM PGMBreader::getPGM(){
    //Find beginning and end of pixel data
	vector<int>::const_iterator first = fileData.begin() + 3;
	vector<int>::const_iterator last = fileData.end();
	vector<unsigned int> pixelData(first, last);

	PGM pgm(fileData[0], fileData[1], fileData[2], pixelData);
	return pgm;
}


void PGMBreader::testMagicNumber(){
	char firstChar;
	char secondChar;
	fileStream.get(firstChar);
	fileStream.get(secondChar);
	bool correctMagicNumbers = (firstChar == 'P' && secondChar == '5');
	if(!correctMagicNumbers){
		ExitWithError("File does not have magic numbers!");
	}
}

void PGMBreader::readFile(){
	unsigned char cur; //will contain the integer value of the pixel
	unsigned int current;
	unsigned int headerLength = 12; //number of bytes in the entire header
	unsigned int headerSize = 4; //the width of a header value in bytes

	//Get header
	unsigned int runningHeaderValue = 0;
	for(unsigned int i = 0; i < headerLength; i++){
		//Read in a char then conver to int
		fileStream >> cur;
		current = cur;

		if(current != 0){
			//Add value to data
			unsigned int pushBack = 8 * (3-(i%4));
			unsigned int valueToAdd = current << pushBack;
			runningHeaderValue += valueToAdd;
		}
		if( (i+1) % headerSize == 0){
			//Finalize the data
			fileData.push_back(runningHeaderValue);
			runningHeaderValue = 0;
		}
	}

	while(!fileStream.eof()){
		if(fileStream >> cur){
			//Current is a byte 
			current = cur;
			fileData.push_back(current);
		}
	}
}

#endif
