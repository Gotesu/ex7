#include "Computer.h"
#include <stdio.h>

Computer::Computer(Logic& l, Board& b, Side s):Player(l, b, s) {}

Computer::~Computer() {
	delete last;
}

int Computer::moveValue(Move * move) const {
	int i, cunt = 1;
	// go-over every direction, and sum the number of blocks that will change
	for (i = 0; i < 8; i++) {
		cunt = cunt + move->getDir(i);
	}
	return cunt;
}

int Computer::checkNext(Move * move) const {
	Board bnext(b);
	vector<Move*> enmopts;
	//update the copied board
	bnext.update(s, move);
	// check for enemy moves
	enmopts = l.allowedActions(bnext, (Side) -s);
	// if no possible move was found - return 0
	if (enmopts.size() == 0) {
		return 0;
	}
	int max = 0, current = 0;
	// go over every possible enemy move
	for (int i = 0; i < enmopts.size(); i++) {
		// check how many blocks will change
		current = moveValue(enmopts[i]);
		// check if the value is bigger than max value
		if (current > max)
			max = current;
		// free memory
		delete enmopts[i];
	}
	return max;
}

bool Computer::doMove() {
	// free last move
	delete last;
	cout << "Its " << sign() << " move." << endl;
	vector<Move*> options;
	// check possible moves
	options = l.allowedActions(b, s);
	if (options.size() == 0) {
		cout << "No possible moves, turn pass" << endl;
		last = NULL;
		return false;
	}
	int i, min, current;
	Move * best = NULL;
	// go over every possible move
	for (i = 0; i < options.size(); i++) {
		// check its value to the enemy
		current = checkNext(options[i]) - moveValue(options[i]);
		// check if this is the first move, or if its value smaller than min
		if ((best == NULL) || (current < min)) {
			// save the current move as the new best, and its value in min
			min = current;
			best = options[i];
		}
	}
	// change the board whith the chosen move
	b.update(s, best);
	// print the chosen move
	cout << sign() << " played ";
	best->pMove();
	cout << endl;
	// free memory - delete all the other moves
	for (i = 0; i < options.size(); i++)
		if (!options[i]->isEqual(best))
			delete options[i];
	// save the chosen move
	last = best;
	return true;
}
