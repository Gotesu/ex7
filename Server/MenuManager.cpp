#include "MenuManager.h"

#include "StartCommand.h"
#include "ListCommand.h"
#include "JoinCommand.h"

using namespace std;

MenuManager* MenuManager::instance = 0;
pthread_mutex_t MenuManager::lock;
pthread_mutex_t MenuManager::mapLock;

MenuManager * MenuManager::getInstance() {
	if (instance == 0) {
		pthread_mutex_lock(&lock);
		if (instance == 0) {
			instance = new MenuManager();
		}
		pthread_mutex_unlock(&lock);
	}
	return instance;
}

MenuManager::MenuManager() {
	commandsMap["start"] = new StartCommand();
	commandsMap["list_games"] = new ListCommand();
	commandsMap["join"] = new JoinCommand();
}

string MenuManager::gamesList() {
	int len = 0;
	// create a output char[]
	char output[INSIZE] = {0};
	pthread_mutex_lock(&mapLock);
	// walk over the map
	map<string, int>::iterator it;
	for (it = gamesMap.begin(); it != gamesMap.end(); it++) {
		ostringstream arg;
		// check if the output is empty
		if (len == 0)
			// if the output is empty, add the game-name to arg
			arg << it->first;
		else
			// if the output is not empty, add  before the game-name
			arg << endl << it->first;
		// check if the output has space
		if (len + arg.str().length() <= INSIZE - 1) {
			// add arg to the output
		  strcat(output, arg.str().c_str());
		  len = len + arg.str().length();
		}
	}
	pthread_mutex_unlock(&mapLock);
	return output;
}

bool MenuManager::addGame(int socket, string name) {
	bool check = false;
	pthread_mutex_lock(&mapLock);
	// check if the name key is already in the map
	map<string, int>::iterator it = gamesMap.find(name);
	if (it == gamesMap.end()) {
		// add the game to the map
		gamesMap.insert(it, make_pair(name, socket));
		sockets.insert(socket);
		check = true;
	}
	pthread_mutex_unlock(&mapLock);
	return check;
}

int MenuManager::removeGame(string name) {
	int socket = -1;
	pthread_mutex_lock(&mapLock);
	// check that the name key is in the map
	map<string, int>::iterator it = gamesMap.find(name);
	if (it != gamesMap.end()) {
		// put the socket number into "socket"
		socket = it->second;
		// remove the game from the map
		gamesMap.erase(it);
        sockets.erase(socket);
	}
	pthread_mutex_unlock(&mapLock);
	// return the socket number
	return socket;
}

void MenuManager::executeCommand(string commandStr, int socket) {
	stringstream iss(commandStr);
	string command, gameName;
	// get the command string
	iss >> command;
	if (iss)
		iss >> gameName;
	// get the command from the map
	MenuCommand *commandObj = commandsMap[command];
	// check that the command exist
	if (commandObj != NULL) {
			commandObj->execute(socket, gameName);
	} else {
		// send error message
		Message sendy;
		sendy.error(socket);
	}
}

MenuManager::~MenuManager() {
	map<string, MenuCommand *>::iterator it;
	for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
		delete it->second;
	}
}

bool MenuManager::isWaiting(int socket) {
    if (sockets.find(socket) == sockets.end())
        return false;
    return true;
}
