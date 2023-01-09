#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 10


int main(int argc, char const *argv[]) {
    srand(time(NULL)); 
    double CPU_time;
    
    int i, j, counter = 0, counter1 = 0, searchNum = 42;
    int times_found;

    bool found = false;

     int start = 0;
     int mid, row, col, value;
     int end = N * N - 1;
    
    int **A;
    
  
    A = (int **)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N; i++){
            A[i] = (int *)malloc(N * sizeof(int));
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            A[i][j] = counter++;
        }
    }
    display2D(A, N);

    printf("\n\n");

    binary_search_par()

    free(A);
        
}