#include <iostream>
#include "GameSession.h"
#include "Human.h"
#include "Computer.h"
#include "StdLogic.h"
#include "StdVisual.h"

int main() {
	Board* b1;
	Visual* vis;
	Logic* log;
	Player* p1;
	Player* p2;
	GameSession* game;
	char c;
	// ask the user about player O
	do{
		cout << "Player X is Human. What about Player O?" << endl << "Enter 'H' for Human, or 'C' for Computer: ";
		cin >> c;
	} while ((c != 'C') && (c != 'H'));
	try {
		b1 = new Board();
		vis = new StdVisual(b1);
		log = new StdLogic();
		p1 = new Human(*log, *b1, BLACK);
		// check answer for player O
		if (c == 'C')
			p2 = new Computer(*log, *b1, WHITE);
		else
			p2 = new Human(*log, *b1, WHITE);
		game = new GameSession(b1, vis, p1, p2);
	} catch(exception e1) {
		cout << "Error :Cannot allocate memory";
		return 0;
	}
	// run the game
	game->playRound();
	delete b1;
	delete vis;
	delete log;
	delete p1;
	delete p2;
	delete game;
	return 0;
}
