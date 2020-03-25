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
    for ( vector<int> row : grid ) {
        for ( int val : row ) {
            std::cout << val;
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}