/**
 * My git:			https://github.com/tomer89/Board_matala6_cpp.git
 * HW:				https://github.com/erelsgl/ariel-cpp-5778/tree/master/week05-copy-friend/homework    //in ass. num 5 add "real" to url
 * HW7:				https://github.com/erelsgl/ariel-cpp-5778/tree/master/week06-inheritance/homework
 * https:			//ide.geeksforgeeks.org/index.php
 * For compiling:	g++ -std=c++0x main.cpp Board.cpp IllegalCoordinateException.cpp TicTacToe.cpp DummyPlayers.cpp Champion.cpp
 * Auto checking6:  http://31.154.73.178:8008/?backend=5678&exercise=EX6
 * course git:      https://github.com/erelsgl/ariel-cpp-5778
 * 
 * Polymorphizm
 //*/ 




#include "TicTacToe.h"
#include "DummyPlayers.h"
#include "Champion.h"
#include <fstream>

#include "Board.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
	Board board;
	cin >> board;
	string filename = board.draw(600);
	//cout << filename << endl;*/
}