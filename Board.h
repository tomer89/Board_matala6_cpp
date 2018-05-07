
#ifndef CIRC_H
#define CIRC_H

#include <iostream>
#include <string>
using namespace std;


        
struct coord {
    int x;
    int y;
};


class IllegalCoordinateException{
    coord _coord;
    public:
        IllegalCoordinateException(coord c){
            _coord = c;
        }
        string theCoordinate() const{
            return to_string(_coord.x)+","+to_string(_coord.y);
        }
};


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

class xo{
    char x;
    
    public:
        
        char getChar() const{
            return x;
        }
        
        char& operator= (const char c){
            if(c == 'X' || c == 'O')
            {
                x = c;
            }
            else
            {
                throw IllegalCharException(c);
            }
            return x;
        }
        
        xo& operator= (const xo _xo){
            x = _xo.getChar();
            return *this;
        }
        
        friend std::ostream& operator<<(std::ostream& os, xo  &b);
        
        void clear(){
            x = '.';
        }
        
        
        operator char(){
            return x;
        }
};

class Board{
    
    private:
        
        coord _coord;
    	xo** board;
    	int size;
	
    public:
        Board();
        Board(int v);
        Board(const Board& b);
        ~Board();
        friend std::ostream& operator<<(std::ostream& os, Board const &b); 
        xo& operator[](coord c);
        Board& operator= (const char c);
        Board& operator= (const Board &b);
};


/*
class _map
{
    public:
        //data being what you have in your board
        _map& operator[] (struct coord) {
            this;
        }
        void operator= (char enter) {
            cout << enter;
        }        
        
};*/

#endif