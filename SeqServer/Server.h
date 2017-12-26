//
// Created by gotesu on 11/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>


class Server {
public:
    /**********************
 * constructor
 * @param port the number for the port
     *********************/
    Server(int port);
    /*******************
 * Function name: start
 * function Operation: Starts the connection and waits for two clients.
     *******************/
    void start();
    /*******************
* Function name: stop
* function Operation: Close the servere.
 *******************/
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    /*******************
* Function name: handleClients
* @param clientSocket first client port
* @param clientSocket2 second client port
* function Operation: Exchange move between clients.
 *******************/
    void handleClients(int clientSocket, int clientSocket2);
 /*******************
 * Function name: endGame
 * @param input the client input.
 * function Operation: check if client send "End", and if so end the connection with the clients.
  *******************/
    bool endGame(char* input);
};

#endif //SERVER_SERVER_H
