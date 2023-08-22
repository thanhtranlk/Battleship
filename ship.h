#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <cstdlib>
#include <ctime>
#include "point.h"

using namespace std;


class ship {

private:
	point origin;
	int length, hitCount;
	string name;
	
public:
	bool isVertical;

	
	ship(int l, string n) {length = l; name = n; hitCount = 0;}
	

	void setOrigin(point p) {origin = p;}
	void setVertical(bool b) {isVertical = b;}
	int getLength() {return length;}
	point getOrigin() {return origin;}
	string getName() {return name;}
	void bumpHitCount() {hitCount++;}
	bool isAfloat() {return hitCount != length;}
	
	bool containsPoint(point p) {
	if(isVertical && origin.x == p.x) {
		for(int i = origin.y; i < (origin.y + length); i++) {
			if(i == p.y) return true;
		}
	}else if(!isVertical && origin.y == p.y) {
		for(int i = origin.x; i < (origin.x + length); i++) {
			if(i == p.x) return true;
		}
	}
	return false;
}
	void randomlyPlaceShip() {
	//bool hasConflict = true;
	//while (hasConflict) {
	
	srand(time(NULL));
	bool b = rand() % 2;
	setVertical(b);
	if(isVertical) {
		srand(time(NULL));
		int rx = rand() % 10 + 1;
		int ry = rand() % (10 - (getLength() - 1)) + 1;
		point r(rx, ry);
		setOrigin(r);
	}else {
		srand(time(NULL));
		int rx = rand() % (10 - (getLength() - 1)) + 1;
		int ry = rand() % 10 + 1;
		point r(rx, ry);
		setOrigin(r);
	}
	//}
	
}

bool hasConflictWith(ship s) {
	point p;
	if(isVertical) {
		for(int i = origin.y; i < (origin.y + length); i++) {
			p.x = origin.x;
			p.y = i;
			if(s.containsPoint(p)) {
				return true;
			}
		}
	}else if(!isVertical) {
		for(int i = origin.x; i < (origin.x + length); i++) {
			p.x = i;
			p.y = origin.y;
			if(s.containsPoint(p)) {
				return true;
			}
		}
	}
	return false;
}
};

#endif















