//
// Created by gotesu on 11/12/17.
//
#include "Server.h"
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
    cout << "Server" << endl;
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

void* Server::playGame(void* twoClients) {
    int n;
    int first = 1;
    int *sockets = (int*) twoClients;
    int clientSocket = *sockets;
    sockets++;
    int clientSocket2 = *sockets;
    n = write(clientSocket, &first, 4);
    first++;
    n = write(clientSocket2, &first, 4);
    char client1Input[INSIZE] = {0};
    char client2Input[INSIZE] = {0};
    char endMessage[INSIZE] = "End";
    while(true) {
        //read new move of first player.
        n = read(clientSocket, client1Input, sizeof(client1Input));
        if (n == -1) {
            cout << "Error reading client 1 input" << endl;
            break;
        }
        if (n == 0) {
            cout << "Client 1 disconnected" << endl;
            break;
        }
        //case game ended
        if (Server::endGame(client1Input)) {
            cout << "Game ended" << endl;
            write(clientSocket2, endMessage, sizeof(endMessage));
            break;
        }
        //send the move to client 2
        n = write(clientSocket2, client1Input, sizeof(client1Input));
        if (n == -1) {
            cout << "Error writing to client 2" << endl;
            break;
        }
        //read client 2 new move
        n = read(clientSocket2, client2Input, sizeof(client2Input));
        if (n == -1) {
            cout << "Error reading client 2 input" << endl;
            break;
        }
        if (n == 0) {
            cout << "Client 1 disconnected" << endl;
            break;
        }
        //case game ended.
        if (Server::endGame(client2Input)) {
            cout << "Game ended" << endl;
            write(clientSocket, endMessage, sizeof(endMessage));
            break;
        }
        //send to client 1
        n = write(clientSocket, client2Input, sizeof(client2Input));
        if (n == -1) {
            cout << "Error writing to client 1" << endl;
            break;
        }
    }
    close(clientSocket);
    close(clientSocket2);
}

void Server::stop() {
    close(serverSocket);
}

bool Server::endGame(char* input) {
    string check = "End";
    if (strcmp(input, check.c_str()) == 0)
        return 1;
    return 0;
}

void *Server::handleClient(void* args) {
    mainThreadsArgs arg = *(mainThreadsArgs*) args;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(arg.serverSocket, (struct
                sockaddr *) &arg.clientAddress, &arg.clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept of 1";
        cout << "First Client connected" << endl;
    }
}