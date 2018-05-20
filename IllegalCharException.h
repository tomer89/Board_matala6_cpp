#pragma once

#include <iostream>
#include "Board.h"
using namespace std;




struct Coordinate;

class IllegalCoordinateException{
    Coordinate* _coord;
    public:
        IllegalCoordinateException(Coordinate c);
        std::string theCoordinate() const;
};


/**
 * didn't seperate header and cpp program since the program is so small 
 * and since this exception class doesn't have a high potential to grow
 */

class IllegalCharException{
    char ex;
    public:
        IllegalCharException(char c){
            ex = c;
        }
        char theChar() const{
            return ex;
        }
};



//this is a small class that will only apply for the play
class IllegalPlay{
    public:
        IllegalPlay(){
        }

};
