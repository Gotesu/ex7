#include "StdLogic.h"
using namespace std;
StdLogic::StdLogic():Logic() {}

vector<Move*> StdLogic::allowedActions(Board& board, Side s) {
	vector<Move*> moves;
	for (int i = 0; i < board.getRow(); i++) {
		for (int j = 0; j < board.getCol(); j++) {
			if (board.get(i,j) == EMPTY) {
				vector<int> changes(8, 0);
				vector<int> count(8, 0);
				vector<bool> check(8, true);
				// check how many enemy blocks will change, it is a long check :(
				// the loop continues until all the direction (0-7) stop
				for (int k = 1; (check[0] || check[1] || check[2] || check[3]
													|| check[4] || check[5] || check[6] || check[7]); k++) {
					// check the down direction
					if (i + k < board.getRow()) {
						// check for a break
						if (check[down]) {
							if ((board.get(i + k, j) != s) &&
									(board.get(i + k, j) != EMPTY))
								count[down]++;
							else {
								if (board.get(i + k, j) == s) {
									// add to the total score of the move
									changes[down] = count[down];
								}
								check[down] = false;
							}
					}
				} else {
					// stop if out of borders
					check[down] = false;
				}
					// check the up direction
					if (i - k >= 0) {
						// check for a break
						if (check[up]) {
							if ((board.get(i - k, j) != s) &&
									(board.get(i - k, j) != EMPTY))
								count[up]++;
							else {
								if (board.get(i - k, j) == s) {
									// add to the total score of the move
									changes[up] = count[up];
								}
								check[up] = false;
							}
					}
				} else {
						// stop if out of borders
						check[up] = false;
					}
					// check the right direction
					if (j + k < board.getCol()) {
						// check for a break
						if (check[righ]) {
							if ((board.get(i, j + k) != s) &&
									(board.get(i, j + k) != EMPTY))
								count[righ]++;
							else {
								if (board.get(i, j + k) == s) {
									// add to the total score of the move
									changes[righ] = count[righ];
								}
								check[righ] = false;
							}
					}
				} else {
						// stop if out of borders
						check[righ] = false;
					}					// check the left direction
					if (j - k >= 0) {
						// check for a break
						if (check[lef]) {
							if ((board.get(i, j - k) != s) &&
									(board.get(i, j - k) != EMPTY))
								count[lef]++;
							else {
								if (board.get(i, j - k) == s) {
									// add to the total score of the move
									changes[lef] = count[lef];
								}
								check[lef] = false;
							}
					}
				} else {
						// stop if out of borders
						check[lef] = false;
					}
					// check the down-right direction
					if ((j + k < board.getCol()) && (i + k < board.getRow())) {
						// check for a break
						if (check[downright]) {
							if ((board.get(i + k, j + k) != s) &&
									(board.get(i + k, j + k) != EMPTY))
								count[downright]++;
							else {
								if (board.get(i + k, j + k) == s) {
									// add to the total score of the move
									changes[downright] = count[downright];
								}
								check[downright] = false;
							}
					}
				} else {
						// stop if out of borders
						check[downright] = false;
					}
					// check the down-left direction
					if ((j - k >= 0) && (i + k < board.getRow())) {
						// check for a break
						if (check[downleft] >= 0) {
							if ((board.get(i + k, j - k) != s) &&
									(board.get(i + k, j - k) != EMPTY))
								count[downleft]++;
							else {
								if (board.get(i + k, j - k) == s) {
									// add to the total score of the move
									changes[downleft] = count[downleft];
								}
								check[downleft] = false;
							}
					}
				} else {
						// stop if out of borders
						check[downleft] = false;
					}
					// check the up-right direction
					if ((j + k < board.getCol()) && (i - k >= 0)) {
						// check for a break
						if (check[upright]) {
							if ((board.get(i - k, j + k) != s) &&
									(board.get(i - k, j + k) != EMPTY))
								count[upright]++;
							else {
								if (board.get(i - k, j + k) == s) {
									// add to the total score of the move
									changes[upright] = count[upright];
								}
								check[upright] = false;
							}
					}
				} else {
						// stop if out of borders
						check[upright] = false;
					}
					// check the up-left direction
					if ((j - k >= 0) && (i - k >= 0)) {
						// check for a break
						if (check[upleft]) {
							if ((board.get(i - k,j - k) != s) &&
									(board.get(i - k,j - k) != EMPTY))
								count[upleft]++;
							else {
								if (board.get(i - k,j - k) == s) {
									// add to the total score of the move
									changes[upleft] = count[upleft];
								}
								check[upleft] = false;
							}
					}
				} else {
						// stop if out of borders
						check[upleft] = false;
					}
				}
				// check if at least one move was found
				if ((changes[0] + changes[1] + changes[2] + changes[3] +
					changes[4] + changes[5] + changes[6] + changes[7]) > 0) {
					Move* m = new Move(i, j, changes);
					moves.push_back(m);
				}
			}
		}
	}
	return moves;
}

