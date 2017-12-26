#include "RemoteGame.h"

RemoteGame::RemoteGame(Board* board, Visual* vis, Player* p1, RemotePlayer* p2):
	GameSession(board, vis, p1, p2) {};

RemoteGame::~RemoteGame() {}

void RemoteGame::playRound() {
	// check if the RemotePlayer (Player2) is the first
	if (player2->sign() == 'X') {
			vis->printBoard();
			// Player 2 play a turn
			player2->doMove();
	}
	//  the loop continue when x or o had a turn
	do {
		vis->printBoard();
		// Player 1 play a turn
		player1->doMove();
		// RemotePlayer (Player2) get an update
		((RemotePlayer*)player2)->upload(player1->lastMove());
		vis->printBoard();
		// Player 2 play a turn
		player2->doMove();
	} while ((player1->lastMove() != NULL) || (player2->lastMove() != NULL));
	// RemotePlayer (Player2) disconnect from the server
	((RemotePlayer*)player2)->disconnect();
	finalCountdown(board);
}

void RemoteGame::finalCountdown(Board* b) {
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
