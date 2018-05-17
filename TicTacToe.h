#pragma once


#include "Player.h"
#include "Board.h"
#include "coordinate.h"

class TicTacToe{
    
    private:
        int _size;
        Board _board;
        Player* _winner;
        //true if finished game false if not. If true this func will populate _winner
        bool finished(Coordinate coord, Player& p);
        
    
    public:
        TicTacToe(int size):_size(size), _board(size){}
        void play(Player& a,Player& b);
        Board board() const;
        Player& winner();
    
};