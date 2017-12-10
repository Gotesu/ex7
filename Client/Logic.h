#ifndef LOGIC_H
#define LOGIC_H

#include "Board.h"
#include <vector>

#include "Move.h"
/********************
 * class Logic is the "interface" that is incharge
 * of the telling the player the legitimate moves.
 ****************************/
class Logic {
public:
  //constructor.
  Logic() {};
  //destroyer.
  virtual ~Logic(){};
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
  virtual Move* checkAction(Board& board, Side s, int i, int j) = 0;
    /****************
 * Function name: allowedActions
 * @param b board
 * @param s side
 * @return a Move* vector with possible moves.
     */
  virtual vector<Move*> allowedActions(Board& b, Side s) = 0;
};


#endif //LOGIC_H
