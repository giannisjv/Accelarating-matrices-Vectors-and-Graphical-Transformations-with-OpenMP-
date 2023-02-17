#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../../myLibs/colib.h"
#include "../../myLibs/functions.h"
#include "../../myLibs/parallelFunctions.h"

#define min 1
#define max 50
#define N 10000
#define cores 8

int main(int argc, char const *argv[])
{
    double start = 0, end = 0;
    double time_taken = 0;
    int i, j, c;
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

for(int chunk = 1; chunk <=4096; chunk *= 2){
    for(c = 2; c<=cores; c *= 2){
        
        start = omp_get_wtime();
            parallel_rotation180_static(A, B, N, c, chunk);
        end = omp_get_wtime();
        time_taken = end - start;
        printf("\n%5.6f",time_taken);
        start = end = time_taken =  0;
            }
            printf("\n\n");
}
    free(A);
    free(B);
    
    return 0;
}
