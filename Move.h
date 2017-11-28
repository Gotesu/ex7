#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <vector>

using namespace std;

/****************
 * class Move objective is just to be a more human readable representation of a position in our board
 * which I made analogic with row and col axis' ( I defined it as a Move in space just for
 * convenience).
 */
class Move {
public:
	/******************************************
	* Constructor
	* The Input: x row value, y column value,
	* d a vector with numbers of enemy's blocks that will change by the move, for every direction.
	******************************************/
	Move(int x, int y, vector<int> d = vector<int> (8,0));
	/******************************************
	* function name: getR()
	* The Output: the move row value.
	* The function operation: this is a getter function for r.
	******************************************/
    int getR() const;
	/******************************************
	* function name: getC()
	* The Output: the move column value.
	* The function operation: this is a getter function for c.
	******************************************/
    int getC() const;
	/******************************************
	* function name: getDir()
	* The Output: a vector with numbers of enemy's blocks that will change
  * by the move, for every direction.
	* The function operation: this is a getter function for dir.
	******************************************/
    vector<int> getDir();
    /************************
	* Function name : pPrint()
	* The function operation: prints the Move in a conventional way (row,col).
     **********************/
    void pMove() const;
    /************************
	* Function name : isEqual
	* The Input: m2 a Move to compare to this Move.
	* The Output: true if the given Move row & column values equal to this move values, false otherwise.
	* The function operation: compare row & column values of two Moves.
     **********************/
    bool isEqual(Move *m2);
    /************************
	* Function name : isEqual
	* The Input: r2 a value to compare to r, c2 a value to compare to c.
	* The Output: true if the given row & column values equal to this move values, false otherwise.
	* The function operation: compared r2 to r, and c2 to c.
     **********************/
    bool isEqual(int r2, int c2);
private:
    int r;
    int c;
    vector<int> dir;
};

#endif //MOVE_H
