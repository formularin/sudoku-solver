/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 23
 
 The `Board` class, which represents a
 sudoku board.
========================================*/


#include <vector>

using namespace std;


class Board {
    vector< vector< vector< vector<int> > > > board;

    public:
    Board(int[9][9]);
    vector< vector<int> > grid();
};