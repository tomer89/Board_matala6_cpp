/**
 * My git: https://github.com/tomer89/Board_matala6_cpp.git
 * HW:	   https://github.com/erelsgl/ariel-cpp-5778/tree/master/week05-copy-friend/homework
 * 
 * 
 */ 



//#include "Board.h"

#include <iostream>
#include <vector>
#include <map>
using namespace std;


struct coord {
    int x;
    int y;
};

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
        
};



int main() {
	int shira[10];
	int* tomer = new int[10];
	map<vector<int>, char> a;
	a[{1,1}]='X';
	cout << a[{9,1}];
	//vector<vector<int> > matrix(50);
	/*for ( int i = 0 ; i < matrix.size() ; i++ )
		matrix[i].resize(50);
	matrix[{1,1}]=1;*/
	_map ppp;
	ppp[{1,2}] = 'X';
	//maybe map
	//mat[{1,1}]=1;
/*	Board board1{4};			// Initializes a 4x4 board
	cout << board1 << endl;   */
								/* Shows an empty board:
								....
								....
								....
								....
								*/
/*	board1[{1,1}]='X';
	board1[{1,2}]='O';
	cout << board1 << endl;  */
								/* Shows the following board:
								....
								.XO.
								....
								....
								*/

/*	try {
		board1[{3,4}]='O';  	// This should raise an exception
	} catch (const IllegalCoordinateException& ex) {
		cout << "Illegal coordinate: " << ex.theCoordinate() << endl;  // prints "Illegal coordinate: 3,4"
	}

	board1 = '.';   		   // Fill the entire board with "."
	cout << board1 << endl;    // Shows an empty board, as above 
	try { 
		board1 = 'a';          // This should raise an exception
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: a"
	}

	try {
		board1[{0,1}] = 'x';   // This should raise an exception
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: x"
	}

	Board board2 = board1;
	board2[{0,0}] = 'X';
	cout << board1 << endl;    // Shows an empty board, as above 
	cout << board2 << endl;    // Shows a board with an X at top-left 

	board1 = board2;
	board1[{3,3}] = 'O';
	cout << board2 << endl;    // Shows a board with an X at top-left
	cout << board1 << endl;    // Shows a board with an X at top-left and O at bottom-right 

	cout << "Good bye!" << endl;*/

	return 0;
}




/*int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}*/