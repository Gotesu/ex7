#ifndef STARTCOMMAND_H_
#define STARTCOMMAND_H_

#include "MenuCommand.h"

class StartCommand: public MenuCommand {
public:
    /*******************
 * Function name: execute
 * @param socket - the client socket number
 * @param gameName - a string with name of a game
 * The function tries to add the game to the map, if succeeds sends back "OK",
 * else sends back "error".
     *******************/
	virtual void execute(int socket, string gameName) {
		Message sendy;
		// add game to map, and check if the name isn't taken
		if (!MenuManager::getInstance()->addGame(socket, gameName)) {
			// if the name already taken - send an error massage to client
			sendy.error(socket);
		} else {
			// send the client a massage that the command accepted
			sendy.accept(socket);
		}
	}
};

#endif /* STARTCOMMAND_H_ */
