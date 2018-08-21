minesweeper: main.o Point.o
	g++ main.o Point.o -o minesweeper -lncurses
main.o: main.cpp Point.h
	g++ -c  main.cpp
Point.o: Point.cpp Point.h
	g++ -c Point.cpp 
clean:
	rm *.o minesweeper
