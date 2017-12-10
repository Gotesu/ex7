//
// Created by gotesu on 09/12/17.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H


#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

class Server {
public:
    Server(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClients(int clientSocket, int clientSocket2);
    bool endGame(string input);
};


#endif //EX4_SERVER_H