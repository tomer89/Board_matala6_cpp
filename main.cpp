/**
 * My git:			https://github.com/tomer89/Board_matala6_cpp.git
 * HW:				https://github.com/erelsgl/ariel-cpp-5778/tree/master/week05-copy-friend/homework    //in ass. num 5 add "real" to url
 * HW7:				https://github.com/erelsgl/ariel-cpp-5778/tree/master/week06-inheritance/homework
 * https:			//ide.geeksforgeeks.org/index.php
 * For compiling:	g++ -std=c++0x main.cpp Board.cpp IllegalCoordinateException.cpp TicTacToe.cpp DummyPlayers.cpp 
 * Auto checking6:  http://31.154.73.178:8008/?backend=5678&exercise=EX6
 * course git:      https://github.com/erelsgl/ariel-cpp-5778
 * 
 * Polymorphizm
 //*/ 




#include "TicTacToe.h"
#include "DummyPlayers.h"
/*#include "Champion.h"*/

void printResults(const TicTacToe& game) {
	cout << endl << "The final board is " << endl << game.board();
	cout << "And the winner is " << game.winner().name() 
	     << ", playing as " << game.winner().getChar() << "!" << endl;
}

void playAndPrintResults(TicTacToe& game, Player& xPlayer, Player& oPlayer) {
	game.play(xPlayer, oPlayer);
	printResults(game);
}

void playAndPrintWinner(TicTacToe& game, Player& xPlayer, Player& oPlayer) {
	game.play(xPlayer, oPlayer);
	cout << "The winner is " << game.winner().name() 
	     << ", playing as " << game.winner().getChar() << "!" << endl;
}


int main() {
	TicTacToe game(4);       // Initializes a game on a 4x4 board
	XYPlayer player1;
	YXPlayer player2;
	IllegalPlayer player3;
	ExceptionPlayer player4;

	playAndPrintResults(game, player1, player2);
	/*
		The final board is 
		XXXX
		O...
		O...
		O...
    	And the winner is XYPlayer, playing as X!
	*/

//	playAndPrintResults(game, player2, player1);  
	/*
		The final board is 
		XOOO
		X...
		X...
		X...
        And the winner is YXPlayer, playing as X!
	*/

//	playAndPrintResults(game, player1, player3);  
	/*
		The final board is 
		X...
		....
		....
		....
        And the winner is XYPlayer, playing as X!
	*/


//	playAndPrintResults(game, player3, player1);  
	/*
		The final board is 
		XO..
		....
		....
		....
        And the winner is XYPlayer, playing as O!
	*/

//	playAndPrintResults(game, player2, player4);  
	/*
		The final board is 
		X...
		....
		....
		....
		And the winner is YXPlayer, playing as X!
	*/

//	playAndPrintResults(game, player4, player2);  
	/*
		The final board is 
		....
		....
		....
		....
		And the winner is YXPlayer, playing as O!
	*/


/*	Champion champion;
	playAndPrintWinner(game, champion, player1);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player1, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player2);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player2, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player3);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player3, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player4);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player4, champion);
		// The winner is <your name>, playing as O!
*/
	return 0;
}




//stuff for personal use:






/*

class Board
{
	
	struct coord
	{
	    int x;
	    int y;
	};
	coord _coord;
	char** board;
	int size;
	
  public:
	  
	Board(int v);
	~Board();
    friend std::ostream& operator<<(std::ostream& os, Board const &b); 
	char& operator[](coord c)
	{
	    return board[c.x][c.y];
	}
};




Board::Board(int v)
{
	size = v;
	board = new char* [size];

	for (int i=0; i<size; i++)
	{
    	board[i] = new char[size];
    	for(int j = 0 ; j < size ; j++){
    		board[i][j] = '*';
    	}
	}
}

Board::~Board(){
    for(int i = 0 ; i < size ; i++){
        delete board[i];
    }
    delete board;
}


ostream& operator<<(std::ostream& os, Board const &b)
{
    for(int i = 0 ; i < b.size ; i++){
        for(int j = 0 ; j < b.size ; j++){
            cout << b.board[i][j] << " ";
        }
        cout << endl;
    }
    cout << " "  << endl;
    
}
*/













/*struct A
{
    void operator=(char)
    {
        std::cout << "foo = ...\n";
    }
    
    operator char()
    {
        std::cout << "... = foo\n";
        return 'a';
    }
};*/

/*class Board
{
	public:
    Board operator[](struct coord c)
    {
        return Board();
    }
    
    
    void operator=(char)
    {
        std::cout << "foo = ...\n";
    }
    
    operator char()
    {
        std::cout << "... = foo\n";
        return 'a';
    }
};
*/
