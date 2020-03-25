/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 25
 
 Method implementations for the `Board`
 class.
========================================*/


#include <algorithm>
#include <vector>

#include "../include/board.hpp"

using namespace std;


bool get_int_in_vector(vector<int> v, int x) {
    // Returns bool - whether or not x is in v
    return find(v.begin(), v.end(), x ) != v.end;
}


Board::Board(vector< vector<int> > grid) {
    for ( vector<int> row : grid ) {
        board.push_back(row);
    }
}


vector<int> Board::get_eligible_values() {
    // Returns all the eligible values for the
    // first unfilled box in this board.

    vector<int> eligible_values;
    // Coordinates of first unfilled point.
    int row;
    int col;

    // Locate first unfilled point.
    bool found_point = false;
    for ( int r = 0; r < 9; r++ ) {
        for ( int c = 0; c < 9; c++ ) {
            if ( board[r][c] == 0 ) {
                row = r;
                col = c;
                break;
            }
        }
        if ( found_point ) {
            break;
        }
    }

    // Fill eligible_values.
    for ( int i = 1; i < 10; i++ ) {
        
        // Check row.
        if (get_int_in_vector(board[row], i)) continue;

        // Vector of values in column.
        vector<int> column;
        for ( int r = 0; r < 9; r++ ) {
            column.push_back(board[r][col]);
        }
        // Check column.
        if (get_int_in_vector(column, i)) continue;

        // Vector of values in box.
        vector<int> box_values(3);
        for ( int y = 0; y < 3; y++ ) {
            for ( int x = 0; x < 3; x++ ) {
                box_values.push_back(
                    board[((row / 3) * 3) + y][((col / 3) * 3) + x]
                );
            }
        }
        // Check box.
        if (get_int_in_vector(box_values, i)) continue;

        eligible_values.push_back(i);
    }

    return eligible_values;
}