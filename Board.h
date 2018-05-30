#pragma once

#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

#include "coordinate.h"
#include <iostream>
#include <string>
using namespace std;



class xo{
    char x;
    
    public:
        
        char getChar() const{return x;}
        
        char& operator= (const char c);
        
        xo& operator= (const xo _xo){
            x = _xo.getChar();
            return *this;
        }
        
        friend std::ostream& operator<<(std::ostream& os, xo  &b);
        
        void clear(){x = '.';}

        bool operator== (const char _xo) const{
            return (x == _xo);
        }
        

        operator char() const{return x;}
};






class Board{
    
    private:
        
        Coordinate _coord;
    	xo** board;
    	uint _size;
	
    public:
        Board();
        Board(int v);
        Board(const Board& b);
        ~Board();
        friend std::ostream& operator<<(std::ostream& os, Board const &b);
        friend std::istream& operator>>(std::istream& os, Board &b);
        xo& operator[](const Coordinate c) const;
        Board& operator= (const char c);
        Board& operator= (const Board &b);
        uint size() const {return _size;}
        string draw(int edge);
        string getFileName();
        
};
