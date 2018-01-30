#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <map>
#include <string>
#include "GameCommand.h"

class GameManager {
public:
	static GameManager * getInstance();
	bool executeCommand(string commandStr, int socket = 0, int socket2 = 0);
private:
	GameManager();
	GameManager(const GameManager&);
	~GameManager();
	map<string, GameCommand *> commandsMap;
	static GameManager* instance;
	static pthread_mutex_t lock;
};

#endif /* GAMEMANAGER_H_ */
