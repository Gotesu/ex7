#include "GameManager.h"
#include <iostream>
#include <sstream>
#include "EndCommand.h"
#include "PlayCommand.h"
#include "NoMoveCommand.h"
#include "Message.h"

#define INSIZE 255

using namespace std;

GameManager* GameManager::instance = 0;
pthread_mutex_t GameManager::lock;

GameManager * GameManager::getInstance() {
	if (instance == 0) {
		pthread_mutex_lock(&lock);
		if (instance == 0) {
			instance = new GameManager();
		}
		pthread_mutex_unlock(&lock);
	}
	return instance;
}

GameManager::GameManager() {
	serverRun = true;
	commandsMap["End"] = new EndCommand();
	commandsMap["play"] = new PlayCommand();
	commandsMap["NoMove"] = new NoMoveCommand();
}

void GameManager::executeCommand(string commandStr, int socket, int socket2) {
	istringstream iss(commandStr);
	string command, gameName;
	// get the command string
	iss >> command;
	// create arguments vector
	vector<string> args;
	while (iss) {
		string arg;
		iss >> arg;
		args.push_back(arg);
	}
	// check if an arguments were given
	if (args.size() == 0)
		// if not - push the command string as argument
		args.push_back(command);
	// get the command from the map
	GameCommand *commandObj = commandsMap[command];
	commandObj->execute(socket, args, socket2);
}

GameManager::~GameManager() {
	map<string, GameCommand *>::iterator it;
	for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
		delete it->second;
	}
}
