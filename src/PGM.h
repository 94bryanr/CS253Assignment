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
		inline unsigned int getWidth() const{return width;};
		/// Returns the height in pixels of the image.
		inline unsigned int getHeight() const{return height;};
		/// Returns the maximum pixel value (0-255 inclusive) allowed in the image.
		inline unsigned int getMaxAllowedValue() const{return maxAllowedValue;};
		/// Returns height*width, or the total number of pixels in the image.
		inline unsigned int getTotalPixels() const{return totalPixels;};
		/// Returns a vector that represents each pixel in the image.
		inline vector<unsigned int> getPixelData() const{return pixelData;};
		/// Returns the smallest pixel value found in the image.
		inline unsigned int getMinPixel() const{return minPixel;};
		/// Returns the largest pixel value found in the image.
		inline unsigned int getMaxPixel() const{return maxPixel;};
		/// Returns the average pixel value across the entire image.
		inline double getAveragePixel() const{return averagePixel;};
		/// Get pixel at location x,y
		inline unsigned int at(unsigned int x, unsigned int y){
			if(x > (width-1))
				ExitWithError("PGM at, x value out of bounds");
			if(y > (height-1))
				ExitWithError("PGM at, y value out of bounds");
			return pixelData[getArrayLocation(x,y)];
		};
		/// Set the pixel at location(x,y) to newValue
		inline void setPixel(unsigned int x, unsigned int y, unsigned int newValue){
			if (newValue > maxAllowedValue)
				ExitWithError("Set Pixel, new value out of range");
			pixelData[getArrayLocation(x,y)] = newValue;
		};
	
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
		inline unsigned int getArrayLocation(unsigned int x, unsigned int y){
			if(x > width-1)
				ExitWithError("GetArrayLocation, x coordinate out of range");
			else if(y > height-1)
				ExitWithError("GetArrayLocation, y coordinate out of range");
			return (width*y) + x;
		};
};

#endif
