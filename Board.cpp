#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;
<<<<<<< HEAD



    char& xo::operator= (const char c){
        if(c == 'X' || c == 'O')
        {
            x = c;
        }
        else
        {
            throw IllegalCharException(c);
        }
        return x;
    }


void freeBoard(xo** board,int _size){
    for(int i = 0 ; i < _size ; i++){
=======
    
    
//Also when overloading operator= I needed to free needed to delete rows but not the pointer since the size of the board changes.
void freeBoard(xo** board,int size){
    for(int i = 0 ; i < size ; i++){
>>>>>>> 58fec4ae1231f0b2851c476a70b1dd022e9c914e
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
<<<<<<< HEAD
	_size = 0;
	board = new xo* [_size];
=======
	size = 0;
	//dynamic matrix tooken from https://www.geeksforgeeks.org/create-dynamic-2d-array-inside-class-c/
	board = new xo* [size];
>>>>>>> 58fec4ae1231f0b2851c476a70b1dd022e9c914e

}


Board::Board(int v)
{
<<<<<<< HEAD
    //freeBoard(board,_size);
	_size = v;
	board = new xo* [_size];

	for (int i=0; i<_size; i++)
	{
    	board[i] = new xo[_size];
    	for(int j = 0 ; j < _size ; j++){
    		board[i][j].clear();
=======
	size = v;
	board = new xo* [size];
	for (int i=0; i<size; i++)
	{
    	board[i] = new xo[size];
    	for(int j = 0 ; j < size ; j++){
    		board[i][j].clear();            //sets all to "."
>>>>>>> 58fec4ae1231f0b2851c476a70b1dd022e9c914e
    	}
	}
}



Board::~Board(){
<<<<<<< HEAD
    freeBoard(board,_size);
    delete[] board;
=======
    freeBoard(board,size);                  //deletes all lines
    delete[] board;                         
>>>>>>> 58fec4ae1231f0b2851c476a70b1dd022e9c914e
}

Board::Board(const Board& b){
    _size = b._size;
	board = new xo* [_size];

	for (int i=0; i<_size; i++)
	{
    	board[i] = new xo[_size];
    	for(int j = 0 ; j < _size ; j++){
    		board[i][j]= b.board[i][j];
    	}
	}
}



ostream& operator<<(std::ostream& os, Board const &b)
{
    for(int i = 0 ; i < b._size ; i++){
        for(int j = 0 ; j < b._size ; j++){
            os << b.board[i][j] ;
        }
        os << endl;
    }
    return os;
    
}



xo& Board::operator[](const Coordinate c) const
{
    if(c.x < _size && c.y < _size)
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
        for(int i = 0 ; i < _size ; i++)
        {
            for(int j = 0 ; j < _size ; j++)
            {
                board[i][j].clear();
            }
        }
    }
    //not sure I am suppose to support this
    else if(c == 'X' || c == 'O')
    {
        for(int i = 0 ; i < _size ; i++)
        {
            for(int j = 0 ; j < _size ; j++)
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
    freeBoard(board,_size);
    _size = b._size;
	board = new xo* [_size];

	for (int i=0; i<_size; i++)
	{
    	board[i] = new xo[_size];
    	for(int j = 0 ; j < _size ; j++){
    		board[i][j]= b.board[i][j];
    	}
	}
	return *this;
}


