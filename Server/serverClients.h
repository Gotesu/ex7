#ifndef SERVERCLIENTS_H_
#define SERVERCLIENTS_H_

#include <vector>
#include "Message.h"

class serverClients {
public:
	static serverClients * getInstance();
    /*******************
 * Function name: addSocket
 * @param socket - the client socket number
 * The function add the socket to the vector.
     *******************/
	void addSocket(int socket);
    /*******************
 * Function name: removeSocket
 * @param socket - the client socket number
 * The function finds the socket in the vector and remove it.
     *******************/
	void removeSocket(int socket);
    /*******************
 * Function name: addThread
 * @param socket - the thread id number
 * The function add the thread to the vector.
     *******************/
    void addThread(pthread_t thread);
    /*******************
 * Function name: removeThread
 * @param thread - the thread id number
 * The function finds the thread in the vector and remove it.
     *******************/
    void removeThread(pthread_t thread);
    /*******************
    * Function name: exit
    * The function go-over the threads vector and the
     * sockets vector , and closes them all.
     *******************/
	void exit();
private:
	serverClients() {}
	serverClients(const serverClients&);
	~serverClients();
	vector<int> sockets;
	vector<pthread_t>threads;
	static serverClients* instance;
	static pthread_mutex_t lock;
	static pthread_mutex_t mapLock;
};

#endif /* SERVERCLIENTS_H_ */
