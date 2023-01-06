#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 20000



int main(int argc, char const *argv[]) {
    srand(time(NULL));

    double CPU_time, CPU_timeSeq;
    double Start = 0.0, Stop =0.0;

    int i, j, times_found;
    int **A;
    int searchNum = randomGenInteger(1, 200);

    //Initiating matrix A with malloc 
    A = (int **)malloc(N * sizeof(int *));
        for(i=0; i<N; i++){
            A[i] = (int *)malloc(N * sizeof(int));
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            A[i][j] = randomGenInteger(1,200);
        }
    }

   for(i=2; i<=8; i=i*2){
    
 printf("\n\n");
 printf("======================================");
 printf("\nStarting Sequencial searching parallel with"RED" %d "RESET"cores\n",i);
    Start = omp_get_wtime();
   times_found = serial_search_parallel(A, N, searchNum, i);
    Stop = omp_get_wtime();

    CPU_time = Stop - Start;
    printf("Times the random number"YEL" %d "RESET" found in plurality of"YEL" %d "RESET" are "YEL" %d"RESET" and the time needed was"GRN" %5.6f"RESET,searchNum, N, times_found, CPU_time);
    
}
    free(A);
 printf("\n\n");
return 0;
}