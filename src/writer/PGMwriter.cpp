#include "PGMwriter.h"
#ifndef USING_STDLIB
    #include <stdlib.h>
    #define USING_STDLIB
#endif

using std::endl;
using std::cerr;
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
		exitWithError("No writer chosen");
	}
}

void PGMwriter::exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
