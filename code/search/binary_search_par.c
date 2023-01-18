#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 10

void binary_search_par_workSharing(int **A, int searchNum, int num_threads);
int binarySearch_openmp(int **A, int first, int last, int searchVal);

int main(int argc, char const *argv[]) {
    srand(time(NULL)); 
    double CPU_time;
    
    int i, j, counter = 0, counter1 = 0, searchNum = 200;
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

    binary_search_par_workSharing(A, searchNum, 4);

    free(A);
        
}

void binary_search_par_workSharing(int **A, int searchNum, int num_threads){
    
    int result;
    int mid, row, col, value, start = 0, end = N * N - 1;
    double start_time, end_time, time_took;

    mid = start + (end - start) / 2;

    int thread_one, thread_two, thread_three, thread_four;
    int quarter_slice = mid / 2;

     printf("\n****** Now beginning Parallel work with OpenMP ******\n\n");
     printf("Starting binary search...\n");

          start = omp_get_wtime();

#pragma omp parallel num_threads(num_threads)
    {
#pragma omp sections
        {
        /* Function parameters:
            binarySearch_openmp(Malloc_Matrix, first_index, last_index, matrix_N search_value);
        */


#pragma omp section
            thread_one = binarySearch_openmp(A, 0, quarter_slice, searchNum);
#pragma omp section
            thread_two = binarySearch_openmp(A, quarter_slice + 1, mid, searchNum);
#pragma omp section
            thread_three = binarySearch_openmp(A, mid + 1, quarter_slice * 3, searchNum);
#pragma omp section
            thread_four = binarySearch_openmp(A, ( quarter_slice * 3) + 1, end, searchNum);
    }

    end_time = omp_get_wtime();
    time_took = end_time - start_time;
    printf("Work took %f seconds\n", time_took);

    // Print results of serial Binary search
    if (result != -1)
    {
        printf("Element %d found! At index %d\n", searchNum, result);
    }
    else
    {
        printf("Element %d not found\n", searchNum);
    }
    printf("\n");
  }
}

int binarySearch_openmp(int **A, int start, int end, int searchNum){
    
  int mid, row, col, value;
  int pl = end;
  int end2 = (end * end) -1;

  while (start <= end2)
  {
    mid = start + (end2 - start) / 2;
    row = mid / pl;
    col = mid % pl;
    value = A[row][col];

    if (value == searchNum){
      printf("\nFound\n");
      return 1;
    }
    else if (value > searchNum){
      end2 = mid - 1;
      }
    else 
      start = mid + 1;
  }
  return -1;
}
