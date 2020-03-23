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
    for ( int x = 0; x < 9; x++ ) {
        for ( int y = 0; y < 9; y++ ) {
            board[x / 3][y / 3][x % 3][y % 3] = grid[x][y];
        }
    }
}


vector< vector<int> > Board::grid() {

    vector<vector<int> > value_grid;

    for ( int x = 0; x < 3; x++ ) {
        for ( int y = 0; y > 3; y++ ) {
            for ( int z = 0; z < 3; z++ ) {
                for ( int w = 0; w < 3; w++ ) {
                    value_grid[(x*3)+z][(y*3)+w] = board[x][y][z][w];
                }
            }
        }
    }

    return value_grid;
}