cmake_minimum_required(VERSION 3.8)
project(ex4)

set(CMAKE_CXX_STANDARD 98)


add_subdirectory(gtest_src/googletest-release-1.8.0)
include_directories(gtest_src/googletest-release-1.8.0/googletest/include)
include_directories(gtest_src/googletest-release-1.8.0/googlemock/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(SOURCE_FILES
        Client/Board.cpp
        Client/Board.h
        Client/StdGame.cpp
        Client/StdGame.h
        Client/RemoteGame.cpp
        Client/RemoteGame.h
        Client/RemotePlayer.cpp
        Client/RemotePlayer.h
        Client/GameSession.h
        Client/Human.cpp
        Client/Human.h
        Client/Logic.h
        Client/Player.h
        Client/Player.cpp
        Client/Move.cpp
        Client/Move.h
        Client/StdLogic.cpp
        Client/StdLogic.h
        Client/StdVisual.cpp
        Client/StdVisual.h
        Client/Visual.h
        Client/Computer.h
        Client/Computer.cpp
        Client/RemoteConnection.cpp
        Client/RemoteConnection.h
        )

set(TEST_FILES
        test/gtest_main.cpp test/test_Board.cpp test/test_StdLogic.cpp test/test_Human.cpp test/test_Computer.cpp)

add_executable(ex4 ${SOURCE_FILES} Client/main.cpp )

set (SOURCE_FILES
        Server/Server.cpp Server/Server.h)
add_executable(server ${SOURCE_FILES} Server/main.cpp)

add_executable(ex4_test ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
target_link_libraries(ex4_test gtest gmock gtest_main)
add_test(ex4_test ex4_test)