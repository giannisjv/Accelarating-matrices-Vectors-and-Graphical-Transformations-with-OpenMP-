#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 5

int main(int argc, char const *argv[]) {
    srand(time(NULL)); 
    double CPU_time;
    
    int i, j, counter = 0, counter1 = 0, searchNum = 99;
    int times_found;

    //bool found = false;

     int found;
     int start = 0;

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

  found = binary_search(A, start, end, N, searchNum);

 /* 
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    row = mid / N;
    col = mid % N;
    value = A[row][col];

    if (value == searchNum){
      printf("\nFound!\n");
      found = true;
      return 1;
    }
    else if (value > searchNum){
      end = mid - 1;}
    else
      start = mid + 1;
  }

  if (found == false){
    printf("\nDidn't found\n");
  }
  */

  if(found == 1){
    printf("\nFound it\n");
  }else{
    printf("\nDoesn't exist\t# %d #\n",found);  
  }

    free(A);
        
}