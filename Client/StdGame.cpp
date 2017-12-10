#include "StdGame.h"

StdGame::StdGame(Board* board, Visual* vis, Player* p1, Player* p2):
	GameSession(board, vis, p1, p2) {}

StdGame::~StdGame() {}

void StdGame::playRound() {
	//  the loop continue when x or o had a turn
	do {
		vis->printBoard();
		player1->doMove();
		vis->printBoard();
		player2->doMove();
	} while ((player1->lastMove() != NULL) || (player2->lastMove() != NULL));
	finalCountdown(board);
}

void StdGame::finalCountdown(Board* b) {
    int white = 0;
    int black = 0;
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if (b->get(i, j) == BLACK)
                black++;
            if (b->get(i, j) == WHITE)
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
