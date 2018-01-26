//
// Created by gotesu on 11/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <pthread.h>
#include "ThreadPool.h"

using namespace std;

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
    pthread_t serverThreadId;
    vector<pthread_t>* threads;
    bool running;
/**************************
 * acceptClients
 * @param args
 * this function is a simple main thread that listens
 * to client connections and opens a thread after accept
 */
    static void* acceptClients(void* args);
/**************************
 * handleClient
 * @param args
 * this is the function that asks the client for input
 * and directs him according to the command he sent
 */
    static void* handleClient(void* args);
};
#endif //SERVER_SERVER_H
