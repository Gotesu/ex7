
#include "RemotePlayer.h"
#include <stdio.h>
#include <stdlib.h>
#define INSIZE 255
RemotePlayer::RemotePlayer(Logic& l, Board& b, Side s, RemoteConnection& rc):rc(rc) ,Player(l, b, s) {}

RemotePlayer::~RemotePlayer() {
	delete last;
}

void RemotePlayer::upload(Move* choice) {
	char send[INSIZE] = {0};
	if (choice == NULL) {
		send[0] = 'N';
		send[1] = 'o';
		send[2] = 'M';
		send[3] = 'o';
		send[4] = 'v';
		send[5] = 'e';
		rc.sendInfo(send);
		return;
	}
    char send1[255] = {'p','l','a','y',' '};
	strcpy(send,moveToChar(choice, send));
    strcat(send1, send);
	rc.sendInfo(send1);
}

Move* RemotePlayer::download() {
	char move[INSIZE] = {0};
	try {
        rc.getInfo(move);
	} catch(exception e) {
		throw "Download failed";
	}
	if ((strcmp(move, "NoMove") == 0) || (strcmp(move, "End") == 0))
		return NULL;
	int row, col;
    string first,second;
    istringstream iss(move);
    iss >> first;
    iss >> second;
  return l.checkAction(b, s, atoi(first.c_str()), atoi(second.c_str()));
}

void RemotePlayer::disconnect() {
	char send[INSIZE] = {0};
	send[0] = 'E';
	send[1] = 'n';
	send[2] = 'd';
	rc.sendInfo(send);
}

bool RemotePlayer::doMove() {
	// free last move
	delete last;
	cout << "Its " << sign() << " turn." << endl;
  cout << "Waiting for " << sign() << "'s move..." << endl;
	Move *choice = download();
	// check if had a possible move
	if (choice == NULL)
	{
		cout << "No possible moves, turn pass" << endl;
		last = choice;
		return false;
	} else {
		// change the board with the given move
		b.update(s, choice);
		// print the chosen move
		cout << sign() << " played ";
		choice->pMove();
		cout << endl;
	}
	last = choice;
	return true;
}

char *RemotePlayer::moveToChar(Move* move, char* dst) {
    ostringstream rowStr;
    rowStr << move->getR();
    ostringstream colStr;
    colStr << move->getC();
    strcat(dst,rowStr.str().c_str());
    strcat (dst, ", ");
    strcat (dst, colStr.str().c_str());
	return dst;
}

int RemotePlayer::charToInt(char *info) {
	return 0;
}
