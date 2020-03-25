/*=======================================
 solve.cpp:                     lol-cubes
 last modified:               Mon, Mar 23
 
 Solves a sudoku puzzle.
 ./solve [input_file] [output_file]
 See README.md for more information.
========================================*/


#include <iostream>
#include <string>
#include <vector>

#include "../include/board.hpp"
#include "../include/utils.hpp"

using std::vector;


int main(int argc, char** argv) {

    // Convert input to 2d array of int.
    vector< vector<int> > grid;
    int l = 0;
    for ( std::string line; std::getline(std::cin, line); ) {
        vector<int> row;
        for ( std::string::size_type c = 0; c < line.size(); c++ ) {
            std::string value;
            value.push_back(line[c]);
            row.push_back(stoi(value));
        }
        grid.push_back(row);
        l++;
    }

    // Create Board object and solve puzzle.
    Board board = Board(grid);
    board.solve();

    // Print output.
    print_2d(board.board);
    return 0;
}