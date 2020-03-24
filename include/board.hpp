/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 23
 
 The `Board` class, which represents a
 sudoku board.
========================================*/


#include <vector>

using namespace std;


class Board {
    public:
    vector< vector<int> > board;
    Board(vector< vector<int> >);
};