//
// Created by Elad on 11/12/17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Client/RemoteConnection.h"
#include "../Server/Server.h"

enum Side {WHITE = -1, EMPTY = 0, BLACK = 1};

/**********************
 * checkSides
 * the test checks the getSide function.
 */
TEST(Connection, checkSides) {
	Server server(50000);
	try {
		server.start();
		RemoteConnection rc = RemoteConnection();
		rc.connectToServer();
		RemoteConnection rc2 = RemoteConnection();
		rc2.connectToServer();
    int x = rc.getSide();
    int o = rc2.getSide();
    // check sides
    EXPECT_EQ(x, BLACK);
    EXPECT_EQ(o, WHITE);
	  // Disconnect
		char send[10] = {0};
		send[0] = 'E';
		send[1] = 'n';
		send[2] = 'd';
		rc.sendMove(send);
		rc2.sendMove(send);
	} catch (exception& e) {
		cout << "Error";
}

/**********************
 * sendAndGet
 * the test checks sendMove and getMove function.
 */
TEST(Connection, sendAndGet) {
	Server server(50000);
	try {
		server.start();
		// create clients and connect them
		RemoteConnection rc = RemoteConnection();
		rc.connectToServer();
		RemoteConnection rc2 = RemoteConnection();
		rc2.connectToServer();
		rc.getSide();
		rc2.getSide();
		// send and get a move
		char send[10] = {0}, get[10] = {0};
		send[0] = 'O';
		send[1] = 'K';
		rc.sendMove(char* send)
		rc2.getMove(get);
		// check the result
	  EXPECT_EQ(strcmp(get, "OK"), 0);
	  // Disconnect
		send[0] = 'E';
		send[1] = 'n';
		send[2] = 'd';
		rc.sendMove(send);
		rc2.sendMove(send);
	} catch (exception& e) {
		cout << "Error";
}
