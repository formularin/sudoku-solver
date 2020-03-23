/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 23
 
 Method implementations for the `Board`
 class.
========================================*/


#include <vector>

#include "../include/board.hpp"

using namespace std;


Board::Board(int grid[9][9]) {
    /*
    Constructor for `Board` class.
    Takes `grid` argument and adds values to `board` attribute accordingly.
    */

    for ( int x = 0; x < 3; x++ ) {
        vector< vector< vector<int> > > box_row;
        for ( int y = 0; y < 3; y++ ) {
            vector< vector<int> > box;
            for ( int z = 0; y < 3; y++ ) {
                vector<int> row;
                for ( int w = 0; w < 3; w++ ) {
                    int val;
                    row.push_back(val);
                }
                box.push_back(row);
            }
            box_row.push_back(box);
        }
        board.push_back(box_row);
    }
}


vector< vector<int> > Board::grid() {
    /*
    Converts `board` attribue
    */

    vector<vector<int> > value_grid;

    for ( int x = 0; x < 3; x++ ) {
        for ( int y = 0; y < 3; y++ ) {
            for ( int z = 0; z < 3; z++ ) {
                for ( int w = 0; w < 3; w++ ) {
                    value_grid[(x*3)+z][(y*3)+w] = board[x][y][z][w];
                }
            }
        }
    }

    return value_grid;
}