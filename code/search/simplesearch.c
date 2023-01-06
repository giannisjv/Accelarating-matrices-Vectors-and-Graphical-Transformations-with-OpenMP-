#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 20000


int main(int argc, char const *argv[]) {
    srand(time(NULL)); 
    time_t start, end;
    double CPU_time;
    int i, j, counter =0, searchNum = randomGenInteger(1, 200);
    int times_found;
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

    printf("\n\n");
start = clock();
    times_found = serial_search(A, N, searchNum);
end = clock();
    CPU_time = end - start;
    CPU_time /= CLOCKS_PER_SEC;

    printf("\nTimes the random number"YEL" %d "RESET" found in plurality of"YEL" %d "RESET" are "YEL" %d"RESET" and the time needed was"GRN" %5.6f"RESET,searchNum, N, times_found, CPU_time);
printf("\n");
    free(A);
        
}