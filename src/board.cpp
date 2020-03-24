/*=======================================
 board.hpp:                     lol-cubes
 last modified:               Mon, Mar 23
 
 Method implementations for the `Board`
 class.
========================================*/


#include <vector>

#include "../include/board.hpp"

using namespace std;


Board::Board(vector< vector<int> > grid) {
    for ( vector<int> row : grid ) {
        board.push_back(row);
    }
}