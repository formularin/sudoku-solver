/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 25
 
 The `Board` class, which represents a
 sudoku board.
========================================*/


#include <vector>

using std::vector;


class Board {
    vector<int> get_first_unfilled_point();
    vector<int> get_eligible_values(int row, int col);
    bool is_solved();

    public:
    vector< vector<int> > board;
    Board(vector< vector<int> >);
    int solve();
};