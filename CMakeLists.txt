cmake_minimum_required(VERSION 3.8)
project(ex3)

set(CMAKE_CXX_STANDARD 98)


add_subdirectory(gtest_src/googletest-release-1.8.0)
include_directories(gtest_src/googletest-release-1.8.0/googletest/include)
include_directories(gtest_src/googletest-release-1.8.0/googlemock/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(SOURCE_FILES
        Client/Board.cpp
        Client/Board.h
        Client/GameSession.cpp
        Client/GameSession.h
        Client/Human.cpp
        Client/Human.h
        Client/Logic.h
        Client/Player.h
        Client/Move.cpp
        Client/Move.h
        Client/StdLogic.cpp
        Client/StdLogic.h
        Client/StdVisual.cpp
        Client/StdVisual.h
        Client/Visual.h
        Client/Computer.h
        Client/Computer.cpp
        )

set(TEST_FILES
        test/gtest_main.cpp test/test_Board.cpp test/test_StdLogic.cpp test/test_Human.cpp test/test_Computer.cpp)

add_executable(ex3 ${SOURCE_FILES} Client/main.cpp)

add_executable(ex3_test ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
target_link_libraries(ex3_test gtest gmock gtest_main)
add_test(ex3_test ex3_test)