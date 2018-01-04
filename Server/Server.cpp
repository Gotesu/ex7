//
// Created by gotesu on 11/12/17.
//
#include "Server.h"
#include "MenuManager.h"
#include "GameManager.h"

using namespace std;

#define MAX_CONNECTED_CLIENTS 2
#define INSIZE 255

struct mainThreadsArgs{
    int serverSocket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    vector<pthread_t>* threadings;
};


Server::Server(int port): port(port), serverSocket(0), serverThreadId(0) {
    cout << "Server running" << endl;
    threads = new vector<pthread_t>();
    running = true;
}

void Server::start() {
    mainThreadsArgs *args = new mainThreadsArgs;
    args->threadings = threads;
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
    pthread_join(serverThreadId, NULL);
    delete args;
}

void *Server::acceptClients(void* args) {
    mainThreadsArgs arg = *(mainThreadsArgs*) args;
    while (true) {
        // Accept a new client connection
        int clientSocket = accept(arg.serverSocket, (struct
                sockaddr *) &arg.clientAddress, &arg.clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept";
        cout << "Client (" << clientSocket << ") connected" << endl;
        pthread_t threadId;
        pthread_create(&threadId, NULL, &handleClient, (void *)clientSocket);
        arg.threadings->push_back(threadId);
    }

}
void *Server::handleClient(void *args) {
    char input[INSIZE] = {0};
    long clientSocket = (long)args;
    int check = read(clientSocket, input, sizeof(input));
    if (check == -1)
        throw "Error on read";
    MenuManager::getInstance()->executeCommand(string(input), clientSocket);
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
