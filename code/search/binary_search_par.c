#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"
#include "../myLibs/parallelFunctions.h"

#define N 2000000000
#define cores 8


int main(int argc, char const *argv[]) {
    srand(time(NULL)); 
    double CPU_time;
    
    int i, j, counter = 0;
    int times_found, searchNum;  

    bool found = false;

     int start = 0;
     int end = N - 1;
    
    int *A;
    
  
    A = (int *)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 
    
    if(!A){
      printf("\nToo much speedooo!\n");
      return -1;
    }

    for(i=0; i<N; i++){
      A[i] = counter++;
    }

   // display(A, N);

    printf("\n\n");
for(i=0; i < 5; i++){
  searchNum = randomGenInteger(0, N-1);  
  for(int c = 2; c<=cores; c *=2)

    parallel_work(A, N, searchNum, c);

    printf("\n\n");

}
    free(A);
        
}

