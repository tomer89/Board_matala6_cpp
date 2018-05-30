#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;



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
	_size = 0;
	board = new xo* [_size];

}


Board::Board(int v)
{
    //freeBoard(board,_size);
	_size = v;
	board = new xo* [_size];

	for (int i=0; i<_size; i++)
	{
    	board[i] = new xo[_size];
    	for(int j = 0 ; j < _size ; j++){
    		board[i][j].clear();
    	}
	}
}



Board::~Board(){
    freeBoard(board,_size);
    delete[] board;

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

istream& operator>>(std::istream& input, Board &b)
{
    //b.~Board();
    cout << "Working here - tomer\n";
    string line;
    input >> line;
    Board tmpBoard(line.size());
    int col = 0;
    for(char& c : line) {
        tmpBoard.board[0][col] = c;
        col++;
    }
    for(int row = 1; row < tmpBoard.size() ; row++){
        input >> line;
        col = 0 ;
        for(char& c : line) {
            tmpBoard.board[row][col] = c;
            col++;
        }
    }
    cout << tmpBoard;
    //cout << unparsed << next;
/*	string line;
	ifstream nameFileout;
	
	while (nameFileout >> line)
	{
	    //cout << item_name;
        for(char& c : str) {
            do_things_with(c);
        }
	    cout << endl;
	}
	nameFileout.close();*/
    return input;
    
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


string Board::draw(int edge){
    return "a";
}
