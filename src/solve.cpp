/*=======================================
 solve.cpp:                     lol-cubes
 last modified:               Mon, Mar 23
 
 Solves a sudoku puzzle.
 ./solve [input_file] [output_file]
 See README.md for more information.
========================================*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/board.hpp"

using namespace std;


void print_2d(vector< vector<int> > grid) {
    // Pretty prints a 2d vector as a matrix
    for ( vector<int> row : grid ) {
        for ( int val : row ) {
            cout << val;
            cout << " ";
        }
        cout << endl;
    }
}


int main(int argc, char** argv) {

    // Read file to 2d array of strings
    ifstream input_file(argv[1]);
    vector< vector<int> > grid;
    string line;
    int l = 0;
    while ( getline(input_file, line) ) {
        vector<int> row;
        for (string::size_type c = 0; c < line.size(); c++) {
            string value;
            value.push_back(line[c]);
            row.push_back(stoi(value));
        }
        grid.push_back(row);
        l++;
    }
    input_file.close();

    print_2d(grid);

    // Create Board object and solve puzzle
    Board board = Board(grid);

    // Write output to file
    ofstream output_file(argv[2]);
    for ( int x = 0; x < 9; x++ ) {
        for ( int y = 0; y < 9; y++ ) {
            output_file << board.board[x][y];
        }
        if (x != 8) {
            output_file << endl;
        }
    }
    output_file.close();

    return 0;
}