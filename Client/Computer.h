#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include "Player.h"
#include "Logic.h"
#include "Board.h"

using namespace std;
/************************
* class Computer is a type of player that makes his move according to
* the user's input and not automaticly (like an A.I).
***********************/
class Computer: public Player {
public:
	  /*******************
	 * constructor
	 * @param l Logic
	 * @param b Board
	 * @param s side
	 ***********************/
    Computer(Logic& l, Board& b, Side s);
	//destructor
    ~Computer();
    /***********************
  * function name: doMove
  * @return true if the player had a possible move, false otherwise.
  * Note: the function change this->last value, to the current Move.
     ***********************/
    bool doMove();
private:
	/*****************
	* Function name: checkNext
	* @param move - a Move pointer.
	* @return the maximum number of blocks the enemy could change after the given move.
	******************/
    int checkNext(Move * move) const;
	/*****************
	* Function name: moveValue
	* @param move - a Move pointer.
	* go-over every direction, and sum the number of blocks that will change.
	* @return the number of blocks that will change after the move.
	 ******************/
    int moveValue(Move * move) const;
};

#endif //COMPUTER_H
