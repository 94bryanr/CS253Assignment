#ifndef PGM_H
#define PGM_H

#include<iostream>
#include<vector>
#include"ExitWithError.h"

using std::vector;
using std::string;

class PGM{
	public:
		/// Constructor
		PGM(unsigned int width, unsigned int height, unsigned int max, vector<unsigned int> pixelData);
		/// Returns the width of the image.
		unsigned int getWidth();
		/// Returns the height in pixels of the image.
		unsigned int getHeight();
		/// Returns the maximum pixel value (0-255 inclusive) allowed in the image.
		unsigned int getMaxAllowedValue();
		/// Returns height*width, or the total number of pixels in the image.
		unsigned int getTotalPixels();
		/// Returns a vector that represents each pixel in the image.
		vector<unsigned int> getPixelData();
		/// Returns the smallest pixel value found in the image.
		unsigned int getMinPixel();
		/// Returns the largest pixel value found in the image.
		unsigned int getMaxPixel();
		/// Returns the average pixel value across the entire image.
		double getAveragePixel();
		/// Get pixel at location x,y
		unsigned int at(unsigned int x, unsigned int y);
		/// Set the pixel at location(x,y) to newValue
		void setPixel(unsigned int x, unsigned int y, unsigned int newValue);
	
	private:
		/// Width in pixels of the image.
		unsigned int width;
		/// Height in pixels of the image.
		unsigned int height;
		/// Maximum allowed pixel value of the image.
		unsigned int maxAllowedValue;
		/// Total pixels in the image.
		unsigned int totalPixels;
		/// Vector of integers (unsigned) that represent the pixels of the image.
		vector<unsigned int> pixelData;
		/// Fills in data about the image: average, max, min, total pixels.
		void calculateFields();
		/// Checks to see if all supplied data is valid. Checks each pixel, supplied width, height, and max.
		void testForInvalidData();
		/// The largest pixel found in the image.
		unsigned int maxPixel;
		/// The smallest pixel found in the image.
		unsigned int minPixel;
		/// The average pixel value in the image.
		double averagePixel;
		/// Get array location from (x,y)
		unsigned int getArrayLocation(unsigned int x, unsigned int y);
};

#endif
