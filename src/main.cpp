#include<iostream>
#include "PGM.h"
#include "PGMreader.h"
#include "PGMscale.h"

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char* argv[]){
	vector<int> test;
	test.push_back(10);
	test.push_back(255);
	test.push_back(-0);
	test.push_back(2);
	PGM pgm(4, 1, 255, test);
	cout << "Total Pixels: " << pgm.getTotalPixels() << endl;
	cout << "Max Pixel: " << pgm.getMaxPixel() << endl;
	cout << "Min Pixel: " << pgm.getMinPixel() << endl;
	cout << "Average Pixel: " << pgm.getAveragePixel() << endl;

	//PGMreader reader(filename);

	//PGM testPGM();
	//PGMscale scale(testPGM);
}
