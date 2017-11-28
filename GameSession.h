#ifndef EX2_GAMESESSION_H
#define EX2_GAMESESSION_H

#include "Board.h"
#include "StdLogic.h"
#include "Player.h"
#include "Visual.h"
/****************************
 * class GameSession is the base on which we play our game
 * this class holds a board, a logic and two players and
 * manages their interactions.
 ****************************/
class GameSession {
public:
    /**********************
     * constructor
     * @param board
     * @param logic
     * @param vis the board visual.
     * @param p1
     * @param p2
     *********************/
    GameSession(Board* board, Visual* vis, Logic* logic, Player* p1, Player* p2);
    /********************
     * destroyer is needed because we have object Moveer members which
     * GameSession is composed of.
     ***********************/
    ~GameSession();
    /*******************
     * Function name: playRound
     * function Operation: this function is the function that actually
     * coordinates a round of a game, using the board, the logic to know what
     * are the possible moves and asks the players to pick their move in turn.
     *******************/
    void playRound();
private:
    /*********************
     * Function name: finalCountdown
     * @param b the board.
     * Operation: this function is called when no player has legal moves
     * which means the game ended. and counts and annouces who is the winner.
     */
    void finalCountdown(Board* b);
    /***********************
     * Function name: updateBoard
     * @param s the side
     * @param choice the Move of choice
     * Operation: this function changes the board according
     * the player's chosen move.
     */
    void updateBoard(Side s, Move* choice);
    Board *board;
    Visual* vis;
    Logic *logic;
    Player *player1;
    Player *player2;
};

#endif //EX2_GAMESESSION_H
