#ifndef GAMESESSION_H
#define GAMESESSION_H

#include "Player.h"
#include "Visual.h"
#include "Board.h"
/****************************
 * class GameSession is the base on which we play our game
 * this class holds a board, a logic and two players and
 * manages their interactions.
 ****************************/
class GameSession {
public:
    /**********************
     * constructor
     * @param board the Board
     * @param vis the board visual.
     * @param p1
     * @param p2
     *********************/
    GameSession(Board* board, Visual* vis, Player* p1, Player* p2);
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
    Board* board;
    Visual* vis;
    Player *player1;
    Player *player2;
};

#endif //GAMESESSION_H
