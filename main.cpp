#include <iostream>
#include <cstring>
#include "model.h"
#include "point.h"
#include "ship.h"


using namespace std;


int main() {
	ship acCarrier(5, "Carrier");
	ship battleShip(4, "Battleship");
	ship submarine(3, "Submarine");
	ship destroyer(3, "Destroyer");
	ship patrol(2, "Patrol Boat");
	ship shipFleet[5] = {acCarrier, battleShip, submarine, destroyer, patrol};
	
	ship shipFleet2[5] = {acCarrier, battleShip, submarine, destroyer, patrol};
	
	model board(10, 10);
	shipFleet[0].randomlyPlaceShip();
	for (int i = 1; i < 5; i++) {   
		bool conflict = true;
		while (conflict) {
			conflict = false;
			shipFleet[i].randomlyPlaceShip();
			for (int j = 0; j < i; j++) {
				if (shipFleet[j].hasConflictWith(shipFleet[i])) {
					conflict = true;
					break;
				}
			}
		}
	}
	
	cout << "\n]n=============================Battleship!===============================\n\n";
	
		model board1(10, 10);
	shipFleet2[0].randomlyPlaceShip();
	for (int i = 1; i < 5; i++) {   
		bool conflict = true;
		while (conflict) {
			conflict = false;
			shipFleet[i].randomlyPlaceShip();
			for (int j = 0; j < i; j++) {
				if (shipFleet[j].hasConflictWith(shipFleet[i])) {
					conflict = true;
					break;
				}
			}
		}
	}
	
    cout<<"Carrier [5 spaces]"<<endl;
	cout<<"Battleship [4 spaces]"<<endl;
	cout<<"Submarine [3 spaces]"<<endl;
	cout<<"Destroyer 3[spaces]"<<endl;
	cout<<"Patrol Boat 2[spaces]"<<endl;
	
	
	cout << "Your board:\n\n";
	
	board1.display(shipFleet2, 5);
	
	cout << "Computer board:\n\n";
	
	board.display(shipFleet, 5);
	
	
	
	cout << "\nWhich co-ordinate do you wish to attack!\n";
	bool gameOver = false;
	int flag =0;
	while (!gameOver) {
		cout << endl << endl;
		point p = board.getFiringCoordinates();
		if (!board.hitsShip(p, shipFleet, 5)) cout << "\n\nyou miss...\n\n";
		board.display(shipFleet, 5);
		if (!shipFleet[1].isAfloat()){
			flag=1;
			gameOver = true;
		} 
		else cout << "\nHave another Shot!";
		
		cout << endl << "Computer attack: Please enter co-ordinate for computer"<<endl;
		point p1 = board1.getFiringCoordinates();
		if (!board1.hitsShip(p1, shipFleet2, 5)) cout << "\n\ncomputer miss...\n\n";
		board1.display(shipFleet2, 5);
		if (!shipFleet2[1].isAfloat()){
			flag=2;
			gameOver = true;
		} 
		else cout << "\nHave another Shot!";
	}
	if(flag==1)
	cout << "\n\nYou Won!!\n\n\n";
	else{
		cout<<"\n\nComputer won\n\n"<<endl;
	}
	
	cout << "     Game Over.\n\n\n";
	
	
	
	return 0;
}








