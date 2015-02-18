#include "PGMreader.h"
#ifndef USING_STDLIB
    #include <stdlib.h>
    #define USING_STDLIB
#endif

using std::endl;
using std::ifstream;
using std::cerr;

PGMreader::PGMreader(string filename){
	//Check what reader to use
	
	//Open file
	fstream fileStream;
	fileStream.open(filename.c_str(), std::ios_base::in);
	if(!fileStream){
		cerr << "Error: File can not be opened" << endl;
		exit(-1);
	}
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
