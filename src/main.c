#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

/**
 * @brief Main function to load a Sudoku grid from a file, solve it, and display the results.
 *
 * @param argc Argument count.
 * @param argv Argument vector containing command line arguments.
 * @return Exit status.
 */
int main(int argc, char *argv[]){
    if (argc < 2){
        fprintf(stderr, "Error: Please provide a file as an argument.\n");
        return 1;
    }
        
    sudokuGrid *grid = loadGrid(argv[1]);
    printf("Sudoku grid:\n");
    printGrid(grid);
    printf("Solution:\n");
    backtracking_solve(grid);
    free(grid);
    return 0;
}