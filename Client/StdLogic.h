#ifndef STDLOGIC_H
#define STDLOGIC_H
#include <vector>
#include "Board.h"
#include "Logic.h"
#include "Move.h"
/***************************
 * class StdLogic
 * this class acts as the game rules for a GameSession, notifying which
 * moves are legitimate.
 ***************************/
class StdLogic: public Logic {
public:
    StdLogic();
    /********************
	 * Function name : checkAction
	 * @param b the board.
	 * @param s the relevant side who wants to make a move.
	 * @param i,j a given row & column values to the move.
	 * @return a Move object if (i,j) is legal, NULL otherwise.
	 * Operation: the function checks given move according the
	 * standard logic of reversi which mean that a player can put
	 * his piece only by skipping over his opponent piece in a line
	 * from his piece to an empty slot.
     */
    Move* checkAction(Board& board, Side s, int i, int j);
    /********************
	 * Function name : allowedActions
	 * @param b the board.
	 * @param s the relevant side who wants to make a move.
	 * @return a vector of the optional moves the player has.
	 * Operation: the function checks every move using checkAction function,
	 * and collects all the possible moves into a vector.
     */
    vector<Move*> allowedActions(Board& b, Side s);
};


#endif //STDLOGIC_H
