//
// Created by gotesu on 31/12/17.
//

#ifndef EX5_REMOTEGAMEROOM_H
#define EX5_REMOTEGAMEROOM_H


#include "RemoteConnection.h"

class RemoteGameRoom {
public:
    RemoteGameRoom();
private:
    RemoteConnection *rc;
    bool stopped;
    void getList(const char* request);
    void startGame(const char* request);
    void joinGame(const char* request);

};


#endif //EX5_REMOTEGAMEROOM_H
