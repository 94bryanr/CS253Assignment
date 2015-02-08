#include "PGMreader.h"
	
PGMreader::PGMreader(ifstream& stream)
	: fileStream(stream)
{
	scanFile();
}

void PGMreader::scanFile(){
	if(fileStream.is_open()){
		//The stream opened 
		//TODO: Check that these characters can be read!
		char firstCharacter = fileStream.get();
		char secondCharacter = fileStream.get();
		if (firstCharacter == 'P' && secondCharacter == '2'){
			//Can I condense this into a method that reads every remaining value into a vector?
			checkForComment();
			getWidth();
			getHeight();
			getMax();
			lowestPixel = max + 1;
			highestPixel = 0;
			calculatePixelData();
		}
		else{
			exitWithError("File does not start with 'P2'.");
		}
	}
	else {
		exitWithError("Stream not opened correctly.");
	}
}

int PGMreader::getWidth(){
	fileStream >> width;
	checkHeaderValue(width);
	checkForComment();
	return 0;
}

int PGMreader::getHeight(){
	fileStream >> height;
	checkHeaderValue(height);
	checkForComment();
	return 0;
}

int PGMreader::getMax(){
	fileStream >> max;
	checkHeaderValue(max);
	if(max == 256){
		//For incorrect formatting
		max = 255;
	}
	if(max > 256){
		exitWithError("Max value too large");
	}
	checkForComment();
	return 0;
}

double PGMreader::getAveragePixel(){
	return averagePixel;
}

int PGMreader::getLowestPixel(){
	return lowestPixel;
}

int PGMreader::getHighestPixel(){
	return highestPixel;
}

void PGMreader::exitWithError(string errorMessage){	
	cerr << "Error: " << errorMessage << endl;
	exit(-1);
}

void PGMreader::calculatePixelData(){
	int totalPixels = width * height;
	int currentPixel;
	int runningTotal = 0;
	checkForComment();
	for(int i = 0; i < totalPixels; i++){
		if(fileStream.eof()){
			//We havent finished reading pixels,
			//if we are already at the eof, exit.
			exitWithError("Too few pixels");
		}
		fileStream >> currentPixel;
		//Make sure we dont have a negative pixel
		checkPixelFormat(currentPixel);
		runningTotal += currentPixel;
		checkForComment();
	}
	if(!fileStream.eof()){
		//We are done reading pixels, if we are not at the
		//end of the file, exit.
		exitWithError("Too many pixels");
	}
	averagePixel = (double)runningTotal / (double)totalPixels;
}

void PGMreader::checkForComment(){
	//Next character in the stream
	char nextChar;
	while(isspace(fileStream.peek()) || fileStream.peek() == '#'){
		//Eat up whitspace to find # signs
		nextChar = fileStream.get();
		if(nextChar == '#'){
			//We have found a comment
			while (fileStream.peek() != '\n' && !fileStream.eof()){
				//Chew through characters to find \n or EOF, end of comment
				nextChar = fileStream.get();
			}
		}
	}
}

void PGMreader::checkPixelFormat(int pixel){
	// Negative pixels, width, height, etc are not allowed.
	if (pixel < 0){
		exitWithError("Negative Pixel");
	}
	if (pixel > highestPixel){
		highestPixel = pixel;
	}
	if (pixel < lowestPixel){
		lowestPixel = pixel;
	}
	if(pixel > max){
		exitWithError("Pixel Greater Than Max");
	}
}

 void PGMreader::checkHeaderValue(int spec){
	//Check value of height, min, and max
	if (spec <= 0){
		exitWithError("Invalid Header Value");
	}
 }
