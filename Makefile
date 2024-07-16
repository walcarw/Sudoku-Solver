CC=gcc
CFLAGS=-I.

build:
	$(CC) -o sudoku_solver src/main.c  src/sudoku_io.c