/* Ανάστροφος πίνακας
   Vidras Ioannis
   4414002
   Sequencial algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../myLibs/ragnlib.h"
#include "../myLibs/colib.h"

//#define N 250
int main(int argc, char const *argv[]) {

  int **A, **B;
  int N;
  int i, j, counter = 0;
  double CPU_time;
  time_t Start, Stop;
  srand(time(NULL));

  printf("\nInput the size of the matrix\t"CYN);
  scanf("%d",&N);


  A = (int **)malloc(N * sizeof(int *));
      for(i=0;i<N;i++){
      A[i] = (int *)malloc(N * sizeof(int));
    }

    B = (int **)malloc(N * sizeof(int *));
        for(i=0;i<N;i++){
        B[i] = (int *)malloc(N * sizeof(int));
      }


  for(i=0;i<N;i++){
    for (j = 0; j < N; j++) {
      A[i][j] = randomGen();
    }
  }
  Start=clock();
for (i = 0; i <N; i++) {
  for (j = 0; j <N; j++) {
    /* code */

    B[i][j] = A[j][i];
    }
  }
  Stop=clock();

/*
//Print statements for the Matrices
    printf(GRN"\n\nMatrix A\n"RESET);
  for (i = 0; i <N; i++) {
    printf("\n");
    for (j = 0; j <N; j++) {

      printf(MAG"(%2d)\t",A[i][j] );
      }
    }

    printf(YEL"\n\nMatrix B\n"RESET);
  for (i = 0; i <N; i++) {
    printf("\n");
    for (j = 0; j <N; j++) {

      printf(RED"(%2d)\t",B[i][j] );
      }
    }
    */

    CPU_time = Stop - Start;
    CPU_time /= CLOCKS_PER_SEC;


    for (i = 0; i <N; i++) {
      for (j = 0; j <N; j++) {
        /* code */

        if (B[i][j] != A[j][i]){
          counter++;
        }
        }
      }


    printf(RESET"\n\nTime needs to run sequencialy " GRN "%6.6f"RESET" errors where appeared "BLU" %2d\n"RESET,CPU_time,counter);
    printf("\n");
// Freeing Matrices from RAM
free(A);
free(B);

  return 0;
}
