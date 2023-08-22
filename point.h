#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class point{
private:
	
public:
	int x;
	int y;
	
	point(int a, int b) {x = a; y = b;}
	point() {x = 0, y = 0;}
	bool operator==(point& p) {return x == p.x && y == p.y;}
	void operator=(const point& p) {
		x = p.x;
		y = p.y;
	}

};

ostream& operator <<(ostream& out, point p){
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

#endif
