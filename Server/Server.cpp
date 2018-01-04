//
// Created by gotesu on 11/12/17.
//
#include "Server.h"
#include "MenuManager.h"
#include "GameManager.h"
#include <vector>
#include <pthread.h>

using namespace std;

#define MAX_CONNECTED_CLIENTS 2
#define INSIZE 255

struct mainThreadsArgs{
    int serverSocket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
};


Server::Server(int port): port(port), serverSocket(0) {
    cout << "Server running" << endl;
    running = true;
}

void Server::start() {
    vector<pthread_t> threads;
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
    threads.push_back((pthread_t)new pthread_t());
    pthread_create(&threads.at(0),NULL,handleClient,(void*)args);
    pthread_join(threads.at(0), NULL);
    delete args;
}

void *Server::handleClient(void* args) {
    mainThreadsArgs arg = *(mainThreadsArgs*) args;
    while (true) {
        // Accept a new client connection
        int clientSocket = accept(arg.serverSocket, (struct
                sockaddr *) &arg.clientAddress, &arg.clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept of 1";
        cout << "Client (" << clientSocket << ") connected" << endl;
    char input[INSIZE] = {0};
		int check = read(clientSocket, input, sizeof(input));
    if (check == -1)
    	throw "Error on read";
		MenuManager::getInstance()->executeCommand(string(input), clientSocket);
    }
}

void Server::stop() {
	cout << "Server closing" << endl;
	running = false;
	// use GameManager.exit to close all the running games
	GameManager::getInstance()->exit();
	// use MenuManager.exit to close all the waiting games from the map
	MenuManager::getInstance()->exit();
	close(serverSocket);
}
