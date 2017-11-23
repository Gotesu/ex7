/*
 * Ouriel Gotesdyner
 * gotesdo
 * 305554834
 */

#include "GameSession.h"

GameSession::GameSession(Board* board, Visual* vis, Logic* logic, Player* p1, Player* p2):
        board(board),vis(vis) ,logic(logic),player1(p1), player2(p2) {}

GameSession::~GameSession() {
};
void GameSession::playRound() {
    int gameOver = 2;
    vector<Point*> optionsX;
    vector<Point*> optionsO;
    Point* choiceX;
    Point* choiceO;
    while (gameOver != 0) {
        vis->printBoard();
        gameOver = 2;
        cout << "X its your move." << endl;
        optionsX = logic->allowedActions(board, BLACK);
        choiceX = player1->doMove(optionsX);
        if (choiceX != NULL) {
            updateBoard(BLACK, choiceX);
            delete choiceX;
            optionsX.clear();
        }
        else
            gameOver--;
        vis->printBoard();
        cout << "O its your move." << endl;
        optionsO = logic->allowedActions(board, WHITE);
        choiceO = player2->doMove(optionsO);
        if (choiceO != NULL) {
            updateBoard(WHITE, choiceO);
            delete choiceO;
            optionsO.clear();
        }
        else
            gameOver--;
    }
    finalCountdown(board);
}

void GameSession::updateBoard(Side s, Point *choice) {
    int i = 1;
    int j = 1;
    board->getBoard()[choice->getR()][choice->getC()] = s;
    //Down direction.
    while (choice->getR() + i < board->getRow()) {
        if (board->getBoard()[choice->getR() + i][choice->getC()] != s
            && board->getBoard()[choice->getR() + i][choice->getC()] != EMPTY) {
           i++;
        }
        else
            break;
    }
    if (choice->getR() + i < board->getRow()
        && s == board->getBoard()[choice->getR() + i][choice->getC()]) {
        for (j = 1; j <= i ; j++) {
            board->getBoard()[choice->getR() + j][choice->getC()] = s;
        }
    }
    //Up direction.
    i = 1;
    j = 1;
    while (choice->getR() - i > 0) {
        if (board->getBoard()[choice->getR() - i][choice->getC()] != s
            && board->getBoard()[choice->getR() - i][choice->getC()] != EMPTY) {
            i++;
        }
        else
            break;
    }
    if (choice->getR() - i > 0
        && s == board->getBoard()[choice->getR() - i][choice->getC()]) {
        for (j = 1; j <= i ; j++) {
            board->getBoard()[choice->getR() - j][choice->getC()] = s;
        }
    }
    //Right direction.
    while (choice->getC() + i < board->getCol()) {
        if (board->getBoard()[choice->getR()][choice->getC() + i] != s
            && board->getBoard()[choice->getR()][choice->getC() + i] != EMPTY) {
            i++;
        }
        else
            break;
    }
    if (s == board->getBoard()[choice->getR()][choice->getC() + i]) {
        for (j = 1; j <= i ; j++) {
            board->getBoard()[choice->getR()][choice->getC() + j] = s;
        }
    }
    //Left direction.
    i = 1;
    j = 1;
    while (choice->getC() - i > 0) {
        if (board->getBoard()[choice->getR()][choice->getC() - i] != s
            && board->getBoard()[choice->getR()][choice->getC() - i] != EMPTY) {
            i++;
        }
        else
            break;
    }
    if (s == board->getBoard()[choice->getR()][choice->getC() - i]) {
        for (j = 1; j <= i ; j++) {
            board->getBoard()[choice->getR()][choice->getC() - j] = s;
        }
    }
    //lower right diagonal
    i = 1;
    j = 1;
    while (choice->getR() + i < board->getRow()
           && choice->getC() + i < board->getCol()) {
        if (board->getBoard()[choice->getR() + i][choice->getC() + i] != s
                && board->getBoard()[choice->getR() + i][choice->getC() + i] != EMPTY) {
            i++;
        }
        else
            break;
    }
    if (choice->getR() + i < board->getRow()
        && s == board->getBoard()[choice->getR() + i][choice->getC() + i]) {
        for (j = 1; j <= i ; j++) {
            board->getBoard()[choice->getR() + j][choice->getC() + j] = s;
        }
    }
    //upper right diagonal
    i = 1;
    j = 1;
    while (choice->getR() - i > 0
           && choice->getC() + i < board->getCol()) {
        if (board->getBoard()[choice->getR() - i][choice->getC() + i] != s
            && board->getBoard()[choice->getR() - i][choice->getC() + i] != EMPTY) {
            i++;
        }
        else
            break;
    }
    if (choice->getR() - i >= 0
        && s == board->getBoard()[choice->getR() - i][choice->getC() + i]) {
        for (j = 1; j <= i ; j++) {
            board->getBoard()[choice->getR() - j][choice->getC() + j] = s;
        }
    }
    //lower left diagonal
    i = 1;
    j = 1;
    while (choice->getR() + i < board->getRow()
           && choice->getC() - i > 0) {
        if (board->getBoard()[choice->getR() + i][choice->getC() - i] != s
            && board->getBoard()[choice->getR() + i][choice->getC() - i] != EMPTY) {
            i++;
        }
        else
            break;
    }
    if (choice->getC() - i >= 0 && choice->getR() + i < board->getRow()
        && s == board->getBoard()[choice->getR() + i][choice->getC() - i]) {
        for (j = 1; j <= i ; j++) {
            board->getBoard()[choice->getR() + j][choice->getC() - j] = s;
        }
    }
    //upper left diagonal
    i = 1;
    j = 1;
    while (choice->getR() - i > 0
           && choice->getC() - i > 0) {
        if (board->getBoard()[choice->getR() - i][choice->getC() - i] != s
            && board->getBoard()[choice->getR() - i][choice->getC() - i] != EMPTY) {
            i++;
        }
        else
            break;
    }
    if (choice->getC() - i >= 0 && choice->getR() - i >= 0
        && s == board->getBoard()[choice->getR() - i][choice->getC() - i]) {
        for (j = 1; j <= i ; j++) {
            board->getBoard()[choice->getR() - j][choice->getC() - j] = s;
        }
    }
}

void GameSession::finalCountdown(Board* b) {
    int white = 0;
    int black = 0;
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if (b->getBoard()[i][j] == BLACK)
                black++;
            if (b->getBoard()[i][j] == WHITE)
                white++;
        }
    }
    if (black > white)
        cout << " Player 1 (black) won! thank you for playing." <<endl;
    if (black < white)
        cout << " Player 2 (white) won! thank you for playing." <<endl;
    if (black == white)
        cout << "a draw! thank you for playing" <<endl;
}
