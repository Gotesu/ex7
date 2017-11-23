/*
 * Ouriel Gotesdyner
 * gotesdo
 * 305554834
 */

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "Board.h"
#include "Point.h"
#include <vector>
/***********************
 * class Player is an "interface" of player types.
 ************************/
class Player {
public:
    //constructor.
    Player(Side s);
    /***********************
     * doMove
     * @param options Point* vector with possible options to move.
     * @return the chosen point to make a move to.
     */
    virtual Point* doMove(const vector<Point*> &options){};
    //destroyer
    virtual ~Player() {};

protected:
    Side s;
};


#endif //EX2_PLAYER_H
