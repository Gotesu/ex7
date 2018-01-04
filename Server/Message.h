#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <map>
#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <string>
#include <cstring>

#define INSIZE 255

using namespace std;

class Message {
public:
    /*******************
 * Function name: accept
 * @param socket - the client socket number
 * @param socket2 (optional) - a second client socket number
 * The function send the client a massage that the command accepted.
     *******************/
	void accept(int socket, int socket2 = -1);
    /*******************
 * Function name: error
 * @param socket - the client socket number
 * @param socket2 (optional) - a second client socket number
 * The function sends the client an error massage.
     *******************/
	void error(int socket, int socket2 = -1);
    /*******************
 * Function name: exit
 * @param socket - the client socket number
 * @param socket2 (optional) - a second client socket number
 * The function sends the client/s an exit massage.
     *******************/
	void exit(int socket, int socket2 = -1);
private:
    /*******************
 * Function name: sendTo
 * @param socket - the client socket number
 * @param message - the message
 * The function sends the given message to the client.
     *******************/
	void sendTo(int socket, string message);
};

#endif /* MESSAGE_H_ */
