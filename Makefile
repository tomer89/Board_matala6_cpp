CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

all: main.o Board.o
     g++ -std=c++11 main.o Board.o -o hello
     
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
    
Board.o: Board.cpp Board.h
	g++ -std=c++11 -c Board.cpp

clean: 
	rm *.o hello