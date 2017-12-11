#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Logic.h"
#include "Board.h"
/***********************
 * class Player is an "interface" of player types.
 ************************/
class Player {
public:
	  /*******************
	 * constructor
	 * @param l Logic
	 * @param b Board
	 * @param s side
	 ***********************/
    Player(Logic& l, Board& b, Side s): s(s), l(l), b(b), last(NULL) {};
    /***********************
  * function name: doMove
  * @return true if the player had a possible move, false otherwise.
  * Note: the function change this->last value, to the current Move.
     ***********************/
    virtual bool doMove() = 0;
	/******************************************
	* function name: sign()
	* The Output: the player sign.
	* The function operation: the function checks the player side, and return the right sign.
	******************************************/
    char sign() const;
	/***********************
	* function name: lastMove
	* @return the last move.
	* This is a getter function for last.
	***********************/
    Move* lastMove();
	//destructor
    virtual ~Player() {};
protected:
    Side s;
    Logic& l;
    Board& b;
    Move* last;
};


#endif //PLAYER_H
