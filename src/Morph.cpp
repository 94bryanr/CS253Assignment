#include "Morph.h"

Morph::Morph(vector<KeyPoint> map, PGM pgm) : 
	inputPGM(pgm), keyPoints(map)
{
	cout << "Morph Constructor" << endl;
	modifyImage();
}

void Morph::modifyImage(){

}

PGM Morph::getPGM(){
	return inputPGM;
}

double Morph::weightKeyPoint(
		int x, int y, KeyPoint keyPoint){
	return 5;
}
