#include <stdio.h>
#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(Logic& l, Board& b, Side s, RemoteConnection& rc):rc(rc) ,Player(l, b, s) {}

void RemotePlayer::upload(Move* choice) {
	string move = choice->getR() + " " + choice->getC();
	rc.sendMove(move);
}

Move* RemotePlayer::download() {
	string move = rc.getMove();
	if ((strcmp(move.c_str(), "NoMove") == 0) || (strcmp(move.c_str(), "End") == 0))
		return NULL;
	int row, col;
  istringstream iss(move);
  iss >> row >> col;
  return l.checkAction(b, s, row, col);
}

void RemotePlayer::disconnect() {
	rc.sendMove("End");
}

char RemotePlayer::sign() const {
    switch(s) {
        case WHITE : return 'O';
        case BLACK : return 'X';
        default: return 'E';
    }
}

bool RemotePlayer::doMove() {
	// free last move
	delete last;
	cout << "Its " << sign() << " move." << endl;
	Move *choice = download();
	// check if had a possible move
	if (choice == NULL)
	{
		cout << "No possible moves, turn pass" << endl;
		last = choice;
		return false;
	} else {
		// change the board whith the given move
		b.update(s, choice);
		// print the chosen move
		cout << sign() << " played ";
		choice->pMove();
		cout << endl;
	}
	last = choice;
	return true;
}
