cmake_minimum_required(VERSION 3.8)
project(ex5)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS -pthread)

add_subdirectory(gtest_src/googletest-release-1.8.0)
include_directories(gtest_src/googletest-release-1.8.0/googletest/include)
include_directories(gtest_src/googletest-release-1.8.0/googlemock/include)


set(Client_FILES
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

add_executable(ex5 ${Client_FILES} Client/main.cpp Client/RemoteGameRoom.cpp Client/RemoteGameRoom.h)

set (SeqServer_FILES
        SeqServer/Server.cpp SeqServer/Server.h)
add_executable(SeqServer ${SeqServer_FILES} SeqServer/main.cpp)

set (Server_FILES
        Server/Server.cpp
        Server/Server.h
        Server/GameManager.h
        Server/GameManager.cpp
        Server/MenuManager.h
        Server/MenuManager.cpp
        Server/MenuCommand.h
        Server/GameCommand.h
        Server/EndCommand.h
        Server/Message.h
        Server/Message.cpp
        Server/JoinCommand.cpp
        Server/JoinCommand.h
        Server/PlayCommand.h
        Server/NoMoveCommand.h
        Server/ListCommand.h
        Server/StartCommand.h)
add_executable(Server ${Server_FILES} Server/main.cpp)

add_executable(ex5_test ${Client_FILES} ${SeqServer_Files} ${TEST_FILES} test/gtest_main.cpp)

target_link_libraries(ex5_test gtest gmock gtest_main)
add_test(ex5_test ex5_test)