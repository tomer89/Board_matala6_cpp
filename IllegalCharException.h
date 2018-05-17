#ifndef CHAR_EXC
#define CHAR_EXC

#include <iostream>
#include "Board.h"
using namespace std;

struct Coordinate;


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



#endif