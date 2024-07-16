#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "sudoku.h"

#define LINE_BUFF_SIZE 20
#define LINE_SIZE 17



sudokuGrid* loadGrid(char filename[]){
    FILE *fptr;
    sudokuGrid *grid = malloc(sizeof(sudokuGrid));
    fptr = fopen(filename, "r");

    if (fptr == NULL){
        fprintf(stderr,"Cannot open the file '%s'\n", filename);
        exit(1);
    }

    char line[LINE_BUFF_SIZE];

    for (int lineNb = 0; lineNb < 9; lineNb++){
        // Reads a line from the file
        fgets(line,LINE_BUFF_SIZE,fptr);
        // Checks that the line contains 9 numbers
        for (int i=0; i < LINE_SIZE; i+=2){
            if (isdigit(line[i])){
                // Convertion: char -> int
                int num = (int) line[i] - (int) '0';
                grid->matrix[lineNb][i/2] = num;
            } else {
                fprintf(stderr,"Invalid format. The file '%s' doesn't contain a correct sudoku grid\n", filename);
                exit(1);
            }
        }
    }

    fclose(fptr);
    return grid;
}


void printGrid(sudokuGrid *grid){
    printf("\n");
    for (int line=0; line < 9; line++){
        for (int column=0; column < 9; column++){
            if (column % 3 == 0){
                // Adds an empty column between each blocs
                printf(" %d ", grid->matrix[line][column]);
            } else {
                printf("%d ", grid->matrix[line][column]);
            }
        }
        printf("\n");
        if (line % 3 == 2){
            // Adds an empty line between each blocs
            printf("\n");
        }
    }
}