#include <stdio.h>
#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(Logic& l, Board& b, Side s, RemoteConnection& rc):rc(rc) ,Player(l, b, s) {}

RemotePlayer::~RemotePlayer() {
	delete last;
}

void RemotePlayer::upload(Move* choice) {
	char send[10] = {0};
	send[0] = (char)(choice->getR() + '0');
    cout << send[0] << endl;
	send[1] = ',';
	send[2] = ' ';
	send[3] = (char)(choice->getC() + '0');
    cout << send[3] << endl;
	rc.sendMove(send);
}

Move* RemotePlayer::download() {
	char move[10] ={0};
	rc.getMove(move);
	if ((strcmp(move, "NoMove") == 0) || (strcmp(move, "End") == 0))
		return NULL;
	int row, col;
	row = (int) (move[0] - '0');
	col = (int) (move[3] - '0');
  return l.checkAction(b, s, row, col);
}

void RemotePlayer::disconnect() {
	char send[10] = {0};
	send[0] = 'E';
	send[1] = 'n';
	send[2] = 'd';
	rc.sendMove(send);
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
