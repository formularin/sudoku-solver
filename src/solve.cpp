/*=======================================
 solve.cpp:                     lol-cubes
 last modified:               Mon, Mar 23
 
 This file contains an implementation of
 the backtracking algorithm to solve a
 sudoku puzzle.
========================================*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {

    
    // Read file to 2d array of strings
    ifstream input_file(argv[1]);
    int grid[9][9];
    string line;
    int l = 0;
    while ( getline(input_file, line) ) {
        for (string::size_type c = 0; c < line.size(); c++) {
            string value;
            value.push_back(line[c]);
            grid[l][c] = stoi(value);
        }
        l++;
    }
    input_file.close();

    // Write output to file
    ofstream output_file(argv[2]);
    for ( int x = 0; x < 9; x++ ) {
        for ( int y = 0; y < 9; y++ ) {
            output_file << grid[x][y];
        }
        if (x != 8) {
            output_file << endl;
        }
    }
    output_file.close();

    return 0;
}