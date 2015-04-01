#include "ExitWithError.h"

ExitWithError::ExitWithError(string errorMessage){
	cerr << errorMessage << endl;
	exit(-1);
}
