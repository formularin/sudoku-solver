/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 25
 
 The `Board` class, which represents a
 sudoku board.
========================================*/


#include <vector>

using namespace std;


class Board {
    vector<int> get_eligible_values();

    public:
    vector< vector<int> > board;
    Board(vector< vector<int> >);
};