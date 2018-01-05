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

void serverClients::addThread(pthread_t thread) {
	pthread_mutex_lock(&mapLock);
	// add the socket to the vector
	threads.push_back(thread);
	pthread_mutex_unlock(&mapLock);
}

void serverClients::removeThread(pthread_t thread) {
	pthread_mutex_lock(&mapLock);
	// go-over the vector
	vector<pthread_t>::iterator it;
	for (it = threads.begin(); it != threads.end(); it++) {
		// check if the current socket is the given one
		if (thread == *it) {
			// close the socket
			pthread_cancel(*it);
			cout << "thread (" << *it << ") closed" << endl;
			// erase the socket from the vector
			threads.erase(it);
		}
	}
	pthread_mutex_unlock(&mapLock);
}

void serverClients::exit() {
	Message sendy;
	// go-over the vector of sockets
    pthread_mutex_lock(&mapLock);
	vector<int>::iterator it;
	for (it = sockets.begin(); it != sockets.end(); it++) {
		// send an exit command
		sendy.exit(*it);
		// close the socket
		close(*it);
		cout << "Client (" << *it << ") disconnected" << endl;
	}
    pthread_mutex_unlock(&mapLock);

    //go over vector of threads;
    pthread_mutex_lock(&mapLock);
    vector<pthread_t>::iterator it2;
    for (it2 = threads.begin(); it2 != threads.end(); it2++) {
        // close the thread
        pthread_cancel(*it2);
        cout << "thread (" << *it2 << ") closed" << endl;
    }
    pthread_mutex_unlock(&mapLock);
}

serverClients::~serverClients() {
	if (instance != 0)
		delete instance;
}
