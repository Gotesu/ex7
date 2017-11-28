/*
 * Ouriel Gotesdyner
 * gotesdo
 * 305554834
 */

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "Board.h"
#include <vector>

#include "Move.h"
/***********************
 * class Player is an "interface" of player types.
 ************************/
class Player {
public:
    //constructor.
    Player(Side s);
    /***********************
     * doMove
     * @param options Move* vector with possible options to move.
     * @return the chosen Move to make a move to.
     */
    virtual Move* doMove(const vector<Move*> &options){};
    //destroyer
    virtual ~Player() {};

protected:
    Side s;
};


#endif //EX2_PLAYER_H
