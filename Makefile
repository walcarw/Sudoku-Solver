CC=gcc
CFLAGS=-I.

build:
	$(CC) -o main src/main.c  src/sudoku_io.c