#ifndef USING_PGMREADER
#define USING_PGMREADER
#include "PGMreader.h"

using std::endl;
using std::ifstream;

/// Construct a PGMreader, pass in a filename
PGMreader::PGMreader(string filename){
	//Open file
	fstream fileStream;
	fileStream.open(filename.c_str(), std::ios_base::in);
	if(!fileStream){
		ExitWithError("Error: File can not be opened");
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
		ExitWithError("Error: Incorrect Filetype");
	}
    fileStream.close();
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
		ExitWithError("Error: Incorrect Filetype");
		// To get compiler to stop complaining
		return readerA -> getPGM();
	}
}

char PGMreader::getType(){
	return chosenReader;
}

PGMreader::~PGMreader(){
    if(chosenReader == 'a')
        delete readerA;
    else if(chosenReader == 'b')
        delete readerB;
}

#endif
