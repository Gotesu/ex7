#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <limits>
#include "Player.h"
#include "Logic.h"
#include "Board.h"

using namespace std;
/************************
 * class Human is a type of player that makes his move according to
 * the user's input and not automaticly (like an A.I).
 */
class Human: public Player {
public:
    /*******************
     * constructor
     * @param s side
     */
    Human(Logic& l, Board& b, Side s);
    /*****************
     * Function name: doMove
     * @param options , vector holding optional moves.
     * @return a Move of the chosen move.
     ******************/
    virtual bool doMove();
private:
	/******************************************
	* function name: checkMove
	* @param i/j - a number for row/col value.
	* @param options a Move* vector with possible moves.
	* The Output: true if the move possible, false otherwise.
	* @return a Move * for the chosen move
	******************************************/
    Move* checkMove(int i, int j, vector<Move*> options);
};


#endif //HUMAN_H
