//
// Created by gotesu on 31/12/17.
//

#ifndef EX5_REMOTEGAMEROOM_H
#define EX5_REMOTEGAMEROOM_H


#include "RemoteConnection.h"

class RemoteGameRoom {
public:
    //c'tor
    RemoteGameRoom();
private:
    RemoteConnection *rc;
    bool stopped;
    /*
     * function for game list request
     */
    void getList();
    /*
     * function to run game
     */
    void startGame();
    /*
     * function that gets the server response if request is valid
     */
    bool validityCheck();

};


#endif //EX5_REMOTEGAMEROOM_H
