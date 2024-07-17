# Sudoku-Solver

This repository contains a C application that solves Sudoku puzzles using a backtracking algorithm. The application reads a Sudoku grid from a file, displays the grid, solves it, and then displays the solution.

## Features

- Loads a Sudoku grid from a text file.
- Uses a backtracking algorithm to solve the Sudoku puzzle.
- Displays the input Sudoku grid, solves the puzzle and displays the solution.

## Getting Started

### Prerequisites

- `GCC`.
- `make`.

### Building the Application

```sh
cd sudoku-solver
make
```

### Running the Application

1. Prepare a text file containing the Sudoku grid. The file should contain 9 lines with 9 numbers each, separated by spaces. Use `0` for empty cells. Example:
    ```
    9 1 3 0 0 0 5 0 0
    6 0 7 0 0 0 0 2 4
    0 5 0 0 8 0 0 7 0
    0 7 9 0 0 0 0 0 0
    0 0 2 0 9 0 0 4 3
    0 0 0 0 0 4 0 9 0
    0 4 0 0 0 1 9 0 0
    7 0 6 0 0 9 0 0 5
    0 0 1 0 0 6 4 0 7
    ```

2. Run the application with the file as an argument:
    ```
    ./sudoku_solver path/to/sudoku_file.txt
    ```

## File Structure

- `main.c` - The main entry point for the application.
- `solver.c` - Contains functions to solve a Sudoku puzzle.
- `sudoku.h` - Header file with function declarations and the `sudokuGrid` struct definition.
- `sudoku_io.c` - Contains functions to load the grid and print the grid.
- `Makefile` - Build script to compile the application.


## Example Output

```
Sudoku grid:

 9 1 3  0 0 0  5 0 0
 6 0 7  0 0 0  0 2 4
 0 5 0  0 8 0  0 7 0

 0 7 9  0 0 0  0 0 0
 0 0 2  0 9 0  0 4 3
 0 0 0  0 0 4  0 9 0

 0 4 0  0 0 1  9 0 0
 7 0 6  0 0 9  0 0 5
 0 0 1  0 0 6  4 0 7

Solution:

 9 1 3  4 2 7  5 8 6
 6 8 7  9 1 5  3 2 4
 2 5 4  6 8 3  1 7 9

 4 7 9  1 3 2  6 5 8
 1 6 2  5 9 8  7 4 3
 5 3 8  7 6 4  2 9 1

 3 4 5  8 7 1  9 6 2
 7 2 6  3 4 9  8 1 5
 8 9 1  2 5 6  4 3 7
```