#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
//#include <string>
#include "coordinate.h"
#include "Board.h"
using namespace std;


class Player{
    //private:
        
    public:
        char myChar;
        virtual const string name() const = 0;
    	virtual const Coordinate play(const Board& board) = 0;
};


#endif