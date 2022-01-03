#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 10000



int main(int argc, char const *argv[]) {
    srand(time(NULL)); 
    double CPU_time;
    double Start = 0.0, Stop =0.0;

    int i, j, counter =0, searchNum = randomGenInteger(1, 200);
    int **A;
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
/*
    printf("\n\n");
    for(i=0; i<N; i++){
        printf("\n");
        for(j=0; j<N; j++){
           printf("\t%d",A[i][j] );
        }
    }
    */
    printf("\n\n");
    Start = omp_get_wtime();
   #pragma omp parallel for collapse(2) schedule(static) num_threads(8) private(counter, searchNum, i, j) shared(A)
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(A[i][j] == searchNum){
                counter++;
            }
        }
    }
    Stop = omp_get_wtime();

CPU_time = Stop - Start;

    printf("\nTimes the random number"YEL" %d "RESET" found in plurality of"YEL" %d "RESET" are "YEL" %d"RESET" and the time needed was"GRN" %5.6f"RESET,searchNum, N, counter, CPU_time);

    free(A);
        
}