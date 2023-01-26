#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/parallelFunctions.h"
#include "../../myLibs/colib.h"

#define N 10
#define min 1
#define max 50
#define cores 4
int main(int argc, char const *argv[])
{

    srand(time(NULL));

    double start, end;
    double time_taken;
    int i, j;
    int translationRow, translationColumn;
    int **A, **B;

    translationRow = 5; //randomGenInteger(min, max);
    translationColumn = 2; //randomGenInteger(min, max);

     A = (int **)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N; i++)
            A[i] = (int *)malloc(N * sizeof(int));
    
    for ( i = 0; i < N; i++){ //This is a for
        for (j = 0; j < N; j++)
            A[i][j] = randomGenInteger(min, max);
    }

     B = (int **)malloc((N + translationRow) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N + translationRow; i++)
            B[i] = (int *)malloc((N + translationColumn)  * sizeof(int));
printf("\n\t\t\t\tmatrix A\n");
display2D(A, N);

start = omp_get_wtime();
parallel_translate(A, B, N, translationRow, translationColumn, cores);
end = omp_get_wtime();

printf("\n\t\t\t\tmatrix B\n");
display_2D_Non_Squered(B, N + translationRow, N + translationColumn);

time_taken = end - start;

printf("\n\nThe N was %d, translate row %d, translate Column %d, time took %5.6f, cores %d", N, translationRow, translationColumn, time_taken, cores);
    printf("\n\n");
    return 0;
}
