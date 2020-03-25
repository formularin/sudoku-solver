# sudoku-solver

Solves sudoku puzzles.

## Installation

```
git clone https://github.com/lol-cubes/sudoku-solver.git
cd sudoku-solver
make
make install
```

## Usage

`cat [input_file] | sudoku-solver`

Example `input_file`:

```
400002830
080104002
706080500
100007050
270500019
030940006
008090705
300806090
042700003
```

This will print out the solved board.
Redirect output to file using:

`cat [input_file] | sudoku-solver > [output_file]`