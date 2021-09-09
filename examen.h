
#ifndef EXAMEN_H
#define EXAMEN_H

#define BUF_SIZE 2048 

typedef char dataType [2048];

int getrows(FILE *);
int getcolumns(FILE *);
char *readcsv(const char *);
const char* integrantes();
int *transpose(int *, int, int);
int *multiplyMatrices(int *first_array, int first_row, int first_column, int *second_array, int second_row, int second_column);
int *generateMatrices(const char *);

#endif


