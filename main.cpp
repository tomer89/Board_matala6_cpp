/**
 * My git: https://github.com/tomer89/Board_matala6_cpp.git
 * HW:	   https://github.com/erelsgl/ariel-cpp-5778/tree/master/week05-copy-friend/homework
 * https://ide.geeksforgeeks.org/index.php
 * g++ -std=c++0x main.cpp Board.cpp
 //*/ 




#include "Board.h"

#include <iostream>
#include <vector>
//#include <map>
using namespace std;




/*

class Board
{
	
	struct coord
	{
	    int x;
	    int y;
	};
	coord _coord;
	char** board;
	int size;
	
  public:
	  
	Board(int v);
	~Board();
    friend std::ostream& operator<<(std::ostream& os, Board const &b); 
	char& operator[](coord c)
	{
	    return board[c.x][c.y];
	}
};




Board::Board(int v)
{
	size = v;
	board = new char* [size];

	for (int i=0; i<size; i++)
	{
    	board[i] = new char[size];
    	for(int j = 0 ; j < size ; j++){
    		board[i][j] = '*';
    	}
	}
}

Board::~Board(){
    for(int i = 0 ; i < size ; i++){
        delete board[i];
    }
    delete board;
}


ostream& operator<<(std::ostream& os, Board const &b)
{
    for(int i = 0 ; i < b.size ; i++){
        for(int j = 0 ; j < b.size ; j++){
            cout << b.board[i][j] << " ";
        }
        cout << endl;
    }
    cout << " "  << endl;
    
}
*/


int main() {
	Board board1{4};  // Initializes a 4x4 board
	cout << board1 << endl;   /* Shows an empty board:
	....
	....
	....
	....
//	*/
	cout << board1[{1,2}] << endl; // .
	board1[{1,1}]='X';
	board1[{1,2}]='O';
	
	char c = board1[{1,2}]; cout << c << endl; // O
	cout << board1 << endl;  /* Shows the following board:
	....
	.XO.
	....
	....
	*/

	try {
		board1[{3,4}]='O';   // This should raise an exception
	} catch (const IllegalCoordinateException& ex) {
		cout << "Illegal coordinate: " << ex.theCoordinate() << endl;  // prints "Illegal coordinate: 3,4"
	}
	//cout << "did i get here?\n";
	board1 = '.';     // Fill the entire board with "."
	cout << board1 << endl;  // Shows an empty board, as above 
	try { 
		board1 = 'a';        // This should raise an exception
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: a"
	}

	try {
		board1[{0,1}] = 'x';  // This should raise an exception
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: x"
	}
	/*
	Board board2 = board1;
	board2[{0,0}] = 'X';

	cout << board1 << endl;  // Shows an empty board, as above 
	cout << board2 << endl;  // Shows a board with an X at top-left 

	board1 = board2;
	board1[{3,3}] = 'O';
	cout << board2 << endl;  // Shows a board with an X at top-left 
	cout << board1 << endl;  // Shows a board with an X at top-left and O at bottom-right 

	cout << "Good bye!" << endl;
*/
	return 0;
}
























/*struct A
{
    void operator=(char)
    {
        std::cout << "foo = ...\n";
    }
    
    operator char()
    {
        std::cout << "... = foo\n";
        return 'a';
    }
};*/

/*class Board
{
	public:
    Board operator[](struct coord c)
    {
        return Board();
    }
    
    
    void operator=(char)
    {
        std::cout << "foo = ...\n";
    }
    
    operator char()
    {
        std::cout << "... = foo\n";
        return 'a';
    }
};
*/
