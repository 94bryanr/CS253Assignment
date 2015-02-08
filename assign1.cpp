#ifndef COMP_IOSTREAM
	#include<iostream>
	#define COMP_IOSTREAM
#endif
#ifndef FSTREAM
	#include<fstream>
	#define FSTREAM
#endif
#ifndef CSTDLIB
	#include<cstdlib> //Allows exit() call
	#define CSTDLIB
#endif
#ifndef PGM_READER
	#include "PGMreader.h"
	#define PGM_READER
#endif

using std::cout;
using std::cin;
using std::endl; 
using std::string;
using std::ifstream;
using std::cerr;

void readInput(char* fileLocation);
void exitWithError(string errorMessage);
void openFile(ifstream& stream);

int main(int argc, char* argv[]){
	ifstream filestream;
	if (argc == 2){    
		readInput(argv[1]);
	}
	else{
		exitWithError("Incorrect number of arguments.");
		return -1;
	}

	return 0;
}

void readInput(char* fileLocation){
	//Read the input file
	ifstream myfile (fileLocation);
	if (myfile.is_open()){
		openFile(myfile);
	}
	else {
		exitWithError("File not opened. Bad filename.");
	}
}

void openFile(ifstream& stream){
	PGMreader file (stream);
	cout << file.getLowestPixel() << " " << file.getAveragePixel() << " " << file.getHighestPixel() << endl;
}

void exitWithError(string errorMessage){
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}
