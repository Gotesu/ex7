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
 * doMove
 * @return true if the player had a possible move, false otherwise.
     */
    virtual bool doMove() = 0;
    //destroyer
    virtual ~Player() {};

protected:
    Side s;
    Logic& l;
    Board& b;
};


#endif //PLAYER_H
