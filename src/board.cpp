/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 25
 
 Method implementations for the `Board`
 class.
========================================*/


#include <algorithm>
#include <vector>

#include "../include/board.hpp"

using std::vector;


bool get_int_in_vector(vector<int> v, int x) {
    // Returns bool - whether or not x is in v
    return find(v.begin(), v.end(), x ) != v.end();
}


Board::Board(vector< vector<int> > grid) {
    for ( vector<int> row : grid ) {
        board.push_back(row);
    }
}


vector<int> Board::get_first_unfilled_point() {
    // Returns vector containing coords of first unfilled point
    // on board in form of {row, col}.

    vector<int> point(2);

    // Locate first unfilled point.
    bool found_point = false;
    for ( int r = 0; r < 9; r++ ) {
        for ( int c = 0; c < 9; c++ ) {
            if ( board[r][c] == 0 ) {
                point[0] = r;
                point[1] = c;
                break;
            }
        }
        if ( found_point ) {
            break;
        }
    }

    return point;
}


vector<int> Board::get_eligible_values(int row, int col) {
    // Returns all the eligible values for the
    // first unfilled box in this board.

    vector<int> eligible_values;

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


bool Board::is_solved() {
    // Whether or not this board has any unfilled cells.

    for ( vector<int> row : board ) {
        for ( int val : row ) {
            if ( val == 0 ) {
                return false;
            }
        }
    }

    return true;
}


int Board::solve() {
    // Fills unfilled points in board attribute with solution to puzzle.

    vector<int> first_unfilled_point = get_first_unfilled_point();
    int row = first_unfilled_point[0];
    int col = first_unfilled_point[1];
    vector<int> eligible_values = get_eligible_values(row, col);
    vector<int> tried_values;

    while (true) {
        // List of all eligible points that haven't
        // been tried in previous calls.
        vector<int> untried_values;
        for ( int val : eligible_values ) {
            if (!get_int_in_vector(tried_values, val)) {
                untried_values.push_back(val);
            }
        }
        if (untried_values.empty()) {
            // There are no possible values for this cell.
            return 1;
        } else {
            // Fills cell with eligible value.
            int index = std::rand() % untried_values.size();
            board[row][col] = untried_values[index];

            if ( is_solved() ) {
                return 0;
            }

            int solution = solve();
            if ( solution == 1 ) {
                board[row][col] = 0;
                tried_values.push_back(untried_values[index]);
            } else return 0;
        }
    }
}