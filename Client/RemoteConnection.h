//
// Created by gotesu on 09/12/17.
//

#ifndef EX4_REMOTECONNECTION_H
#define EX4_REMOTECONNECTION_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "Move.h"
#include <fstream>
class RemoteConnection {

public:
    //c'tor
    RemoteConnection();
    /***************
     * connecting to server func.
     */
    void connectToServer();
    /********************
     * get side by who connected first.
     */
    int getSide();
    /****************
     * send command to server
     * @param move
     */
    void sendInfo(char* info);
    /***************
     * get move from server
     * @param input
     */
    void getInfo(char *input);
    /*************************
     * send info sends a command to the server.
     * @param info
     ********************/
    /************
     * set the side by who connected first
     */
    void setSide();
private:

    int side;
    const char *serverIP;
    int serverPort;
    int clientSocket;
    int stringToInt(string input);
};



#endif //EX4_REMOTECONNECTION_H
