#include "TicTacToe.h"
#include "coordinate.h"
#include "Player.h"
#include <iostream>

void TicTacToe::play(Player& xPlayer,Player& oPlayer){
    bool playing= true;
    Coordinate x_move;
    Coordinate o_move;
    while(playing){
        x_move = xPlayer.play(_board);
        _board[x_move] = 'X';                //not going to check if a char already exists here, I suppose Player does this.
        playing = !finished(x_move, xPlayer);
        if(playing){
            o_move = oPlayer.play(_board);
            _board[o_move] = 'O';            //not going to check if a char already exists here, I suppose Player does this.
            playing = !finished(o_move, oPlayer);
        }
    }
}
Board TicTacToe::board() const{
    return this._board;
}
Player& TicTacToe::winner(){
    
}

bool TicTacToe::finished(Coordinate coord, Player& p){
    bool stop = false;
    char player = _board[coord];
    uint x = coord.x;
    uint y = coord.y;
    for(uint j = 0 ; j < _size && !stop; j++){
        if(_board[{x,j}] != player)
        {
            stop = true;
        }
    }
    if(stop){
        stop = false;
    }

    for(uint i = 0 ; i < _size && !stop; i++){
        if(_board[{i,y}] != player)
        {
            stop = true;
        }
    }
    
    if(stop){
        stop = false;
    }
    
    if(x == y){
        for(uint i = 0 , j = 0 ; i < _size && j < _size && !stop; i++ , j++){
            if(_board[{i,y}] != player)
            {
                stop = true;
            }
        }
    }
    
    if(!stop)
    {
        _winner = &p;
        return true;
    }
    return false;
}