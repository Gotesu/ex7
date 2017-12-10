//
// Created by gotesu on 09/12/17.
//

#include "Server.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int stringToInt(string input) {
    int number = 0;
    int dig;
    for (int i = 0; i < input.size(); i ++) {
        dig = (int) (input.at(i) - '0');
        number += (pow(10, input.size() - 1 - i) * dig);
    }
    return number;
}

int main() {
    fstream data;
    string input;
    try {
        data.open("Server_Settings.txt");
    } catch(exception) {
        throw "Cannot open settings file";
    }
    getline(data, input);
    Server server(stringToInt(input));
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}