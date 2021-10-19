/* Ανάστροφος πίνακας
   Vidras Ioannis
   4414002
   Sequencial algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "/home/giannisvidras/Documents/ptixiaki/myLibs/ragnlib.h"
#include "/home/giannisvidras/Documents/ptixiaki/myLibs/colib.h"

#define cores 8
int main(int argc, char const *argv[]) {

  int **A, **B;
  int N;
  int i, j, l, counter = 0;
  double CPU_time = 0.0;
  double Start = 0.0, Stop =0.0;
  srand(time(NULL));

  printf("\nInput the size of the matrix\t"BLU);
  scanf("%d",&N);

printf(RESET"\n");

  A = (int **)malloc(N * sizeof(int *));
      for(i=0;i<N;i++){
      A[i] = (int *)malloc(N * sizeof(int));
    }

    B = (int **)malloc(N * sizeof(int *));
        for(i=0;i<N;i++){
        B[i] = (int *)malloc(N * sizeof(int));
      }


  for(i=0; i<N; i++){
    for (j=0; j<N; j++) {
      A[i][j] = randomGen();
    }
  }

  for( l=1; l<=cores; l*=2){

     CPU_time = 0.0;
     Start = 0.0;
     Stop =0.0;

/* Initiating the B array every time with "zeros"
    for(i=0;i<N;i++){
      for (j = 0; j < N; j++) {
        B[i][j] = 0;
      }
    }
    */

      printf("\nBe patient, Waiting the the job with %d CPUs to end ",l );
  Start = omp_get_wtime();
    #pragma omp parallel for collapse(2) schedule(static) num_threads(l) private(i, j,) shared(A, B, N)
for (i=0; i<N; i++) {
  for (j=0; j<N; j++) {
    /* code */

    B[i][j] = A[j][i];
    }
  }
  Stop=omp_get_wtime();

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
    //CPU_time /= CLOCKS_PER_SEC;

/*
// checking if the operations are correct!
    for (i = 0; i <N; i++) {
      for (j = 0; j <N; j++) {


        if (B[i][j] != A[j][i]){
          counter++;
        }
        }
      }

*/
    printf(CYN"\nTime tooks to run in "GRN"(%d)"GRN" CPUs is " GRN "(%6.6f)"CYN"\n"RESET,l ,CPU_time);
    //printf("errors where appeared "GRN" (%2d)\n",counter);
    printf("\n");
  }
// Freeing Matrices from RAM
free(A);
free(B);

  return 0;
}
