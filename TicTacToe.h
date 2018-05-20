#pragma once


#include "Player.h"
#include "Board.h"
#include "coordinate.h"






class TicTacToe{
    
    private:
        int _size;
        Board _board;
        Player* _xPlayer,*_oPlayer;
        Player* _winner;
        //true if finished game false if not. If true this func will populate _winner
        bool finished(Coordinate coord, Player& p);
        void setWinner(Player& p);
        
    
    public:
        TicTacToe(int size):_size(size), _board(size){}
        void play(Player& a,Player& b);
        Board board() const;
        Player& winner() const;
        bool legalMove(const Coordinate coord , Player &p);
};