#include <stdio.h>
#include <iostream>
#include "Board.h"
#include "StdGame.h"
#include "RemoteGame.h"
#include "RemoteConnection.h"
#include "Human.h"
#include "Computer.h"
#include "RemotePlayer.h"
#include "StdLogic.h"
#include "StdVisual.h"

int main() {
    Board* board;
    Visual* vis;
    Logic* log;
    Player * p1;
    Player * p2;
    GameSession* game;
		int c;
		cout << "Welcome to Reversi!" << endl;
		cout << "Choose an opponent type:" << endl;
		cout << "1. a human local player" << endl;
		cout << "2. an AI player" << endl;
		cout << "3. a remote player" << endl;
		cin >> c;
    try {
    		board = new Board();
        vis = new StdVisual(board);
        log = new StdLogic();
        if (c == 1) {
						p1 = new Human(*log, *board, BLACK);
			      p2 = new Human(*log, *board, WHITE);
			      game = new StdGame(board, vis, p1, p2);
        } else if (c == 2) {
						p1 = new Human(*log, *board, BLACK);
			      p2 = new Computer(*log, *board, WHITE);
			      game = new StdGame(board, vis, p1, p2);
        } else if (c == 3) {
						RemoteConnection rc = RemoteConnection();
						rc.connectToServer();
						// check Player1 side, and create the Players
						switch (rc.getSide()) {
							case 1:
								p1 = new Human(*log, *board, BLACK);
								p2 = new RemotePlayer(*log, *board, WHITE, rc);
								break;
							case 2:
								p1 = new Human(*log, *board, WHITE);
								p2 = new RemotePlayer(*log, *board, BLACK, rc);
								break;
							default:
								cout << "Error: Illegal input from server";
								return 0;
						}
						game = new RemoteGame(board, vis, p1, (RemotePlayer*) p2);
        } else {
						cout << "Error: Illegal choice";
						return 0;
        		}
        game->playRound();
    } catch(exception& e) {
		cout << "Error";
		return 1;
		}
    delete board;
    delete vis;
    delete log;
    delete p1;
    delete p2;
    delete game;
    return 0;
}
