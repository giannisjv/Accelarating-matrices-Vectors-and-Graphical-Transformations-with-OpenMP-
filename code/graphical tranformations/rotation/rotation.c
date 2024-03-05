#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../myLibs/colib.h"
#include "../../myLibs/functions.h"

#define min 1
#define max 50
#define N 10

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    time_t start, end;
    double time_took;
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
    printf("\n");

for(i=0;i<14;i++){
    start = clock();
    rotation180(A, B, N);
    
    end = clock();
    time_took = end - start;
    time_took /= CLOCKS_PER_SEC;
    printf("%5.6f\n\n\n\n\n",time_took);
    start = end = time_took = 0;
}
display2D(A, N);
printf("\n\n");
display2D(B, N);

    free(A);
    free(B);
    
    return 0;
}
