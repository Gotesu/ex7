#ifndef PLAYCOMMAND_H_
#define PLAYCOMMAND_H_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include "GameCommand.h"

class PlayCommand: public GameCommand {
public:
	virtual void execute(int socket, vector<string> args, int socket2 = -1) {
		// create a output char[]
		char output[INSIZE] = {0};
		// copy args to the output
		if (args.size() >= 2) {
		    ostringstream rowStr, colStr;
		    rowStr << args[0];
		    colStr << args[1];
		    strcpy(output, rowStr.str().c_str());
		    strcat(output, ", ");
		    strcat(output, colStr.str().c_str());
		}
		// write to the socket
		int check = write(socket, output, sizeof(output));
		if (check == -1) {
			cout << "Error writing to socket " << socket << endl;
		}
	}
};

#endif /* PLAYCOMMAND_H_ */
