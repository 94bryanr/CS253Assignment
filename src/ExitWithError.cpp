#include "ExitWithError.h"

ExitWithError::ExitWithError(string errorMessage){
	cout << errorMessage << endl;
	exit(-1);
}
