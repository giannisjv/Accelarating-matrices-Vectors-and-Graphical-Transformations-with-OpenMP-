#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 2000000000

int main(int argc, char const *argv[]) {
   
    srand(time(NULL)); 
    double CPU_time;
    double time_start, time_stop;
    
    int i, j, counter = 0, counter1 = 0;
    int times_found, searchNum;

    //bool found = false;

     int found;
     int start = 0;

     int end = N - 1;
    
    int *A;
    
  
    A = (int *)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 

    for(i=0; i<N; i++){
            A[i] = counter++;
    }
    //display(A, N);

    printf("\n\n");

  searchNum = randomGenInteger(0, N -1);
  time_start = omp_get_wtime();
  found = binary_search(A, start, end, searchNum);
  time_stop = omp_get_wtime();

  CPU_time = time_stop - time_start;
  
  if(found != -1){
    printf("\nFound the num %d it at time %5.6f\n",found, CPU_time);
  }else{
    printf("\nDoesn't exist\t# %d #\n",found);  
  }
    free(A);
        
}