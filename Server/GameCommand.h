#ifndef GAMECOMMAND_H_
#define GAMECOMMAND_H_

#include <string>
#include <cstring>
#include <vector>
#define INSIZE 255

using namespace std;

class GameCommand {
public:
	virtual bool execute(int socket, vector<string> args, int socket2 = -1) = 0;
	virtual ~GameCommand() {}
};

#endif /* GAMECOMMAND_H_ */
