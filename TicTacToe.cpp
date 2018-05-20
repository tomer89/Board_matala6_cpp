#include "TicTacToe.h"
#include "coordinate.h"
#include "Player.h"
#include <iostream>

using namespace std;






void TicTacToe::play(Player& xPlayer,Player& oPlayer){
    _board = '.';
    
    bool playing= true;
    Coordinate x_move;
    Coordinate o_move;
    
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    
    while(playing){
        try{
            x_move = xPlayer.play(_board);
        }
        catch (string& s) {
            setWinner(oPlayer);
            return;            
        }
        try{
            if(legalMove(x_move,xPlayer))
            {
                try{
                    _board[x_move] = xPlayer.getChar();
                }
                catch(IllegalCharException e){
                    setWinner(oPlayer);
                    return;
                }
                catch(IllegalCoordinateException e){
                    setWinner(oPlayer);
                    return;                    
                }
            }
        }
        catch(IllegalPlay p)
        {
            setWinner(oPlayer);
            return;
        }    
        playing = !finished(x_move, xPlayer);
        if(playing){
            try{
                o_move = oPlayer.play(_board);
            }
            catch (string& s) {
                setWinner(xPlayer);
                return;            
            }
            try{
                if(legalMove(o_move,oPlayer))
                {
                    try{
                        _board[o_move] = oPlayer.getChar();            //not going to check if a char already exists here, I suppose Player does this.
                    }
                    catch(IllegalCharException e){
                        setWinner(xPlayer);
                        return;
                    }
                    catch(IllegalCoordinateException e){
                        setWinner(xPlayer);
                        return;                    
                    }
                }
            }
            catch(IllegalPlay p)
            {
                setWinner(xPlayer);
                
                return;
            }
            playing = !finished(o_move, oPlayer);
        }
    }
}

Board TicTacToe::board() const{return _board;}

Player& TicTacToe::winner() const{
    return *_winner;
}

void TicTacToe::setWinner(Player& p){ _winner = &p;}

bool TicTacToe::finished(Coordinate coord, Player& p){
    bool stop = false;
    char player = _board[coord];
    Coordinate c_checking;
    uint x = coord.x;
    uint y = coord.y;
    for(uint j = 0 ; j < _size && !stop; j++){
        c_checking = {x,j};
        if(_board[c_checking] != player)
        {
            stop = true;
        }
    }
    if(stop){
        stop = false;
    }
    else
    {
        _winner = &p;
        return true;
    }
    

    for(uint i = 0 ; i < _size && !stop; i++){
        c_checking = {i,y};
        if(_board[c_checking] != player)
        {
            stop = true;
        }
    }
    
   
    
    if(x == y){
        if(stop){
            stop = false;
        }
        else{
            _winner = &p;
            return true;
        }
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


bool TicTacToe::legalMove(const Coordinate coord , Player &p){
    if(_board[coord] != '.'){
        throw IllegalPlay();
        return false;
    }
    return true;
}