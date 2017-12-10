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
    //constructor.
    Player(Logic& l, Board& b, Side s): s(s), l(l), b(b) {};
    /***********************
 * function name: doMove
 * @return true if the player had a possible move, false otherwise.
     */
    virtual bool doMove() = 0;
    //destroyer
    ~Player() {delete last;};
	/******************************************
	* function name: sign()
	* The Output: the player sign.
	* The function operation: the function checks the player side, and return the right sign.
	******************************************/
    virtual char sign() const = 0;
    /***********************
 * function name: lastMove
 * @return the last move.
 * This is a getter function for last.
     */
    Move* lastMove() {return last;};
protected:
    Side s;
    Logic& l;
    Board& b;
    Move* last = NULL;
};


#endif //PLAYER_H
