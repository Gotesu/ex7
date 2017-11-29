//
// Created by gotesu on 28/11/17.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

GTEST_API_ int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}