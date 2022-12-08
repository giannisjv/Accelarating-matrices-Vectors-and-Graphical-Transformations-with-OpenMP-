#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/colib.h"

#define min 1
#define max 1000

int main(int argc, char const *argv[]) {

  srand(time(NULL));      // random seed
  time_t start, end;      // timers 
  double time_taken;      // variable for time taken
  int counter = 0;

  int i, j, N, p;         // Variables 
  int **A, **B, **C;      // double pointers for using with malloc to create matrices
  int Rows, Columns;      // number of Rows and Columns 

  printf("\nN:  ");       // Ask user to give N
  scanf("%d",&N);

  Rows = N * sizeof(int *);   // Initialize Rows into size of int (4bytes) 
  Columns = N * sizeof(int);  // Initialize Rows into size of int (4bytes)

  A = (int **)malloc(Rows);   // Creating the Matrix A
    for(i=0;i<N;i++){
      A[i] = (int *)malloc(Columns);
    }
    if(!A){                                       // Checking if Matrix A has builded
      printf("The Array is too big\nExiting\n");  
      return -1;                                  // If not exit 
    }

  B = (int **)malloc(Rows);                     // Creating the Matrix B
    for(i=0;i<N;i++){
      B[i] = (int *)malloc(Columns);            
    }
    if(!B){                                       // Checking if Matrix B has builded
      printf("The Array is too big\nFreeing A and Exiting\n"); 
      free(A);                                    // If not free A and exit
    return -1;
    }

  C = (int **)malloc(Rows);             // Creating the Matrix B
    for(i=0;i<N;i++){
      C[i] = (int *)malloc(Columns);
    }
    if(!C){                // Checking if Matrix B has builded
      printf("The Array is too big\nFreeing A and B\nExiting\n");
      free(A);
      free(B);
    return -1;             // If not free A and B and then exit
    }

    for(i=0; i<N; i++){
      for (j=0; j<N; j++) 
        A[i][j] = randomGenInteger(min, max);
    }

    for(i=0; i<N; i++){
      for (j=0; j<N; j++) 
        B[i][j] = randomGenInteger(min, max);
    }

    start = clock();
    for(i=0; i<N; i++){
      for (j=0; j<N; j++) {
          for(p=0; p<N; p++){
            C[i][j] += A[i][p] * B[p][j];
            counter++;
            }
          }
        }
        end = clock();



          /* ---------------------------------
             |print statements for the arrays|
             --------------------------------- */
/*
             printf("\n\nArray A\n");
            display2D(A, N);

             printf("\n\nArray B\n");
             display2D(B, N);

             printf("\n\nArray C\n");
            display2D(C, N);
*/
time_taken = end - start;
time_taken /= CLOCKS_PER_SEC;
printf("\n%5.6f time took, N %d, moves were %d\n",time_taken, N, counter);
             free(A);
             free(B);
             free(C);

  return 0;
}
