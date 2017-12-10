//
// Created by gotesu on 09/12/17.
//

#include "RemoteConnection.h"
using namespace std;
RemoteConnection::RemoteConnection(const char *serverIP, int serverPort): clientSocket(0) {
    fstream data;
    string input;
    string input2;
    try {
        data.open("Client_Settings.txt");
    } catch(exception) {
        throw "Cannot open settings file";
    }
    getline(data,input);
    getline(data,input2);
    this->serverIP = input.c_str();
    this->serverPort = stringToInt(input2);
    cout << "Client" << endl;
}
void RemoteConnection::connectToServer() {
// Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char
    *) server->h_addr, server->h_length);
    // htons converts values between host and network byte
    //orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *) &serverAddress,
                sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
    setSide();
}

void RemoteConnection::setSide() {
    int side = 0;
    int n = read(clientSocket, &side, sizeof(side));
    if (n == -1) {
        throw "Error writing Move to socket";
    }
    this->side = side;
    return;
}

int RemoteConnection::getSide() {
    return this->side;
}

string RemoteConnection::getMove() {
    string input;
    int n = read(clientSocket, &input, sizeof(input));
    return input;
}

void RemoteConnection::sendMove(string move) {
// Write the Player's move to the socket
    int n = write(clientSocket, &move, sizeof(move));
    if (n == -1) {
        throw "Error writing Move to socket";
    }
    return;
}

int RemoteConnection::stringToInt(string input) {
        int number = 0;
        int dig;
        for (int i = 0; i < input.size(); i ++) {
            dig = (int) (input.at(i) - '0');
            number += (pow(10, input.size() - 1 - i) * dig);
        }
        return number;
}