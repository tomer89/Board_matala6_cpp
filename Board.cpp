#include <iostream>
#include <vector>
#include "Board.h"
//#include <map>
using namespace std;
    
    
//Also when overloading operator= I needed to free needed to delete rows but not the pointer since the size of the board changes.
void freeBoard(xo** board,int size){
    for(int i = 0 ; i < size ; i++){
        delete[] board[i];
    }
}

    

std::ostream& operator<<(std::ostream& os, xo &c){
    os << c.getChar();
    return os;
}    
    
    
    
    
//*************************************All board stuff*********************************************    
    

Board::Board()
{
	size = 0;
	//dynamic matrix tooken from https://www.geeksforgeeks.org/create-dynamic-2d-array-inside-class-c/
	board = new xo* [size];

}


Board::Board(int v)
{
	size = v;
	board = new xo* [size];
	for (int i=0; i<size; i++)
	{
    	board[i] = new xo[size];
    	for(int j = 0 ; j < size ; j++){
    		board[i][j].clear();            //sets all to "."
    	}
	}
}



Board::~Board(){
    freeBoard(board,size);                  //deletes all lines
    delete[] board;                         
}

Board::Board(const Board& b){
    size = b.size;
	board = new xo* [size];

	for (int i=0; i<size; i++)
	{
    	board[i] = new xo[size];
    	for(int j = 0 ; j < size ; j++){
    		board[i][j]= b.board[i][j];
    	}
	}
}



ostream& operator<<(std::ostream& os, Board const &b)
{
    for(int i = 0 ; i < b.size ; i++){
        for(int j = 0 ; j < b.size ; j++){
            os << b.board[i][j] ;
        }
        os << endl;
    }
    return os;
    
}



xo& Board::operator[](coord c)
{
    if(c.x < size && c.y < size)
    {
        return board[c.x][c.y];                 //returns reference to this xo
    }
    else
    {
        throw IllegalCoordinateException(c);
    }
}




Board& Board::operator= (const char c)
{
    if(c == '.')
    {
        for(int i = 0 ; i < size ; i++)
        {
            for(int j = 0 ; j < size ; j++)
            {
                board[i][j].clear();
            }
        }
    }
    //not sure I am suppose to support this
    else if(c == 'X' || c == 'O')
    {
        for(int i = 0 ; i < size ; i++)
        {
            for(int j = 0 ; j < size ; j++)
            {
                board[i][j] = c;
            }
        }
    }
    else
    {
        throw IllegalCharException(c);
    }
    
    return *this;
}


Board& Board::operator=(const Board& b)

{
    freeBoard(board,size);
    size = b.size;
	board = new xo* [size];

	for (int i=0; i<size; i++)
	{
    	board[i] = new xo[size];
    	for(int j = 0 ; j < size ; j++){
    		board[i][j]= b.board[i][j];
    	}
	}
	return *this;
}


