#ifndef COORD_EXC
#define COORD_EXC

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


#endif