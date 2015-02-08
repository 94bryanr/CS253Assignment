#include<iostream>
#include<vector>

using std::vector;
using std::string;

class PGM{
	public:
		PGM(int width, int height, int max, vector<int> pixelData);
		int getWidth();
		int getHeight();
		int getMaxAllowedValue();
		int getTotalPixels();
		vector<int> getPixelData();
		int getMinPixel();
		int getMaxPixel();
		double getAveragePixel();
	
	private:
		int width;
		int height;
		int maxAllowedValue;
		int totalPixels;
		vector<int> pixelData;
		void calculateFields();
		void testForInvalidData();
		int maxPixel;
		int minPixel;
		double averagePixel;
		void exitWithError(string errorMessage);
};
