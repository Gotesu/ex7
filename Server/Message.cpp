#include "Message.h"

void Message::accept(int socket, int socket2) {
	// write to socket
	sendTo(socket, "accept");
	// check if has a second socket
	if (socket2 != -1) {
		// write to socket
		sendTo(socket2, "accept");
	}
}

void Message::error(int socket, int socket2) {
	// write to socket
	sendTo(socket, "error");
	// check if has a second socket
	if (socket2 != -1) {
		// write to socket
		sendTo(socket2, "error");
	}
}

void Message::exit(int socket, int socket2) {
	// write to socket
	sendTo(socket, "exit");
	// check if has a second socket
	if (socket2 != -1) {
		// write to socket
		sendTo(socket2, "exit");
	}
}

void Message::sendTo(int socket, string message) {
	char output[INSIZE] = {0};
	strcpy(output, message.c_str());
	// write to the socket
	int check = write(socket, output, sizeof(output));
	if (check == -1) {
		cout << "Error writing to socket " << socket << endl;
	}
}
