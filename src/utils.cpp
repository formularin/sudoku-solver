/*=======================================
 utils.cpp:                     lol-cubes
 last modified:               Mon, Mar 25
 
 Implementations for utils.hpp
========================================*/


#include <iostream>
#include <vector>

#include "../include/utils.hpp"

using std::vector;


bool get_int_in_vector(vector<int> v, int x) {
    // Returns bool - whether or not x is in v
    return find(v.begin(), v.end(), x ) != v.end();
}


void print_2d(vector< vector<int> > grid) {
    // Pretty prints a 2d vector as a matrix
    for ( int r = 0; r < grid.size(); r++ ) {
        vector<int> row = grid[r];
        for ( int val : row ) {
            std::cout << val;
            std::cout << " ";
        }
        if ( !(r == grid.size() - 1) ) std::cout << std::endl;
    }
    std::cout.flush();
}


void reset_cursor() {
    // Moves cursor up 8 lines.
    for ( int i = 0; i < 8; i++ ) {
        std::cout << "\033[F";
    }
    std::cout.flush();
}