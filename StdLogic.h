
#ifndef EX2_STDLOGIC_H
#define EX2_STDLOGIC_H
#include <vector>
#include "Board.h"
#include "Logic.h"
#include "Move.h"
/***************************
 * class StdLogic
 * this class acts as the game rules for a GameSession, notifying which
 * moves are legitimate.
 ***************************/
class StdLogic: public Logic {
public:
    StdLogic();
    /********************
     * Function name : allowedActions
     * @param b the board.
     * @param s the relevant side who wants to make a move.
     * @return a vector of the optional moves the player has.
     * Operation: the function checks for possible moves according the
     * standard logic of recursi which mean that a player can put
     * his piece only by skipping over his opponent piece in a line
     * from his piece to an empty slot.
     */
    std::vector<Move*> allowedActions(Board* b, Side s);

private:
    /***********************
     * mapPositions
     * @param b board
     * @param s side
     * @return vector of Moves.
     * Operation: maps the whole board and make a vector of all the pieces of
     * the current player.
     */
    std::vector<Move*> mapPositions(Board* b, Side s);
    /*********************
     * Function name: findPossibility
     * @param p Move of origin
     * @param b board
     * @param s side
     * @param c this parameter is used to determine to which direction possibilities
     * will be searched.
     * @return a possible Move to move to if there is one, NULL otherwise.
     * Operation: according to the wanted direction the function will go in a straight
     * line from the Move of origin and return a possible Move to move to in that direction
     * in case there is one.
     ************************/
    Move* findPossibility(Move* p, Board* b, Side s, char c);
    /***************************8
     * Function name: isANewOne
     * @param vec vector of Moves to check
     * @param p suspect Move
     * @return if Move is new to the vector
     * Operation : iterates over the vector to check if Move is already there.
     */
    bool isANewOne(vector<Move*> &vec, Move* p);
=======
#include "Point.h"
#include "Logic.h"
/***************************
 * class StdLogic
 * this class acts as the game rules for a GameSession, notifying which
 * moves are legitimate.
 ***************************/
class StdLogic: public Logic {
public:
    StdLogic();
    /********************
     * Function name : allowedActions
     * @param b the board.
     * @param s the relevant side who wants to make a move.
     * @return a vector of the optional moves the player has.
     * Operation: the function checks for possible moves according the
     * standard logic of recursi which mean that a player can put
     * his piece only by skipping over his opponent piece in a line
     * from his piece to an empty slot.
     */
    std::vector<Point*> allowedActions(Board* b, Side s);

private:
    /***********************
     * mapPositions
     * @param b board
     * @param s side
     * @return vector of points.
     * Operation: maps the whole board and make a vector of all the pieces of
     * the current player.
     */
    std::vector<Point*> mapPositions(Board* b, Side s);
    /*********************
     * Function name: findPossibility
     * @param p point of origin
     * @param b board
     * @param s side
     * @param c this parameter is used to determine to which direction possibilities
     * will be searched.
     * @return a possible point to move to if there is one, NULL otherwise.
     * Operation: according to the wanted direction the function will go in a straight
     * line from the point of origin and return a possible point to move to in that direction
     * in case there is one.
     ************************/
    Point* findPossibility(Point* p, Board* b, Side s, char c);
    /***************************8
     * Function name: isANewOne
     * @param vec vector of points to check
     * @param p suspect point
     * @return if point is new to the vector
     * Operation : iterates over the vector to check if point is already there.
     */
    bool isANewOne(vector<Point*> &vec, Point* p);
>>>>>>> branch 'master' of https://github.com/Jed-El/ex3
};


#endif //EX2_STDLOGIC_H
