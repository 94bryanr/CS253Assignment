#include<iostream>
#include<vector>

using std::vector;
using std::string;

class PGM{
	public:
		PGM(unsigned int width, unsigned int height, unsigned int max, vector<unsigned int> pixelData);
		unsigned int getWidth();
		unsigned int getHeight();
		unsigned int getMaxAllowedValue();
		unsigned int getTotalPixels();
		vector<unsigned int> getPixelData();
		unsigned int getMinPixel();
		unsigned int getMaxPixel();
		double getAveragePixel();
	
	private:
		unsigned int width;
		unsigned int height;
		unsigned int maxAllowedValue;
		unsigned int totalPixels;
		vector<unsigned int> pixelData;
		void calculateFields();
		void testForInvalidData();
		unsigned int maxPixel;
		unsigned int minPixel;
		double averagePixel;
		void exitWithError(string errorMessage);
};
