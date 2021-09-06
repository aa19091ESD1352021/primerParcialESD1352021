#include <stdio.h>
#include <stdlib.h>
#include "examen.h"
#include <string.h>

int getrows(FILE * pointer_file) {

    size_t row_counter = 1;
    char buffer = fgetc(pointer_file);

    while (!feof(pointer_file)) {

        if (buffer == '\n')
            row_counter++;

        buffer = fgetc(pointer_file);
    }

    return row_counter;
}

int getcolumns(FILE * pointer_file) {
    size_t column_counter = 1;

    char buffer[BUF_SIZE];
    if (fgets(buffer, BUF_SIZE, pointer_file)) {

        int i;
        for (i = 0; i < strlen(buffer) - 1; i++) {

            if (buffer[i] == ',') {
                column_counter++;
            }

        }

    }

    return column_counter;
}

void readcsv(const char * path) {

}

const char * integrantes() {
    static char grupo[] = {"AA19091,RF18025"};
    return grupo;
}

int * transpose(int *array, int rows, int columns) {
    int i;
    int j;

    int *transpose_array = (int *) malloc(columns * rows * sizeof (int));
    // se debe liberar la memoria despues de usar la funcion! 

    for (i = 0; i < rows; i++) {

        for (j = 0; j < columns; j++) {
            *(transpose_array + j * rows + i) = *(array + i * columns + j);
        }
    }

    return transpose_array;
}