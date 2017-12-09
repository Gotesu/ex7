#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <vector>

using namespace std;

//  using directions as numbers helps save the information in a vector
enum directions {up = 0, down = 1,
						righ = 2, lef = 3,
						downright = 4, downleft = 5,
						upright = 6, upleft = 7};

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
	Move(int x, int y, vector<int> d);
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
	* The Output: a numbers of enemy's blocks that will change by the move, in dirction i
	* The function operation: this is a getter function for dir[i].
	******************************************/
    int getDir(int i);
    /************************
	* Function name : pPrint()
	* The function operation: prints the Move in a conventional way (row,col).
     **********************/
    void pMove() const;
    /************************
	* Function name : isEqual
	* The Input: r2 a value to compare to r, c2 a value to compare to c.
	* The Output: true if the given row & column values equal to this move values, false otherwise.
	* The function operation: compared r2 to r, and c2 to c.
     **********************/
    bool isEqual(int r2, int c2);
    /************************
	* Function name : isEqual
	* The Input: a pointer to another Move.
	* The Output: true if the given row & column values of the moves are equal, false otherwise.
	* The function operation: compared this->r to m2->r, and this->c to m2->c.
     **********************/
    bool isEqual(Move* m2);
private:
    int r;
    int c;
    vector<int> dir;
};

#endif //MOVE_H
