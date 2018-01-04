#include <vector>
#include "serverClients.h"

using namespace std;

serverClients* serverClients::instance = 0;
pthread_mutex_t serverClients::lock;
pthread_mutex_t serverClients::mapLock;

serverClients * serverClients::getInstance() {
	if (instance == 0) {
		pthread_mutex_lock(&lock);
		if (instance == 0) {
			instance = new serverClients();
		}
		pthread_mutex_unlock(&lock);
	}
	return instance;
}

void serverClients::addSocket(int socket) {
	pthread_mutex_lock(&mapLock);
	// add the socket to the vector
	sockets.push_back(socket);
	pthread_mutex_unlock(&mapLock);
}

void serverClients::removeSocket(int socket) {
	pthread_mutex_lock(&mapLock);
	// go-over the vector
	vector<int>::iterator it;
	for (it = sockets.begin(); it != sockets.end(); it++) {
		// check if the current socket is the given one
		if (socket == *it) {
			// close the socket
			close(*it);
			cout << "Client (" << *it << ") disconnected" << endl;
			// erase the socket from the vector
			sockets.erase(it);
		}
	}
	pthread_mutex_unlock(&mapLock);
}

void serverClients::exit() {
	Message sendy;
	// go-over the vector
	vector<int>::iterator it;
	for (it = sockets.begin(); it != sockets.end(); it++) {
		// send an exit command
		sendy.exit(*it);
		// close the socket
		close(*it);
		cout << "Client (" << *it << ") disconnected" << endl;
	}
}

serverClients::~serverClients() {
	if (instance != 0)
		delete instance;
}
