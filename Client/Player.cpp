#include "Player.h"
#include <stdio.h>

char Player::sign() const {
	switch(s) {
		case WHITE : return 'O';
		case BLACK : return 'X';
		default: return 'E';
	}
}

Move* Player::lastMove() {
	return last;
}
