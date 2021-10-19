#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 4


int main(){

  float A[N][N], B[N][N];
  int i, j, k;
  float det;
  srand(time(NULL));

  printf("\n\n");
  printf("\t\tARRAY A\n\n");

  for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        printf("\n Give the i=%d, j=%d\n",i+1, j+1);
          scanf("%f", &A[i][j]);
          //A[i][j] = matrix[i][j];
      }
  }
  printf("\nGive determinant \n");
  scanf("$f\n",&det);

  for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){

          B[i][j] = A[i][j];
          A[i][j] /=det;
          //A[i][j] = matrix[i][j];
      }
  }

printf("\tA\n");
  for(i=0; i<N; i++){
    printf("\n");
    for (j = 0; j < N; j++) {
      printf("%5.6f\t",A[i][j]);
    }
  }
printf("\tB\n" );
  for(i=0; i<N; i++){
    printf("\n");
    for (j = 0; j < N; j++) {
      printf("%5.6f\t",B[i][j]);
    }
  }


return 0;
}
