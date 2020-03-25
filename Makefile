CC = g++
BINDIR = bin
V = 11

all: sudoku-solver

sudoku-solver:
	@mkdir ${BINDIR}
	@echo "compiling sudoku-solver..."
	@${CC} -std=c++${V} src/main.cpp src/utils.cpp src/board.cpp -o ${BINDIR}/sudoku-solver
	@echo "done"

install:
	@install -m 0755 ${BINDIR}/sudoku-solver /usr/local/bin
	@echo "installed sudoku-solver in /usr/local/bin"