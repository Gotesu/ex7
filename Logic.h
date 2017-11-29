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
    /****************
 * Function name: allowedActions
 * @param b board
 * @param s side
 * @return a Move* vector with possible moves.
     */
  virtual vector<Move*> allowedActions(Board& b, Side s) = 0;
};


#endif //LOGIC_H
