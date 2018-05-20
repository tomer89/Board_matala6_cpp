#pragma once
#include <iostream>

using namespace std;
//since I get [{int,int}] made me use this
struct Coordinate {
    uint x;
    uint y;
    
    friend std::ostream& operator<<(std::ostream& os, Coordinate const &c); 
};


