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

struct pix {
  uint8_t red, green, blue;
public:
  pix() {red = 0; green = 0 ; blue = 0;}
  pix(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
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
        string draw(uint edge);
        string getFileName();
        
};
