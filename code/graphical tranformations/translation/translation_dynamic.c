#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/parallelFunctions.h"
#include "../../myLibs/colib.h"

#define N 10000
#define min 1
#define max 50
#define cores 8
int main(int argc, char const *argv[])
{

    srand(time(NULL));

    double start, end;
    double time_taken;
    int i, j, c, chunk;
    int translationRow, translationColumn;
    int **A, **B;

    translationRow = 50;
    translationColumn = 50;

     A = (int **)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N; i++)
            A[i] = (int *)malloc(N * sizeof(int));
    if(!A){
        printf("\nMatrix A too big, error code -1");
        return -1;
    }
    
    for ( i = 0; i < N; i++){ //This is a for
        for (j = 0; j < N; j++)
            A[i][j] = randomGenInteger(min, max);
    }

     B = (int **)malloc((N + translationRow) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N + translationRow; i++)
            B[i] = (int *)malloc((N + translationColumn)  * sizeof(int));

      if(!B){
        printf("\nMatrix B too big, error code -1");
        free(A);
        return -1;
    }

printf("\nThe N was %d, translate row %d, translate Column %d\nThe scheduler is dynamic \n", N, translationRow, translationColumn);

printf("\ntime took\tcores\tchunk\n");
for (chunk = 1; chunk <= 4096; chunk *= 2)
{
    for (c = 2; c <= cores; c*=2){

start = omp_get_wtime();
parallel_translate_dynamic(A, B, N, translationRow, translationColumn, c, chunk);
end = omp_get_wtime();

time_taken = end - start;

printf("\n%5.6f\t%d\t%d", time_taken, c, chunk);
    
    time_taken = end = start = 0.0;
    }
    printf("\n\n");
}

free(A);
free(B);
    return 0;
}
