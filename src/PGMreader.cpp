#ifndef USING_PGMREADER
#define USING_PGMREADER
#include "PGMreader.h"

using std::endl;
using std::ifstream;
using std::cerr;

/// Construct a PGMreader, pass in a filename
PGMreader::PGMreader(string filename){
	//Open file
	fstream fileStream;
	fileStream.open(filename.c_str(), std::ios_base::in);
	if(!fileStream){
		cerr << "Error: File can not be opened" << endl;
		exit(-1);
	}

	//Check what reader to use
	//Find magic numbers
	char firstChar;
	char secondChar;
	fileStream.get(firstChar);
	fileStream.get(secondChar);
	if (firstChar == 'P' && secondChar == '2'){
		readerA = new PGMAreader(filename);
		chosenReader = 'a';
	}
	else if (firstChar == 'P' && secondChar == '5'){
		readerB = new PGMBreader(filename);
		chosenReader = 'b';
	}
	else{
		cerr << "Error: Incorrect Filetype" << endl;
		exit(-1);
	}
}

/// Get PGM object back from PGMreader
PGM PGMreader::getPGM(){
	if (chosenReader == 'a'){
		return readerA -> getPGM();
	}
	else if (chosenReader == 'b'){
		return readerB -> getPGM();
	}
	else{
		cerr << "Error: Incorrect Filetype" << endl;
		exit(-1);
	}
}

char PGMreader::getType(){
	return chosenReader;
}

#endif
