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
* Function name: playGame
* @param clientSocket first client port
* @param clientSocket2 second client port
* function Operation: handles a game between clients.
 *******************/
    static void* playGame(void* twoClients);
 /*******************
 * Function name: endGame
 * @param input the client input.
 * function Operation: check if client send "End", and if so end the connection with the clients.
  *******************/
    static bool endGame(char* input);
/**************************
 * handleClient
 * @param args
 * this function is a simple thread that accpets a client connection and directing the client to
 * an execution manager.
 */
    static void* handleClient(void* args);
};
#endif //SERVER_SERVER_H
