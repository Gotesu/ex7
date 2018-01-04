#ifndef LISTCOMMAND_H_
#define LISTCOMMAND_H_

#include "MenuCommand.h"

class ListCommand: public MenuCommand {
public:
    /*******************
 * The function send the client a list with the names of the games.
     *******************/
	virtual void execute(int socket, string gameName) {
		// send the client a massage that the command accepted
		Message sendy;
		sendy.accept(socket);
		// create a output char[]
		char output[INSIZE] = {0};
		// create a list string
		ostringstream list;
		list << MenuManager::getInstance()->gamesList();
		// copy the list string into the output char[]
		strcpy(output,list.str().c_str());
		// write to the socket
		int n = write(socket, output, sizeof(output));
		if (n == -1)
			cout << "Error writing to socket number " << socket << endl;
	}
};

#endif /* LISTCOMMAND_H_ */
