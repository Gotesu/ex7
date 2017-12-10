#ifndef REMOTEGAME_H
#define REMOTEGAME_H

#include "GameSession.h"
#include "Player.h"
#include "RemotePlayer.h"
#include "Visual.h"
#include "Board.h"
/****************************
 * class RemoteGame is the base on which we play our game
 * this class holds a board, a logic and two players and
 * manages their interactions.
 ****************************/
class RemoteGame: public GameSession {
public:
    /**********************
     * constructorgic
     * @param board the Board
     * @param vis the board visual.
     * @param p1 Player
     * @param p2 RemotePlayer
     *********************/
		RemoteGame(Board* board, Visual* vis, Player* p1, RemotePlayer* p2);
    /********************
     * destroyer is needed because we have object Moveer members which
     * RemoteGame is composed of.
     ***********************/
    ~RemoteGame();
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
};

#endif //REMOTEGAME_H
