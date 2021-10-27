/* Ανάστροφος πίνακας
   Vidras Ioannis
   4414002
   Parallel of transponse algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define cores 4
#define NN 30
int main(int argc, char const *argv[]) {

  int **A, **B;
  int CPUS[NN], N[NN] , metr, mat=0;
  double Metrics[NN];
  int i, j, l, counter = 0;
  int loop_start = 100, loop_end = 1000, loop_step = 100;



printf(YEL"\n|----------------------------------------------------------------------------|\n");
printf("|\tThe transponse of a matrix in Linear Algebra\n");
printf("|\tis the matrix flipped by the axis\n");
printf("|\tfor example the [i] will be [j], the [j] will be [i]\n");
printf("|\tAnd the simbol is [A]T = A\n");
printf("|\tIf the matrix flip again\n|\twill give the first matrix");
printf("\n|----------------------------------------------------------------------------|\n");
  /*printf(GRN"\nInput the size of the matrix: "RESET);
  scanf("%d",&metr);*/

  for(metr = loop_start; metr <= loop_end; metr += loop_step){


  double CPU_time = 0.0;
  double Start = 0.0, Stop =0.0;
  A = (int **)malloc(metr * sizeof(int *));
      for(i=0; i<metr; i++){
        A[i] = (int *)malloc(metr * sizeof(int));
    }

    B = (int **)malloc(metr * sizeof(int *));
        for(i=0; i<metr; i++){
          B[i] = (int *)malloc(metr * sizeof(int));
      }


  for(i=0; i<metr; i++){
    for (j=0; j<metr; j++) {
      A[i][j] = randomGenInteger(1, 2500);
    }
  }

  for( l=1; l<=cores; l*=2){

/* If the l == 1 (l = core) the program doesn't need the #pragma to run so it disengaged! */ 
    if(l == 1){
        clock_t seq_Start = clock();
      for (i=0; i<metr; i++) {
        for (j=0; j<metr; j++) {
         B[i][j] = A[j][i];
    }
  }
  clock_t seq_End = clock();

  double time_tooks = (double) (seq_End - seq_Start) /CLOCKS_PER_SEC;
  Metrics[mat] = time_tooks;
  CPUS[mat] = l;
  N[mat] = metr;
  mat++;
  //printf(CYN"\nTime needs to run Sequentialy is " GRN "(%6.6f)"CYN"\n"RESET,time_tooks);
  //printf("\n");
    } else{

     CPU_time = 0.0;
     Start = 0.0;
     Stop =0.0;

  Start = omp_get_wtime();
    #pragma omp parallel for collapse(2) schedule(static) num_threads(l) private(i, j,) shared(A, B, metr)
      for (i=0; i<metr; i++) {
        for (j=0; j<metr; j++) {
          B[i][j] = A[j][i];
    }
  }
  Stop=omp_get_wtime();

   CPU_time = Stop - Start;
    Metrics[mat] = CPU_time;
    CPUS[mat] = l;
    N[mat] = metr;
  mat++;
 /*
    printf(CYN"Time needed to run in "GRN"(%d)"CYN" CPU cores is " GRN "(%6.6f)"CYN"\n"RESET,l ,CPU_time);
    //printf("errors where appeared "GRN" (%2d)\n",counter);
    printf("\n");*/

}
/*
//Print statements for the Matrices
    printf(GRN"\n\nMatrix A\n"RESET);
  for (i = 0; i <metr; i++) {
    printf("\n");
    for (j = 0; j <metr; j++) {

      printf(MAG"(%2d)\t",A[i][j] );
      }
    }

    printf(YEL"\n\nMatrix B\n"RESET);
  for (i = 0; i <metr; i++) {
    printf("\n");
    for (j = 0; j <metr; j++) {

      printf(RED"(%2d)\t",B[i][j] );
      }
    }
    */
  }

// Freeing Matrices from RAM
free(A);
free(B);

}
printf("------------------------------------");
printf("\n   N, CPU,\tTime");
for(i=0; i< NN; i++){
printf("\n%2d, %d, %6.6f",N[i],CPUS[i],Metrics[i]);
}
printf("\n------------------------------------\n");
  return 0;
}
