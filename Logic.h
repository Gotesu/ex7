#ifndef EX2_LOGIC_H
#define EX2_LOGIC_H

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
    Logic();
    //destroyer.
    virtual ~Logic(){};
    /****************
     * Function name: allowedActions
     * @param b board
     * @param s side
     * @return a Move* vector with possible moves.
     */
    virtual vector<Move*> allowedActions(Board* b, Side s){};
=======
#ifndef EX2_LOGIC_H
#define EX2_LOGIC_H

#include "Point.h"
#include "Board.h"
#include <vector>
/********************
 * class Logic is the "interface" that is incharge
 * of the telling the player the legitimate moves.
 ****************************/
class Logic {
public:
    //constructor.
    Logic();
    //destroyer.
    virtual ~Logic(){};
    /****************
     * Function name: allowedActions
     * @param b board
     * @param s side
     * @return a point* vector with possible moves.
     */
    virtual vector<Point*> allowedActions(Board* b, Side s){};
>>>>>>> branch 'master' of https://github.com/Jed-El/ex3
};


#endif //EX2_LOGIC_H
