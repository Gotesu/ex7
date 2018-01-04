#ifndef JOINCOMMAND_H_
#define JOINCOMMAND_H_

#include "MenuCommand.h"

class JoinCommand: public MenuCommand {
public:
    /*******************
 * Function name: execute
 * @param socket - the client socket number
 * @param gameName - a string with name of a game
 * The function tries to find the game in the map (and remove),
 * if succeeds sends back "OK", else sends back "error".
     *******************/
	virtual void execute(int socket2, string gameName);
private:
    /*******************
	* Function name: playGame
	* @param client1Socket first client port
	* @param client2Socket second client port
	* function Operation: handles a game between clients.
	 *******************/
	void playGame(int client1Socket, int client2Socket);
};

#endif /* JOINCOMMAND_H_ */
