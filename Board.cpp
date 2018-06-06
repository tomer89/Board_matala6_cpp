/*#include <iostream>
#include <fstream>
#include <vector>
#include "Board.h"
using namespace std;



    char& xo::operator= (const char c){
        if(c == 'X' || c == 'O' || c == '.')
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
    b = tmpBoard;
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


string Board::draw(uint edge){
    string filename = getFileName();
    //https://github.com/erelsgl/ariel-cpp-5778/tree/3dad1e8994aceee18cdb34ea030cb4cb6cf2417e/week07-diamond-rtti/5-image

    pix board_image[edge*edge];
    while(std::ifstream(filename)){
        filename = getFileName();
    }
    ofstream imageFile(filename, ios::out | ios::binary);
    imageFile << "P6" << endl << edge <<" " << edge << endl << 255 << endl;
    //int box = edge/size();
    for(uint row = 0 ;row < size() ; row++){
        for(uint col = 0 ;col < size() ; col++){
          board_image[edge*row+col].red = (col % 256);
          board_image[edge*row+col].green = (row % 256);
          board_image[edge*row+col].blue = ( (row*row+col*col) % 256);
        }
    }
    board_image[0].red = 255;
    board_image[0].blue = 0;
    board_image[0].green = 0;
    imageFile.write(reinterpret_cast<char*>(&board_image), 3*edge*edge);
    imageFile.close();
    
    
    return filename;
}



string Board::getFileName(){
    static int i = -1;
    i++;
    return "boardoutput"+to_string(i)+".ppm";    
}



bool Board::DoesFileExist (const std::string& name) {
    cout << name << endl;
    
    ifstream f("boardoutput0.ppm");
    cout << f.good() << endl;
    return f.good();
}*/


#include <iostream>
#include <fstream>
#include <vector>
#include "Board.h"
using namespace std;



    char& xo::operator= (const char c){
        if(c == 'X' || c == 'O' || c == '.')
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
    string line;
    input >> line;
    Board tmpBoard(line.size());
    int col = 0;
    for(char& c : line) {
        //cout << "char is: " << c << endl;
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
    //cout << tmpBoard;
    b = tmpBoard;
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


string Board::draw(uint edge){
    string filename = getFileName();
    //https://github.com/erelsgl/ariel-cpp-5778/tree/3dad1e8994aceee18cdb34ea030cb4cb6cf2417e/week07-diamond-rtti/5-image
    
    while(std::ifstream(filename)){
        filename = getFileName();
    }
    
    ofstream imageFile(filename, ios::out | ios::binary);

    imageFile << "P6" << endl << edge <<" " << edge << endl << 255 << endl;
    pix board_image[edge*edge];
    int box = edge/size();
    for(uint row = 0 ;row < size() ; row++){
        for(uint col = 0 ;col < size() ; col++){
            
            if(board[row][col] == 'X'){
                
                for(uint i = (row * box) ; i < (row * box) + box ; i++){
                    for(uint j = (col * box) ;j < (col * box) +box; j++){
                        board_image[edge*i + j].red = 255;
                    }
                }
            }
            if(board[row][col] == 'O'){
                
                for(uint i = (row * box) ; i < (row * box) + box ; i++){
                    //cout << i << "," << col << "edege is: " << edge << endl;
                     
                    for(uint j = (col * box) ;j < (col * box) +box; j++){
                        //cout << i << "," << j << endl;
                        board_image[edge*i + j].blue = 255;
                    }
                }
            }
        }
    }
    
    //draw edges
    if(edge > 15){
        for(uint col = 1 ;col < size() ; col++){
            for(uint i = 0 ; i < edge ; i++){
                board_image[edge*i + (col * box) ].blue = 0;
                board_image[edge*i + (col * box) ].red = 0;
                board_image[edge*i + (col * box) ].green = 255;
                board_image[edge*i + (col * box) + 1].green = 255;
                board_image[edge*i + (col * box) - 1].green = 255;
            }
        }
         for(uint row = 1 ;row < size() ; row++){
            for(uint i = 0 ; i < edge ; i++){
                board_image[edge*(row*box) + i ].blue = 0;
                board_image[edge*(row*box) + i ].red = 0;
                board_image[edge*(row*box) + i ].green = 255;
                board_image[edge*(row*box-1) + i].green = 255;
                board_image[edge*(row*box+1) + i].green = 255;
            }
        }
    }
/*            for(uint col = 0 ;col < size() ; col++){
                if(col > 0){
                    
            
                }
                if(row > 0){
                    for(uint j = (col * box) ; j < (col * box) + box ; j++){
                        board_image[edge*(row*box)+box + (j +box)].blue = 0;
                        board_image[edge*(row*box)+box + (j +box)].red = 0;
                    }
                    for(uint j = (col * box) ; j < (col * box) + box ; j++){
                        board_image[edge*(row*box) + (j * box) + box + 1].green = 255;
                        board_image[edge*(row*box) + (j * box) + box - 1].green = 255;
                    }
                }
            }
        }
    }*/
/*       for(uint i = (row * box) ; i < (row * box) + box ; i++){
                    for(uint j = (col * box) ;j < (col * box) +box; j++){
                        board_image[edge*i + j].red = 255;*/

    imageFile.write(reinterpret_cast<char*>(&board_image), 3*edge*edge);
    imageFile.close();
    
    return filename;
}



string Board::getFileName(){
    static int i = -1;
    i++;
    return "boardoutput"+to_string(i)+".ppm";    
}
