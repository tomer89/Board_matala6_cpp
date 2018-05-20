#pragma once


#include <iostream>
//#include <string>
#include "coordinate.h"
#include "Board.h"
using namespace std;


class Player{
    //private:
    private:
        char _c;
    public:
        char myChar;
        char setChar(char c){_c = c;}
        char getChar() {return _c;}
        virtual const string name() const = 0;
    	virtual const Coordinate play(const Board& board) = 0;
};

