#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate{
	public:
		Coordinate(int x, int y);
		inline int getX(){return x;};
		inline int getY(){return y;};
	private:
		int x;
		int y;
};

#endif
