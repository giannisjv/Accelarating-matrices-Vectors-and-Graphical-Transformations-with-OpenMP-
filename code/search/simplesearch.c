#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 2000000000


int main(int argc, char const *argv[]) {
    srand(time(NULL)); 
    double start, end;
    double CPU_time;
    int i, j, searchNum;
    int times_found;
    int counter = 0;
    int *A;
    //Initiating matrix A with malloc 
    A = (int *)malloc(N * sizeof(int *));


    for(i=0; i<N; i++){
            A[i] = counter++;
    }
    searchNum = counter / 2;

    //display(A, N);

    printf("\n\n");
    for (i = 1; i <= 4096; i *=2)
    {
    
start = omp_get_wtime();
    times_found = serial_search(A, N, searchNum);
end = omp_get_wtime();
    CPU_time = end - start;

    printf("%5.6f\n\n\n\n\n", CPU_time);
    CPU_time = start = end = 0;
    }

printf("\n");

    free(A);
        
}