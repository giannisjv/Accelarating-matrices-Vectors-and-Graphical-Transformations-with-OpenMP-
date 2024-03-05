#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/colib.h"

#define N 10000
#define min 1
#define max 50
int main(int argc, char const *argv[])
{

    srand(time(NULL));

    time_t start, end;
    double time_taken;
    int i, j;
    int translationRow, translationColumn;
    int **A, **B;

    translationRow = 50;
    translationColumn = 50;

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

for(i=0; i<14;i++){
start = clock();
translate(A, B, N, translationRow, translationColumn);
end = clock();

time_taken = end - start;
time_taken /= CLOCKS_PER_SEC;

printf("\n%5.6f",time_taken);
start = end = time_taken = 0.0;
}
    printf("\n");
    return 0;
}
