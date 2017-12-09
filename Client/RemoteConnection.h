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
class RemoteConnection {

public:
    RemoteConnection(const char *serverIP, int serverPort);
    void connectToServer();
    int sendExercise(int arg1);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};



#endif //EX4_REMOTECONNECTION_H
