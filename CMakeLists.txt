cmake_minimum_required(VERSION 3.8)
project(ex3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    Board.cpp
    Board.h
    GameSession.cpp
    GameSession.h
    Human.cpp
    Human.h
    Logic.cpp
    Logic.h
    main.cpp
    Player.cpp
    Player.h
    Move.cpp
    Move.h
    StdLogic.cpp
    StdLogic.h
    StdVisual.cpp
    StdVisual.h
    Visual.cpp
    Visual.h)

add_executable(ex3 ${SOURCE_FILES})
