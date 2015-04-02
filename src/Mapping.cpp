#include "Mapping.h"

Mapping::Mapping(string filename){
	fileStream.open(filename.c_str(), std::ios_base::in);
	if (!fileStream){
		ExitWithError("Bad KeyPoint File");
	}
	parse();
}

void Mapping::parse(){
	const int maxLineSize = 150;
	char currentLineCharArray[maxLineSize];
	// Split into individual lines to check # of line items
	while(fileStream.getline(currentLineCharArray, maxLineSize)){
		bool isEmpty = false;
		int originalX;
		int originalY;
		int destinationX;
		int destinationY;
		int currentInt;
		//Trim Line
		string currentLine = trim(string(currentLineCharArray));
		stringstream stream(currentLine);
		//Parse Line
		for(int elementCount = 0; elementCount < 4; elementCount++){
			stream >> currentInt;
			// Empty String
			if(stream.fail() && elementCount == 0){
				isEmpty = true;
				break;
			}
			if (elementCount == 0){
				originalX = currentInt;
			}
			else if (elementCount == 1){
				originalY = currentInt;
			}
			else if (elementCount == 2){
				destinationX = currentInt;
			}
			else if (elementCount == 3){
				destinationY = currentInt;
			}
			if (stream.fail())
				ExitWithError("Not enough elements on KeyPoint file line");
		}
		if (!stream.eof())
			ExitWithError("Too many elements on KeyPoint file line");
		stream.flush();
		stream.clear();
		if (isEmpty)
			continue;
		// Add to KeyPoint list
		KeyPoint keyPoint(originalX, originalY, destinationX, destinationY);
		keyPoints.push_back(keyPoint);
	}
	fileStream.close();
}

// Get rid of trailing whitespace
string Mapping::trim(string toTrim){
	if (toTrim.length() == 0)
		return "";
	while(isspace(toTrim.at(toTrim.length()-1))){
		toTrim = toTrim.substr(0, toTrim.length()-1);
		if (toTrim.length() == 0)
			return "";
	}
	return toTrim;
}

vector<KeyPoint> Mapping::getKeyPoints(){
	return keyPoints;
}
