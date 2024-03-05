#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/colib.h"
#include "../../myLibs/parallelFunctions.h"

#define min 1
#define max 50
#define axisx 50
#define axisy 50
#define scalingRow 50
#define scalingColumn 50
#define N 100
#define cores 4

int main(int argc, char const *argv[])
{
srand(time(NULL));

    double start = 0, end = 0;
    double time_taken = 0;
    int i, j;
    int **A, **B, **temp, **temp2;

  

     A = (int **)malloc((axisx + N) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N + axisx; i++)
            A[i] = (int *)malloc((axisy + N) * sizeof(int));
    if(!A){
        printf("\nToo big Array!!!\n");
        return -1;
    }

    temp = (int **)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N; i++)
            temp[i] = (int *)malloc(N * sizeof(int));
     if(!temp){
        printf("\nToo big Array!!!\n");
        free(A);
        return -1;
    }


    temp2 = (int **)malloc((N * scalingRow) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N * scalingRow; i++)
            temp2[i] = (int *)malloc((N * scalingColumn)  * sizeof(int));

      if(!temp2){
        printf("\nToo big Array!!!\n");
        free(A);
        free(temp);
        return -1;
    }

    B = (int **)malloc((N * scalingRow + axisx) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N * scalingRow + axisx; i++)
            B[i] = (int *)malloc((N * scalingColumn + axisy)  * sizeof(int));

      if(!B){
        printf("\nToo big Array!!!\n");
        free(A);
        free(temp);
        free(temp2);
        return -1;
    }

   for (int chunk = 1; chunk <= 4096; chunk*=2)
   {
    for (int c = 2; c <= cores; c *=2)
    {
    #pragma omp parallel num_threads(c)
    {
    start = omp_get_wtime();
    // filing A matrix  
    scaling_filling_Static(A, N, axisx, axisy, min, max, chunk);
    /*
    #pragma omp single
    {
    display_2D_Non_Squered(A, N + axisx, N + axisy);
    }
    */
    
    // taking only the values that matter from matrix A 
    scaling_cleaning_static(A, temp, N, axisx, axisy, chunk);
    /*
    #pragma omp single
    {
    display_2D_Non_Squered(temp, N, N);
    }
    */
    // scaling the matrix temp
    scaling_Static(temp, temp2, N, scalingRow, scalingColumn, chunk);
   /*
    #pragma omp single
    {
    display_2D_Non_Squered(temp2, N * scalingRow, N * scalingColumn);
    }
    */
    scaling_translate_Static(temp2, B, N, axisx, axisy, scalingRow, scalingColumn, chunk);
   /* #pragma omp single
    {
    display_2D_Non_Squered(B, N * scalingRow + axisx, N * scalingColumn + axisy);
    }*/
}
    end = omp_get_wtime();
    time_taken = end - start;
    printf("\n"MAG"%5.6f"RESET"\t"YEL"%d"RESET"\t"RED"%d"RESET, time_taken , chunk, c);
    time_taken = start = end = 0;
   }
   printf("\n\n");
}  
     free(A);
     free(B);
     free(temp);
     free(temp2);
    return 0;
}
