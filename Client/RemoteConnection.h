//
// Created by gotesu on 09/12/17.
//

#ifndef EX4_REMOTECONNECTION_H
#define EX4_REMOTECONNECTION_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "Move.h"
#include <fstream>
class RemoteConnection {

public:
    RemoteConnection();
    void connectToServer();
    int getSide();
    void sendMove(char* move);
    void getMove(char * input);
private:
    void setSide();
    int side;
    const char *serverIP;
    int serverPort;
    int clientSocket;
    int stringToInt(string input);
};



#endif //EX4_REMOTECONNECTION_H
