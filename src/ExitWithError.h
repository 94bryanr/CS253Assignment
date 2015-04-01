#ifndef EXITWITHERROR_H
#define EXITWITHERROR_H

#include <iostream>
#include <string>
#include <stdlib.h>

using std::cerr;
using std::endl;
using std::string;

class ExitWithError{
	public:
		ExitWithError(string errorMessage);
};

#endif
