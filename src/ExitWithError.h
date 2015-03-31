#ifndef EXITWITHERROR_H
#define EXITWITHERROR_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ExitWithError{
	public:
		ExitWithError(string errorMessage);
};

#endif
