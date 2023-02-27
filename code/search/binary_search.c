#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 10
#define searchNum N / 2 

int main(int argc, char const *argv[]) {
   
    srand(time(NULL)); 
    double CPU_time;
    time_t time_start, time_stop;
    
    int i, j, counter = 0, counter1 = 0;
    int times_found;

    //bool found = false;

     int found;
     int start = 0;

     int end = N - 1;
    
    int *A;
    
  
    A = (int *)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 

    for(i=0; i<N; i++){
            A[i] = counter++;
    }
    display(A, N);

    printf("\n\n");

  time_start = clock();
  found = binary_search(A, start, end, N, searchNum);
  time_stop = clock();

  CPU_time = time_stop - time_start;
  CPU_time /=CLOCKS_PER_SEC; 
  if(found == 1){
    printf("\nFound it at time%5.6f\n",CPU_time);
  }else{
    printf("\nDoesn't exist\t# %d #\n",found);  
  }

    free(A);
        
}