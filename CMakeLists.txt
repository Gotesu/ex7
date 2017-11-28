cmake_minimum_required(VERSION 3.8)
project(ex3)

<<<<<<< HEAD
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
=======
set(CMAKE_CXX_STANDARD 98)


add_subdirectory(gtest_src/googletest-release-1.8.0)
include_directories(gtest_src/googletest-release-1.8.0/googletest/include)
include_directories(gtest_src/googletest-release-1.8.0/googlemock/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(SOURCE_FILES
    Board.cpp
    Board.h
    GameSession.cpp
    GameSession.h
    Human.cpp
    Human.h
    Logic.cpp
    Logic.h
    Player.cpp
    Player.h
    Point.cpp
    Point.h
    StdLogic.cpp
    StdLogic.h
    StdVisual.cpp
    StdVisual.h
    Visual.cpp
    Visual.h
    )

set(TEST_FILES
        test/gtest_main.cpp test/test_Board.cpp test/test_StdLogic.cpp)

add_executable(ex3 ${SOURCE_FILES} main.cpp)

add_executable(ex3_test ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
target_link_libraries(ex3_test gtest gmock gtest_main)
add_test(ex3_test ex3_test)
>>>>>>> branch 'master' of https://github.com/Jed-El/ex3
