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

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::cerr;

class PGMreader{	
	public:
		PGMreader(ifstream& stream);
		double getAveragePixel();
		int getLowestPixel();
		int getHighestPixel();
	private:
		int lowestPixel, highestPixel;
		double averagePixel;
		ifstream& fileStream;
		int width, height, max;
		void scanFile();
		int getWidth();
		int getHeight();
		int getMax();
		void calculatePixelData();
		void exitWithError(string errorMessage);
		void checkForComment();
		void checkPixelFormat(int pixel);
		void checkHeaderValue(int spec);
};
