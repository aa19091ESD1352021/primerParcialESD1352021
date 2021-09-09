#include <stdio.h>
#include <stdlib.h>
#include "examen.h"

int main(int argc, char** argv) {
    
    
    const char path[] = "E:\\Desktop\\Examen_Estructuras2021\\archivos\\peliculasFavoritasESD135_2021.csv";
    
    dataType *read = readcsv(path);
    

    return (EXIT_SUCCESS);
}

