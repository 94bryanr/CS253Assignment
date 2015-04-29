#include "Mapping.h"

Mapping::Mapping(string filename) : coordinatesPerLine(-1){
	fileStream.open(filename.c_str(), std::ios_base::in);
	if (!fileStream){
		ExitWithError("Bad KeyPoint File");
	}
	parse();
	intermediates = sourceKeyPoints[0].size();
}

void Mapping::parse(){
	//For each line: parseLine(line)
	string currentLine;
	bool isBlank = true;
	while (getline(fileStream, currentLine)){
		parseLine(currentLine);
		isBlank = false;
	}
	if(isBlank){
		ExitWithError("KeyPoint file is empty");
	}

}

void Mapping::parseLine(string line){
	vector<Coordinate> coordinates;
	line = trim(line);
	stringstream lineStream(line);

	int currentX;
	int currentY;
	while(lineStream >> currentX >> currentY){
		Coordinate coordinate(currentX, currentY);
		coordinates.push_back(coordinate);
	}
	//Check to see that we have at least 3 coordinates on the line
	if (coordinates.size() < 3){
		ExitWithError("Mapping: Not enough coordinates on a KeyPoint line");
	}
	//Check to see that the number of coordinates on this line is equivalent to all other lines
	if(coordinatesPerLine == -1){
		coordinatesPerLine = coordinates.size();
	}
	else if(coordinatesPerLine != int(coordinates.size())){
		ExitWithError("Mapping: Unequal keypoint sizes");
	}

	vector<KeyPoint> lineSourceKeyPoints;
	vector<KeyPoint> lineDestinationKeyPoints;

	// Start at 1 and end at coordinates.size-1 because we want to begin creating source and destination keypoints,
	// which start after the source coordinate (index 0) and run until the destination keypoint
	// (index coordinates.size()-1)
	for (int j = 1; j < int(coordinates.size()-1); j++){
		Coordinate source = coordinates[0];
		Coordinate dest = coordinates[coordinates.size()-1];
		Coordinate frame = coordinates[j];

		KeyPoint sourcePoint(source.getX(), source.getY(), frame.getX(), frame.getY());
		//Switched, worded wrong in assignment
		KeyPoint destinationPoint(dest.getX(), dest.getY(), frame.getX(), frame.getY());

		lineSourceKeyPoints.push_back(sourcePoint);
		lineDestinationKeyPoints.push_back(destinationPoint);
	}

	if(lineSourceKeyPoints.size() != lineDestinationKeyPoints.size()){
		ExitWithError("Mapping: Source and Destination KeyPoints have differing sizes");
	}

	//Check to see that no destinations are equivalent
	for(int keyPointIndex = 0; keyPointIndex < int(lineSourceKeyPoints.size()); keyPointIndex++){
		KeyPoint sourceToCheck = lineSourceKeyPoints[keyPointIndex];
		
		//TODO: getSourceKeyPoints is innefficient here
		//Iterate through all previous keypoints at our destination
		vector<KeyPoint> possibleSourceConflicts = getSourceKeyPoints(keyPointIndex);

		for (int i = 0; i < int(possibleSourceConflicts.size()); i++){
			KeyPoint checkSourceAgainst = possibleSourceConflicts[i];
			if (sourceToCheck.getDestinationX() == checkSourceAgainst.getDestinationX() && 
					sourceToCheck.getDestinationY() == checkSourceAgainst.getDestinationY()){
				ExitWithError("Mapping: Keypoints have the same destination");
			}
		}
	}
	sourceKeyPoints.push_back(lineSourceKeyPoints);
	destinationKeyPoints.push_back(lineDestinationKeyPoints);
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

//TODO: Make map table
vector<KeyPoint> Mapping::getSourceKeyPoints(int image){
	int mapSize = sourceKeyPoints.size();
	vector<KeyPoint> map;
	map.reserve(mapSize);
	for (int i = 0; i < mapSize; i++){
		map.push_back(sourceKeyPoints[i][image]);
	}
	return map;
}

vector<KeyPoint> Mapping::getDestinationKeyPoints(int image){
	vector<KeyPoint> map;
	for (int i = 0; i < int(destinationKeyPoints.size()) ; i++){
		map.push_back(destinationKeyPoints[i][image]);
	}
	return map;
}
