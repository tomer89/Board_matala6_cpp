#include "Champion.h"
#include <iostream>
using namespace std;

const Coordinate Champion::play(const Board& board) {
    
/*    //rows
    uint index = checkRowsCol(board,getChar(),0);
    if(index != -1){
        return block(board,index,0);
    }
    //columns
    index = checkRowsCol(board,getChar(),1);
    if(index != -1){
        return block(board,index,1);
    }*/
    
    //fillDia();
    
 
    
    if(board[{board.size()-1,0}] == '.'){
        return {board.size()-1,0};
    }
    else{
        for(uint rows = 0 ; rows < board.size() ; rows++){
                if(board[{rows , board.size() - (1+rows)}] == '.'){
                    //cout << "\n got here " << "{[" << rows << "," << board.size() - (1+rows) <<"}]" << endl;
                    return{rows,board.size() - (1+rows)};
                }
            }
        }
    }
    
    
/*	for (uint x=0; x<board.size(); ++x) {
		for (uint y=0; y<board.size(); ++y) {
			Coordinate c{x,y};
			if (board[c]=='.') {
				return c;
			}
		}
	}
	return {0,0};  // did not find an empty square - play on the top-left*/
//}




/*
int Champion::checkRowsCol(const Board& b, char c,int rowCol)
{
    char otherP;
    int rowCounter = 0;
    if('X' == c){
        otherP = 'O';
    }
    else{
        otherP = 'X';
    }
    bool found_other = false;
    if(rowCol == 0){
    	for (uint rows=0; rows<b.size(); ++rows) {
    		for (uint col=0; col<b.size() && !found_other; ++col) {
    			Coordinate c{rows,col};
    			char check = b[{rows,col}];
    			if ((check==otherP)) {
    			    rowCounter++;
    			}
    		}
    		if(rowCounter != (b.size() - 1) )
    		{
    		    return rows;
    		}
    	}
    }
    else{
    	for (uint col=0; col<b.size(); ++col) {
    		for (uint rows=0; rows<b.size() && !found_other; ++rows) {
    			Coordinate c{rows,col};
    			char check = b[{rows,col}];
    			if ((check==otherP)) {
    			    rowCounter++;
    			}
    		}
    		if(rowCounter != (b.size() - 1) )
    		{
    		    return col;
    		}
    	}
    }
	return -1;
}




Coordinate Champion::block(const Board& b, uint index, int rowCol) const{
    char c = getChar();
    if(c == 'X'){
        c = 'O';
    }
    else{
        c ='X';
    }
    
    if(rowCol == 0){
        for(uint col = 0 ; col < b.size() ; col++){
            if(b[{index,col}] != c){
                return {index,col};
            }
        }
    }else{
        for(uint rows = 0 ; rows < b.size() ; rows++){
            if(b[{rows,index}] != c){
                return {rows,index};
            }
        }
    }
}*/