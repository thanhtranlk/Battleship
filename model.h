
#include <iostream>
#include <string>
#include "ship.h"
#include "point.h"
#include <iostream>
#include <string>




class model {
private:
	ship* shipFleet[5];
	int rows, columns;
	
public:
	int hitCount, missCount, shotCount;
	
	point hits[17], misses[83], shots[100];
	
	model(int v, int h) {
	rows = v;
	columns = h;
	hitCount = 0;
	missCount = 0;
	shotCount = 0;
}

void display(ship s[], int size) {
		cout << "    A B C D E F G H I J\n";
	for (int i = 1; i <= rows; i++) {
		if (i != 10) {
			cout << " " << i << " ";
		}else cout << i << " ";	
		for (int j = 1; j <= columns; j++) {
			point p(j, i);
			bool shipPresent = false;
			/*======this block for de-bugging only
			
			for (int a = 0; a < size; a++) {
				if (s[a].containsPoint(p)) {
					cout << " a";
					shipPresent = true;
				}
			}
			 =========*/
			for (int h = 0; h < hitCount; h++) {
				if (hits[h] == p) {
					cout << " x";
					shipPresent = true;
				}
			}
			if(!shipPresent) {
				bool missPresent = false;
				for (int m = 0; m < missCount; m++) {
					if (misses[m] == p) {
						cout << " @";
						missPresent = true;
					}
				}
				if(!missPresent) cout << " .";
			}
		}
		cout << endl;
	}
}

point getFiringCoordinates() {
	string a, b;
	int x, y = 0;
	point p(x, y);
	bool alreadyShot = true;
	while (alreadyShot) {
		alreadyShot = false;
		//loop below gets and validates the x value
		bool valid = false;
		while (!valid) {
			valid = true;
			cout << "Enter the x coordinate(A-J):  ";
			cin >> a;
			if (a == "a" || a == "A") x = 1;
			else if (a == "b" || a == "B") x = 2;
			else if (a == "c" || a == "C") x = 3;
			else if (a == "d" || a == "D") x = 4;
			else if (a == "e" || a == "E") x = 5;
			else if (a == "f" || a == "F") x = 6;
			else if (a == "g" || a == "G") x = 7;
			else if (a == "h" || a == "H") x = 8;
			else if (a == "i" || a == "I") x = 9;
			else if (a == "j" || a == "J") x = 10;
			else {
				cout << "\nSorry, coordinate \"" << a << "\" is not recognized...\n";
				valid = false;
			}
		}
		//loop below gets and validates the y value
		valid = false;
		while (!valid) {
			valid = true;
			cout << "Enter the y coordinate(1-10):  ";
			cin >> b;
			if (b == "1") y = 1;
			else if (b == "2") y = 2;
			else if (b == "3") y = 3;
			else if (b == "4") y = 4;
			else if (b == "5") y = 5;
			else if (b == "6") y = 6;
			else if (b == "7") y = 7;
			else if (b == "8") y = 8;
			else if (b == "9") y = 9;
			else if (b == "10") y = 10;
			else {
				cout << "\nSorry, coordinate \"" << y << "\" is not recognized...\n";
			}
		}
		p.x = x;
		p.y = y;   //inserts validated coordinates into point p
		for (int i = 0; i < shotCount; i++) {
			if (p == shots[i]) {
				cout << "You already tried that shot...\n\n";
				alreadyShot = true;
			}
		}
	}
	shots[shotCount] = p;
	shotCount++;
	return p;
}

bool hitsShip(point shot, ship s[], int size) {
	for (int i = 0; i < size; i++) {
		if (s[i].containsPoint(shot)) {
			cout << "\nDirect Hit!\n\n";
			hits[hitCount] = shot;
			hitCount++;
			s[i].bumpHitCount();
			if (!s[i].isAfloat()) {
				cout << "\n   You sunk my " << s[i].getName() << "!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			}
			return true;
		}
	}
	misses[missCount] = shot;
	missCount++;
	return false;
}


};









