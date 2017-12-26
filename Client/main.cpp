#include <iostream>
#include "Board.h"
#include "StdGame.h"
#include "RemoteGame.h"
#include "Human.h"
#include "Computer.h"
#include "StdLogic.h"
#include "StdVisual.h"

/***********************************************
 * Remote
 * this function is used by GameCreator to handle the Remote game creation.
 */
GameSession* Remote(Player *p1, RemotePlayer *p2, Board *board, Logic *log, Visual *vis) {
    RemoteConnection rc = RemoteConnection();
    rc.connectToServer();
    // check Player1 side, and create the Players
    int side = rc.getSide();
    switch (side) {
        case 1:
            p1 = new Human(*log, *board, BLACK);
            p2 = new RemotePlayer(*log, *board, WHITE, rc);
            return new RemoteGame(board, vis, p1, p2);
        case 2:
            p1 = new Human(*log, *board, WHITE);
            p2 = new RemotePlayer(*log, *board, BLACK, rc);
            return new RemoteGame(board, vis, p1, p2);
        default:
            cout << "Error: Illegal input from server";
            return 0;
    }
}
/***********************************************
 * GameCreator
 * this function creates the game according to our user's choice
 * directly creating a local game in case of choice  1 or 2 and
 * using Remote function to handle a Remote game choice.
 *******************************************/
GameSession* GameCreator(int c) {
    Board *b = new Board(2,2);
    StdLogic *log = new StdLogic();
    StdVisual *vis = new StdVisual(b);
    Player *p1;
    Player *p2;
    switch(c) {
        case 1:
            p1 = new Human(*log, *b, BLACK);
            p2 = new Human(*log, *b, WHITE);
            return new StdGame(b, vis, p1, p2);
        case 2:
            p1 = new Human(*log, *b, BLACK);
            p2 = new Computer(*log, *b, WHITE);
            return new StdGame(b, vis, p1, p2);
        case 3:
            RemotePlayer* pr;
            return Remote(p1, pr, b, log, vis);
        default:
            cout << "Error, Illegal Choice" << endl;
    }
}

int main() {
    GameSession* game;
		int c;
		cout << "Welcome to Reversi!" << endl;
		cout << "Choose an opponent type:" << endl;
		cout << "1. a human local player" << endl;
		cout << "2. an AI player" << endl;
		cout << "3. a remote player" << endl;
        cout << "3. Connect to remote GameRoom" << endl;
		cin >> c;
    try {
    	game = GameCreator(c);
        game->playRound();
    } catch(char const* e) {
		cout << e << endl;
		return 1;
		}
    delete game;
    return 0;
}
