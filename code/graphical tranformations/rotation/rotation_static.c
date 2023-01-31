#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../../myLibs/colib.h"
#include "../../myLibs/functions.h"
#include "../../myLibs/parallelFunctions.h"

#define min 1
#define max 50
#define N 3
#define cores 8

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int i, j;
    int **A, **B;
    int counter = 1;

    A = (int **)malloc(N * sizeof(int *));
        for(i = 0; i < N; i++){
            A[i] = (int *)malloc(N * sizeof(int));
        }
    if(!A){
        printf("\nToo big matrix can't exist\n");
        return -1;
    }

    B = (int **)malloc(N * sizeof(int *));
        for(i=0; i<N; i++){
            B[i] = (int *)malloc(N * sizeof(int));
        }

  if(!B){
        printf("\nToo big matrix can't exist\n");
        free(A);
        return -1;
    }

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            A[i][j] = counter++;
        }
    }

    printf("\nDisplay matrix A\n");
    display2D(A, N);
    printf("\n\n");
    
/*
    rotation270(A, B, N);
    printf("\nDisplay matrix B 270 degrees\n");
    display2D(B, N);
    
    rotation180(A, B, N);
    printf("\n\n");

    printf("\nDisplay matrix B 180 degrees\n");
    display2D(B, N);
    printf("\n\n");
    
*/
    parallel_rotation90_static(A, B, N);
    printf("\n\n");

    printf("\nDisplay matrix B 90 degrees\n");
    display2D(B, N);
    printf("\n\n");
    
    free(A);
    free(B);
    
    return 0;
}
