#include "Mapping.h"

Mapping::Mapping(string filename){
	cout << "Mapping Constructor" << endl;
	fileStream.open(filename.c_str(), std::ios_base::in);
	if (!fileStream){
		ExitWithError("Bad KeyPoint File");
	}
	parse();
}

void Mapping::parse(){
	cout << "Parse" << endl;
	const int maxLineSize = 150;
	char currentLineCharArray[maxLineSize];
	// Split into individual lines to check # of line items
	while(fileStream.getline(currentLineCharArray, maxLineSize)){
		cout << "Line: " << currentLineCharArray << endl;
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
				cout << "Empty Line" << endl;
				isEmpty = true;
				break;
			}
			if (elementCount == 0){
				originalX = currentInt;
				cout << "origX: " << originalX << endl;
			}
			else if (elementCount == 1){
				originalY = currentInt;
				cout << "origY: " << originalY << endl;
			}
			else if (elementCount == 2){
				destinationX = currentInt;
				cout << "destX: " << destinationX << endl;
			}
			else if (elementCount == 3){
				destinationY = currentInt;
				cout << "destY: " << destinationY << endl;
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
		cout << "Pushing Back: " << originalX << " " << originalY << " " <<
			destinationX << " " << destinationY << endl;
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
		cout << "Trimming" << endl;
		if (toTrim.length() == 0)
			return "";
	}
	return toTrim;
}

vector<KeyPoint> Mapping::getKeyPoints(){
	return keyPoints;
}
