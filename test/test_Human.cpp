//
// Created by gotesu on 29/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Client/Human.h"
#include "../Client/StdLogic.h"
/******************8
 * noChoice
 * this check verifies that a player passes his turn if he has no move to do.
 */
TEST(HumanCheck,noChoice) {
    Board *b = new Board(2,2);
    StdLogic *logic = new StdLogic();
    Human *hu = new Human(*logic, *b, BLACK);
    Human *hu2 = new Human(*logic, *b, WHITE);
    EXPECT_EQ(hu->doMove(),false);
    EXPECT_EQ(hu2->doMove(),false);
    delete b;
    delete logic;
    delete hu;
    delete hu2;
}