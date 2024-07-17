#include "sudoku.h"
#include <stdbool.h>

/**
 * Checks if a number can be placed using the following two rules:
 *      - A number can appear only once per row.
 *      - A number can appear only once per column.
 * 
 * @param[in] grid A pointer to the Sudoku grid.
 * @param[in] row The index of the row where the number is to be placed.
 * @param[in] column The index of the column where the number is to be placed.
 * @param[in] num The number that we want to place.
 * 
 * @return true if the number can be placed, false otherwise.
 */
bool checkRowColumn(sudokuGrid *grid, int row, int column, int num){
    for (int i=0; i < 9; i++){
        if (grid->matrix[row][i] == num){
            // The number cannot be placed in the row
            return false;
        }
        if (grid->matrix[i][column] == num){
            // The number cannot be placed in the column
            return false;
        }
    }
    return true;
}

/**
 * This function calculates the starting index of a square (0, 3, or 6).
 * 
 * @param[in] index The index for which the starting square index needs to be determined.
 * 
 * @returns The starting index of the square containing the given index.
 *          - Returns 0 if the index is within the first square.
 *          - Returns 3 if the index is within the second square.
 *          - Returns 6 if the index is within the third square.
 */
int getStartingSquare(int index){
    int tmp = index - 3;
    if (tmp < 0){
        // First Square
        return 0;
    }
    tmp = tmp - 3;
    if (tmp < 0){
        // Second Square
        return 3;
    }
    // Third Square
    return 6;
}


/**
 * Checks if a number can be placed in a square.
 * 
 * @param[in] grid A pointer to the Sudoku grid.
 * @param[in] row The index of the row where the number is to be placed.
 * @param[in] column The index of the column where the number is to be placed.
 * @param[in] num The number that we want to place.
 * 
 * @return true if the number can be placed, false otherwise.
 */
bool checkSquare(sudokuGrid *grid, int row, int column, int num){
    int rowIndex = getStartingSquare(row);
    int columnIndex = getStartingSquare(column);
    for (int i=0; i < 3; i++){
        for (int j=0; j < 3; j++){
            if (grid->matrix[rowIndex + i][columnIndex + j] == num){
                return false;
            }
        }
    }
    return true;
}


/**
 * Determines if a number can be placed in a cell
 * 
 * @param[in] grid A pointer to the Sudoku grid.
 * @param[in] row The index of the row where the number is to be placed.
 * @param[in] column The index of the column where the number is to be placed.
 * @param[in] num The number that we want to place.
 * 
 * @return true if the number can be placed, false otherwise.
 */
bool canBePlaced(sudokuGrid *grid, int row, int column, int num){
    return checkRowColumn(grid,row,column,num) && checkSquare(grid, row, column, num);
}


/**
 * Solves a Sudoku using a backtracking algorithm
 * 
 * @param[in] grid The Sudoku grid
 */
void backtracking_solve(sudokuGrid *grid){
    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            if (grid->matrix[row][column] == 0){
                for (int num = 1; num < 10; num++){
                    if (canBePlaced(grid, row, column, num)){
                        grid->matrix[row][column] = num;
                        backtracking_solve(grid);
                        grid->matrix[row][column] = 0;
                    }
                }
                return;
            }
        }
    }
    printGrid(grid);
}