#ifndef MENUCOMMAND_H_
#define MENUCOMMAND_H_

#include <map>
#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <string>
#include <cstring>
#include "Message.h"

#define INSIZE 255

using namespace std;

class MenuCommand {
public:
	virtual void execute(int socket, string gameName = NULL) = 0;
	virtual ~MenuCommand() {}
};

#endif /* MENUCOMMAND_H_ */
