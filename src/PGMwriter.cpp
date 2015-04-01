#ifndef PGMWRITER
#define PGMWRITER

#include "PGMwriter.h"

using std::endl;
using std::fstream;

PGMwriter::PGMwriter(PGM pgm, string fileLocation) {
	//Determine if we are using an ASCII or BINARY writer
	//Filename ends with .pgma, use ASCII
	usingWriter = 'z';
	if(fileLocation.substr(fileLocation.length() - 5) == ".pgma"){
		writerA = new PGMAwriter(pgm, fileLocation);
		usingWriter = 'a';
	}
	else{
		writerB = new PGMBwriter(pgm, fileLocation);
		usingWriter = 'b';
	}
}

void PGMwriter::write(){
	//If using writerA, call A writers function
	if(usingWriter == 'a'){
		writerA->write();
	}
	else if(usingWriter == 'b'){
		writerB->write();
	}
	else{
		ExitWithError("No writer chosen");
	}
}

#endif
