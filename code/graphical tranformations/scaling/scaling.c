#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/colib.h"
#include "../../myLibs/parallelFunctions.h"

#define min 1
#define max 50
#define N 4

int main(int argc, char const *argv[])
{
srand(time(NULL));

    time_t start, end;
    double time_taken;
    int i, j;
    int translationRow, translationColumn;
    int **A, **B;

    translationRow = 2;
    translationColumn = 1;

     A = (int **)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N; i++)
            A[i] = (int *)malloc(N * sizeof(int));
    
    for ( i = 0; i < N; i++){ //This is a for
        for (j = 0; j < N; j++)
            A[i][j] = randomGenInteger(min, max);
    }

     B = (int **)malloc((N + translationRow) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N * translationRow; i++)
            B[i] = (int *)malloc((N * translationColumn)  * sizeof(int));


    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            A[i][j] = randomGenInteger(min, max);
        }
    }

      for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            A[i][j] = randomGenInteger(min, max);
        }
    }
    display2D(A, N);
    printf("\n\n");

      for (i = 0; i < N * translationRow; i++){
        for (j = 0; j < N * translationColumn; j++){
            B[i * translationRow][j * translationColumn] = A[i][j];
            //B[i][j] = randomGenInteger(min, max); 
        }
    }

    display_2D_Non_Squered(B, N * translationRow, N * translationColumn);
    
    return 0;
}
