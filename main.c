#include <stdio.h>
#include <stdlib.h>
#include "examen.h"

int main(int argc, char** argv) {
  
  int matriz[3][2] = {1,2,3,4,5,6};
  int array2d[2][3] = {1,2,3,4,5,6};
  
  int *result = multiplyMatrices(&matriz[0][0],3,2,&array2d[0][0],2,3);
  
  int i;
  for (i = 0; i < 3; i++) {
    int j;
    for ( j= 0; j < 3; j++) {
      printf("%d,",*(result+i*3+j));

    }
    puts("");

  }


  return (EXIT_SUCCESS);
}

