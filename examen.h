
#ifndef EXAMEN_H
#define EXAMEN_H

#define BUF_SIZE 1024 

int getrows(FILE *);
int getcolumns(FILE *);
void readcsv(const char *);
const char* integrantes();
int *transpose(int *, int, int);

#endif


