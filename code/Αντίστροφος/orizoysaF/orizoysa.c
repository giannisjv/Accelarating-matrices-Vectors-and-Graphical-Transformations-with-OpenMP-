#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define randomness 10

int main(int argc, char const *argv[]) {
  /* code */

  srand(time(NULL));
  int N, i, j;
  int **A, **B;
  printf("Give the N: ");
  scanf("%d",&N);

printf("\n");

  int RowsA, ColumnsA;

  int orizousa1, sum1[N], orizousa2, sum2[N], orizousa;


  RowsA =    N * sizeof(int *);
  ColumnsA = N * sizeof(int);




A = (int **)malloc(RowsA);
  for(i=0;i<N;i++){
    A[i] = (int *)malloc(ColumnsA);
  }

  if(!A){
  printf("\n!A \n" );
    return -1;
  }

/*
  int RowsB, ColumnsB;
  RowsB =    N * sizeof(int *);
  ColumnsB = N * sizeof(int);

  B = (int **)malloc(RowsB);
    for(i=0;i<N;i++){
      B[i] = (int *)malloc(ColumnsB);
    }
*/


  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      A[i][j] = rand() % randomness +1;
    }
  }

    printf("\n\n");

  for(i=0; i<N; i++){
    printf("\n");
    for(j=0; j<N; j++){
      printf("\t%d",A[i][j] );
    }
  }

  printf("\n\n");

  for(i=0; i<N; i++){

    //printf("\n");
    for(j=0; j<N; j++){
      if(i==j){
        sum1[i] = A[i][j];

    }
    else if(N-i-1 == j){
      sum2[i] = A[i][j];

    }
      /*else
      { printf("\t0");
    }*/
  }
  }

    orizousa1 =  sum1[0] * sum1[1];
    orizousa2 = sum2[0] * sum2[1];

    orizousa = orizousa1 - orizousa2;

  printf("\nOrizousa1 %d\n",orizousa);

printf("\n\n");
  free(A);




  return 0;
}
