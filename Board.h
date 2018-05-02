
#ifndef CIRC_H
#define CIRC_H

#include <iostream>
using namespace std;

class Board{
    public:
        //contructors:
        Board();
        Board(int n);
        Board(int r,l);
        vector<vector<int> > matrix();
};


#endif