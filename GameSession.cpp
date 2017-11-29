#include "GameSession.h"

GameSession::GameSession(Board* board, Visual* vis, Player* p1, Player* p2):
        board(board), vis(vis) ,player1(p1), player2(p2) {}

GameSession::~GameSession() {
};
void GameSession::playRound() {
	bool xplayed;
	//  the loop continue when x or o had a turn
	do {
		vis->printBoard();
		cout << "X its your move." << endl;
		xplayed = player1->doMove();
		vis->printBoard();
		cout << "O its your move." << endl;
	} while ((player2->doMove()) || (xplayed));
	finalCountdown(board);
}

void GameSession::finalCountdown(Board* b) {
    int white = 0;
    int black = 0;
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if (b->check(i, j) == BLACK)
                black++;
            if (b->check(i, j) == WHITE)
                white++;
        }
    }
    if (black > white)
        cout << " Player 1 (black) won! thank you for playing." <<endl;
    if (black < white)
        cout << " Player 2 (white) won! thank you for playing." <<endl;
    if (black == white)
        cout << "a draw! thank you for playing" <<endl;
}
