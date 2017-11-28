
<<<<<<< HEAD
a.out: Board.o  Move.o Logic.o Player.o Human.o Visual.o StdVisual.o StdLogic.o GameSession.o main.o
	g++ Board.o Move.o Logic.o Player.o Human.o Visual.o StdVisual.o StdLogic.o GameSession.o main.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

Move.o: Move.cpp Move.h
	g++ -c Move.cpp
=======
a.out: Board.o  Point.o Logic.o Player.o Human.o Visual.o StdVisual.o StdLogic.o GameSession.o main.o
	g++ Board.o Point.o Logic.o Player.o Human.o Visual.o StdVisual.o StdLogic.o GameSession.o main.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

Point.o: Point.cpp Point.h
	g++ -c Point.cpp
>>>>>>> branch 'master' of https://github.com/Jed-El/ex3

Logic.o: Logic.cpp Logic.h
	g++ -c Logic.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Human.o: Human.cpp Human.h
	g++ -c Human.cpp

Visual.o: Visual.cpp Visual.h
	g++ -c Visual.cpp

StdVisual.o: StdVisual.cpp StdVisual.h
	g++ -c StdVisual.cpp

StdLogic.o: StdLogic.cpp StdLogic.h
	g++ -c StdLogic.cpp

GameSession.o: GameSession.cpp GameSession.h
	g++ -c GameSession.cpp

main.o: main.cpp Board.h
	g++ -c main.cpp
