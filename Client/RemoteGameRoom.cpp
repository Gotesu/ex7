//
// Created by gotesu on 31/12/17.
//
#include "RemoteGameRoom.h"
#include "Board.h"
#include "Logic.h"
#include "StdLogic.h"
#include "StdVisual.h"
#include "Human.h"
#include "RemotePlayer.h"
#include "RemoteGame.h"
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
             << "1. list_games" << endl << "2. start <game-name>" << endl
             << "3. join <game-name>" << endl;
        cout << "please enter a command string" << endl;
        getline(cin, input);
        istringstream iss(input);
        iss >> command;
        //sending the reqeust to server.
        rc->sendInfo(const_cast<char *>(input.c_str()));
        cout << "waiting patiently for server to attend your request" << endl;
        //making a validity check that our server confirms the request.
        if (!validityCheck()) {
            continue;
        }
        //case getlist was chosen
        if (strcmp(command.c_str(), list) == 0)
            getList();
        //case join
        else if (strcmp(command.c_str(), join) == 0) {
            startGame();
            stopped = true;
        }
        //case start was chosen
        else if (strcmp(command.c_str(), start) == 0) {
            startGame();
            stopped = true;
        }
        //illegal choice.
        else
            cout << "invalid choice, please choose again" << endl;
    }
}

void RemoteGameRoom::getList() {
    char list[INSIZE];
    try {
        rc->getInfo(list);
        cout << "The current games waiting:" << endl << list << endl;
    } catch(const char* c) {
        cout << c << endl;
    }
}

void RemoteGameRoom::startGame() {
    Board* board = new Board();
    Logic* log = new StdLogic();
    Visual *vis = new StdVisual(board);
    rc->setSide();
    Side eSide;
    int side = rc->getSide();
    if (side == 1) {
        eSide = BLACK;
    }else if (side == 2){
        eSide = WHITE;
    }
    RemoteGame* game;
    Player* p1 = new Human(*log, *board, eSide);
    RemotePlayer* p2 = new RemotePlayer(*log, *board, (Side) -eSide, *rc);
    game = new RemoteGame(board, vis, p1, p2);
    game->playRound();
    rc->shutDown();
}


bool RemoteGameRoom::validityCheck() {
    char input[INSIZE];
    char* acc = "accept";
    char* err = "error";
    rc->getInfo(input);
    if (!strcmp(input,acc)) {
        cout << "request accepted by server\n";
        return true;
    }
    if (!strcmp(input,err)) {
        cout << "request denied by server\n";
        return false;
    }
}
