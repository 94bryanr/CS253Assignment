#include "PGMreader.h"
#ifndef USING_STDLIB
    #include <stdlib.h>
    #define USING_STDLIB
#endif

using std::endl;
using std::ifstream;
using std::cerr;

PGMreader::PGMreader(string filename)
	: reader(filename) {
}

PGM PGMreader::getPGM(){
	PGM outputPGM = reader.getPGM();
	return outputPGM;
}
