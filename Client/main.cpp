#include <iostream>
#include "Board.h"
#include "StdGame.h"
#include "RemoteGame.h"
#include "Human.h"
#include "Computer.h"
#include "StdLogic.h"
#include "StdVisual.h"
#include "RemoteGameRoom.h"

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
 * using Remote function to handle a Remote game room.
 *******************************************/
void GameCreator(int c) {
    GameSession *game;
    Board *b;
    StdLogic *log;
    StdVisual *vis;
    Player *p1;
    Player *p2;
    switch(c) {
        case 1:
            //case human vs human
            b = new Board();
            log = new StdLogic();
            vis = new StdVisual(b);
            p1 = new Human(*log, *b, BLACK);
            p2 = new Human(*log, *b, WHITE);
            game = new StdGame(b, vis, p1, p2);
            game->playRound();
            delete game;
            break;
        case 2:
            //case human vs AI
            b = new Board();
            log = new StdLogic();
            vis = new StdVisual(b);
            p1 = new Human(*log, *b, BLACK);
            p2 = new Computer(*log, *b, WHITE);
            game = new StdGame(b, vis, p1, p2);
            game->playRound();
            delete game;
            break;
        case 3:
            //case remote game room
            try {
                RemoteGameRoom *gameRoom = new RemoteGameRoom();
                delete gameRoom;
                break;
            } catch (char const* e) {
                throw e;
            }
        default:
            cout << "Error, Illegal Choice" << endl;
    }
}

int main() {
    int c;
    cout << "Welcome to Reversi!" << endl;
    cout << "Choose an opponent type:" << endl;
    cout << "1. a human local player" << endl;
    cout << "2. an AI player" << endl;
    cout << "3. Connect to remote GameRoom" << endl;
    cin >> c;
    try {
    	GameCreator(c);
    } catch(char const* e) {
		cout << e << endl;
		return 1;
		}
    return 0;
}
