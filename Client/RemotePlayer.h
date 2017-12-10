#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include <iostream>
#include <sstream>
#include <string.h>
#include "Player.h"
#include "RemoteConnection.h"
#include "Logic.h"
#include "Board.h"

using namespace std;
/************************
 * class RemotePlayer is a type of player that makes his move according to
 * the user's input and not automaticly (like an A.I).
 */
class RemotePlayer: public Player {
public:
    /*******************
  * constructor
     */
    RemotePlayer(Logic& l, Board& b, Side s, RemoteConnection& rc);
    /***********************
 * function name: doMove
 * @return true if the player had a possible move, false otherwise.
     */
    bool doMove();
    /***********************
 * Function name: upload
 * @param choice the last moves values.
 * Operation: this function send the last move to the server.
     */
    void upload(Move* choice);
  /***********************
 * Function name: download
 * @return a Move from the server.
 * Operation: this function get the last move from the server.
  */
    Move* download();
  /***********************
 * Function name: disconnect
 * Operation: the function send "End" to the server.
  */
    void disconnect();
	/******************************************
	* function name: sign()
	* The Output: the player sign.
	* The function operation: the function checks the player side, and return the right sign.
	******************************************/
    char sign() const;
private:
    RemoteConnection rc;
};

#endif //REMOTEPLAYER_H
