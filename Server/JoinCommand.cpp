#include "JoinCommand.h"
#include "MenuManager.h"
#include "GameManager.h"

void JoinCommand::execute(int socket2, string gameName) {
	Message sendy;
	// get the other client socket from map
	int socket = MenuManager::getInstance()->removeGame(gameName);
	// check if gameName key was in the map
	if (socket == -1) {
		// if the name wasn't in the map - send an error massage to client
		sendy.error(socket2);
		return;
	}
	// send the client a massage that the command accepted
	sendy.accept(socket2);
	playGame(socket, socket2);
	// if get here - mean the server is closing while game didn't end
	// send an exit massage
	sendy.exit(socket, socket2);
	// close both sockets
	  close(socket);
	  cout << "Client (" << socket << ") disconnected" << endl;
	  close(socket2);
	  cout << "Client (" << socket2 << ") disconnected" << endl;
	// end current pthread
	pthread_exit(NULL);
}

void JoinCommand::playGame(int client1Socket, int client2Socket) {
	int check;
	// send player-number
	int first = 1;
	check = write(client1Socket, &first, 4);
	first++;
	check = write(client2Socket, &first, 4);
	// create a output char[]
	char input[INSIZE] = {0};
	int readen = client1Socket, writen = client2Socket;
	// a loop to handle the game, continue until checkServer() = false
	while (GameManager::getInstance()->checkServer()) {
		// read readen-player command
		check = read(readen, input, sizeof(input));
		// send the command to GameManager
		GameManager::getInstance()->executeCommand(input, writen, readen);
		// swap between the players
		int swap = readen;
		readen = writen;
		writen = swap;
	}
}
