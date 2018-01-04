#ifndef MENUMANAGER_H_
#define MENUMANAGER_H_

#include <map>
#include "MenuCommand.h"

class MenuManager {
public:
	static MenuManager * getInstance();
	void executeCommand(string commandStr, int socket);
    /*******************
 * Function name: execute
 * @param socket - the client socket number
 * @param gameName - a string with name of a game
 * The function tries to add the game to the map, if succeeds sends back "OK",
 * else sends back "error".
     *******************/
	string gamesList();
    /*******************
 * Function name: addGame
 * @param socket - the client socket number
 * @param name - a string with name of a game
 * The function tries to add the game to the map, if succeeds return true, else return false.
     *******************/
	bool addGame(int socket, string name);
    /*******************
 * Function name: removeGame
 * @param socket - the client socket number
 * The function tries to find the game in the map and remove it,
 * if succeeds return the other player socket, else return -1.
     *******************/
	int removeGame(string name);
    /*******************
 * Function name: checkServer
 * The function return the serverRun parameter, that is false if the server got an exit command
 * 	and true otherwise.
     *******************/
	bool checkServer() {return serverRun;}
    /*******************
 * Function name: exit
 * The function change serverRun to false, which mean the server got an exit command.
 * Then it's closes all the waiting games from the map.
     *******************/
	void exit();
private:
	MenuManager();
	MenuManager(const MenuManager&);
	~MenuManager();
	map<string, MenuCommand *> commandsMap;
	map<string, int> gamesMap;
	static MenuManager* instance;
	static pthread_mutex_t lock;
	static pthread_mutex_t mapLock;
	bool serverRun;
};

#endif /* MENUMANAGER_H_ */
