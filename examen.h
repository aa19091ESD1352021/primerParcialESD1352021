
#ifndef EXAMEN_H
#define EXAMEN_H

#define BUF_SIZE 1024 

int getrows(FILE *);
int getcolumns(FILE *);
void readcsv(const char *);
const char* integrantes();
int *transpose(int *, int, int);
int *multiplyMatrices(int *first_array,int first_row, int first_column, int *second_array, int second_row, int second_column);

#endif


