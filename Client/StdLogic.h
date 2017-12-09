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
     * Function name : allowedActions
     * @param b the board.
     * @param s the relevant side who wants to make a move.
     * @return a vector of the optional moves the player has.
     * Operation: the function checks for possible moves according the
     * standard logic of recursi which mean that a player can put
     * his piece only by skipping over his opponent piece in a line
     * from his piece to an empty slot.
     */
    vector<Move*> allowedActions(Board& b, Side s);
};


#endif //STDLOGIC_H
