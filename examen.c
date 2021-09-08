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

void readcsv(const char path) {

}

const char * integrantes() {
  static char grupo[] = "AA19091,RF18025";
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

int *multiplyMatrices(int *first_array, int first_row, int first_column, int *second_array, int second_row, int second_column) {

  if (first_column == second_row) {
    int aux;
    int *result = (int*) malloc(first_row * second_column * sizeof (int));
    for (int i = 0; i < first_row; i++) {
      for (int j = 0; j < second_column; j++) {
        aux = 0;
        for (int x = 0; x < first_column; x++) {
          aux += (*(first_array + i * first_column + x)) * (*(second_array + x * second_column + j));
        }
        *(result + i * second_column + j) = aux;
      }
    }
    return result;
  } else {
    puts("dimensiones incorrectas");
    exit(0);
  }
}

int *generateMatrices(const char * path) {

  FILE *pointer_file;
  pointer_file = fopen(path, "r");
  if (pointer_file == NULL) {
    puts("Error no se pudo abrir el archivo");
    exit(1);

  }


  char temp[BUF_SIZE];
  char aux;
  char *character;
  int rows = 0;
  int columns = 0;

  while (!feof(pointer_file)) {
    fgets(temp, BUF_SIZE, pointer_file);
    rows++;
  }

  rewind(pointer_file);
  while (aux != '\n') {
    aux = fgetc(pointer_file);

    if (aux == 44) {
      columns++;
    }
  }

  int *array = (int *) malloc((rows - 1)*(columns) * sizeof (int));
  for (int i = 0; i < (rows - 1); i++) {
    int j = 0;
    while (aux != ',') {
      aux = fgetc(pointer_file);

    }

    while (aux != '\n' && aux != EOF) {
      aux = fgetc(pointer_file);
      if (aux != ',' && aux != EOF && aux != '\n') {
        character = &aux;
        *(array + i * columns + j) = atoi(character);
        j++;
      }
    }
  }

  fclose(pointer_file);
  return array;
}


