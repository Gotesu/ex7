#ifndef NOMOVECOMMAND_H_
#define NOMOVECOMMAND_H_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include "GameCommand.h"

class NoMoveCommand: public GameCommand {
public:
	virtual bool execute(int socket, vector<string> args, int socket2 = -1) {
		// create a output char[]
		char output[INSIZE] = {0};
		// copy the command arg to the output
		ostringstream command;
		command << args[0];
		strcpy(output,command.str().c_str());
		// write to the socket
		int check = write(socket, output, sizeof(output));
		if (check == -1) {
			cout << "Error writing to socket " << socket << endl;
		}
		return true;
	}
};

#endif /* NOMOVECOMMAND_H_ */
