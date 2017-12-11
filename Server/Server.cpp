//
// Created by gotesu on 11/12/17.
//

#include "Server.h"
using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port): port(port), serverSocket(0) {
    cout << "Server" << endl;
}
void Server::start() {
// Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    int clientSocket;
    int clientSocket2;
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
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    struct sockaddr_in clientAddress2;
    socklen_t clientAddressLen2;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        clientSocket = accept(serverSocket, (struct
                sockaddr *)&clientAddress, &clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept of 1";
        cout << "First Client connected" << endl;
        clientSocket2 = accept(serverSocket, (struct
                sockaddr *)&clientAddress2, &clientAddressLen2);
        if (clientSocket2 == -1)
            throw "Error on accept on 2";
        cout << "Second Client connected" << endl;
        handleClients(clientSocket, clientSocket2);
        // Close communication with the client
        close(clientSocket);
        close(clientSocket2);
    }
}

void Server::handleClients(int clientSocket, int clientSocket2) {
    int n;
    int first = 1;
    n = write(clientSocket, &first, 4);
    first++;
    n = write(clientSocket2, &first, 4);
    char client1Input[10] = {0};
    char client2Input[10] = {0};
    while(true) {
        //read new move of first player.
        n = read(clientSocket, client1Input, sizeof(client1Input));
        if (n == -1) {
            cout << "Error reading client 1 input" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client 1 disconnected" << endl;
            return;
        }
        //case game ended
        if (Server::endGame(client1Input)) {
            cout << "Game ended" << endl;
            return;
        }
        //send the move to client 2
        cout << " this is the first client input" << client2Input << endl;
        n = write(clientSocket2, client1Input, sizeof(client1Input));
        if (n == -1) {
            cout << "Error writing to client 2" << endl;
            return;
        }
        //read client 2 new move
        n = read(clientSocket2, client2Input, sizeof(client2Input));
        if (n == -1) {
            cout << "Error reading client 2 input" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client 1 disconnected" << endl;
            return;
        }
        //case game ended.
        if (Server::endGame(client2Input)) {
            cout << "Game ended" << endl;
            return;
        }
        //send to client 1
        n = write(clientSocket, client2Input, sizeof(client2Input));
        if (n == -1) {
            cout << "Error writing to client 1" << endl;
            return;
        }

    }
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