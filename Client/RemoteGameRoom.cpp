//
// Created by gotesu on 31/12/17.
//

#include "RemoteGameRoom.h"
#include <sstream>
#define INSIZE 255
using namespace std;

RemoteGameRoom::RemoteGameRoom() {
    stopped = false;
    this->rc = new RemoteConnection();
    try {
        rc->connectToServer();
    } catch(char const* e) {
        throw e;
    }
    string input;
    string command;
    char* list = "list_games";
    char* join = "join";
    char* start = "start";
    cout << "Welcome to Remote Game Room" << endl;
    //to avoid getting \n instead our input in getline.
    cin.ignore();
    while (!stopped) {
        cout << "your options are:" << endl
             << "1. list_games" << endl << "2. start <name> game" << endl
             << "3. join <name> game" << endl;
        getline(cin, input);
        istringstream iss(input);
        iss >> command;
        if (strcmp(command.c_str(), list) == 0)
            getList(input.c_str());
        else if (strcmp(command.c_str(), join) == 0) {
            joinGame(input.c_str());
            stopped = true;
        }
        else if (strcmp(command.c_str(), start) == 0) {
            startGame(input.c_str());
            stopped = true;
        }
        else
            cout << "invalid choice, please choose again" << endl;
    }
}

void RemoteGameRoom::getList(const char *request) {
    char list[INSIZE];
    try {
        rc->sendInfo(const_cast<char *>(request));
        rc->getInfo(list);
        cout << list << endl;
    } catch(const char* c) {
        cout << c << endl;
    }
}

void RemoteGameRoom::startGame(const char *request) {
    cout << "you're in start" << endl;
}

void RemoteGameRoom::joinGame(const char *request) {
    cout << "you're in join" << endl;
}
