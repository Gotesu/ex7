#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <map>
#include <string>
#include "GameCommand.h"

class GameManager {
public:
	static GameManager * getInstance();
	void executeCommand(string commandStr, int socket, int socket2 = 0);
    /*******************
 * Function name: checkServer
 * The function return the serverRun parameter, that is false if the server got an exit command
 * 	and true otherwise.
     *******************/
	bool checkServer() {return serverRun;}
    /*******************
 * Function name: exit
 * The function change serverRun to false, which mean the server got an exit command.
     *******************/
	void exit() {serverRun = false;}
private:
	GameManager();
	GameManager(const GameManager&);
	~GameManager();
	map<string, GameCommand *> commandsMap;
	bool serverRun;
	static GameManager* instance;
	static pthread_mutex_t lock;
};

#endif /* GAMEMANAGER_H_ */
