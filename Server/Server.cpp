//
// Created by gotesu on 11/12/17.
//
#include <cstdlib>
#include "Server.h"
#include "MenuManager.h"
#include "serverClients.h"
#include "Task.h"
#include "ThreadPool.h"

using namespace std;

#define MAX_CONNECTED_CLIENTS 2
#define THREADS_NUM 5
#define INSIZE 255

struct mainThreadsArgs{
    int serverSocket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
};

Server::Server(int port): port(port), serverSocket(0), serverThreadId(0) {
    cout << "Server running" << endl;
    running = true;
}

void Server::start() {
    mainThreadsArgs *args = new mainThreadsArgs;
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,
          sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }// Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    args->serverSocket = serverSocket;
    //opening the mainloop client acceptence thread.
    pthread_create(&serverThreadId, NULL,acceptClients,(void*)args);
    //this is our protocol for closing the server on "exit" command
    char stop[10] = {0};
    while (strcmp(stop,"exit")) {
        cin >> stop;
    }
    cout << "server shut down" << endl;
    pthread_cancel(serverThreadId);
    Server::stop();
    delete args;
}

void *Server::acceptClients(void* args) {
    //unpacking our argument struct
    mainThreadsArgs arg = *(mainThreadsArgs*) args;
    while (true) {
        // Accept a new client connection
        int clientSocket = accept(arg.serverSocket, (struct
                sockaddr *) &arg.clientAddress, &arg.clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept";
        serverClients::getInstance()->addSocket(clientSocket);
        cout << "Client (" << clientSocket << ") connected" << endl;
        Task *t = new Task(handleClient, (void *)clientSocket);
        ThreadPool::getInstance()->addTask(t);
    }
}
void *Server::handleClient(void *args) {
    char input[INSIZE] = {0};
    long clientSocket = (long) args;
    //loop is important to continue interaction with game_list requestors.
    while(true) {
        int check = read(clientSocket, input, sizeof(input));
        if (check == -1 || check == 0) {
            cout << "Error on read " << clientSocket << " disconnected" << endl;
            //removing the disfunct socket from the socket list and closing it.
            serverClients::getInstance()->removeSocket(clientSocket);
            break;
        }
        MenuManager::getInstance()->executeCommand(string(input), clientSocket);
        //clients starting games need to clear our thread so we need
        //to check if this socket is now waiting to break the loop.
        if (MenuManager::getInstance()->isWaiting(clientSocket))
            break;
    }
    return NULL;
}

void Server::stop() {
	cout << "Server closing" << endl;
	// terminate all threads
    ThreadPool::getInstance()->terminate();
	// close all sockets
  serverClients::getInstance()->exit();
	close(serverSocket);
}
