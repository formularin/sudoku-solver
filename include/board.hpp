/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 23
 
 The `Board` class, which represents a
 sudoku board.
========================================*/


class Board {
    int board[3][3][3][3];

    public:
    Board(int[9][9]);
    int** grid();
};