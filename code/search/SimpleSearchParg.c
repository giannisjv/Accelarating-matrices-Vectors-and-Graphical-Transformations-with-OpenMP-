#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"
#include "../myLibs/parallelFunctions.h"

#define N 2000000000
#define cores 8

int main(int argc, char const *argv[]) {
    
    srand(time(NULL));

    double CPU_time, CPU_timeSeq;
    double Start = 0.0, Stop =0.0;

    int i, j, times_found, counter = 0, counterPar = 0;
    int *A;
    int searchNum = N / 2;

    //Initiating matrix A with malloc 
    A = (int *)malloc(N * sizeof(int *));
    printf("\n\n");
    for(i=0; i<N; i++){
            A[i] = counter++;
    }
    
    for (int chunk = 1; chunk <=4096; chunk *=2)
    {
        for(i = 2; i<=cores; i*=2){
        
    Start = omp_get_wtime();
    times_found = serial_search_parallel_Guided(A, N, searchNum, i, chunk);
    Stop = omp_get_wtime();

    CPU_time = Stop - Start;
    printf(" %5.6f\t%d\n", CPU_time, chunk);
    Start = Stop = CPU_time = 0;
    }
    printf("\n\n");
}
    printf("\n\n");

//display(A, N);
    free(A);
 printf("\n\n");
return 0;
}