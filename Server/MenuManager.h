#ifndef MENUMANAGER_H_
#define MENUMANAGER_H_

#include <map>
#include <vector>
#include <set>
#include "MenuCommand.h"

struct gameSet {
	pthread_t thread;
	int clientSocket1;
	int clientSocket2;
};

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
	bool isWaiting(int socket);
private:
    //this vector will hold the gameSets which holds info about player sockets
    //and their thread
    vector<gameSet> games;
    set<int> sockets;
	MenuManager();
	MenuManager(const MenuManager&);
	~MenuManager();
	map<string, MenuCommand *> commandsMap;
	map<string, int> gamesMap;
	static MenuManager* instance;
	static pthread_mutex_t lock;
	static pthread_mutex_t mapLock;
};

#endif /* MENUMANAGER_H_ */
