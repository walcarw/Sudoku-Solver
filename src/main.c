#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"


int main(){
    printf("Loading the Sudoku grid.\n");
    sudokuGrid *grid = loadGrid("example.txt");
    printGrid(grid);
    free(grid);
    return 0;
}