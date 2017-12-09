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
    void handleClient(int clientSocket, int clientSocket2);
    int calc(int arg1, const char op, int arg2) const;
};


#endif //EX4_SERVER_H
