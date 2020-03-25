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
        for ( int v = 0; v < row.size(); v++ ) {
            std::cout << row[v];
            if ( v < row.size() - 1 ) std::cout << " ";
        }
        if ( r < grid.size() - 1 ) std::cout << std::endl;
    }
    std::cout.flush();
}