struct sudokuGrid{
    int matrix[9][9];
} typedef sudokuGrid;


/**
 * Loads a Sudoku grid from a specified file.
 *
 * This function attempts to open the provided file and read a Sudoku grid
 * from it. If the file cannot be opened, or if the file does not contain
 * a Sudoku grid in the correct format, the program will terminate.
 *
 * @param[in] filename The name of the file containing the Sudoku grid.
 * @return Returns a pointer to a struct representing the Sudoku grid. 
    The caller is responsible for freeing the memory of the struct.
 */
sudokuGrid* loadGrid(char filename[]);

/**
 * Prints a Sudoku grid.
 * 
 * @param[in] grid A pointer to the Sudoku grid to print.
 */
void printGrid(sudokuGrid *grid);