#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/colib.h"
#include "../../myLibs/parallelFunctions.h"

#define min 1
#define max 50
#define axisx 50
#define axisy 50
#define scalingRow  50
#define scalingColumn  50
#define N 500

int main(int argc, char const *argv[])
{
srand(time(NULL));

    time_t start, end;
    double time_taken;
    int counter = 1;
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

   while (counter != 4096)
   {
   
    

    start = clock();
    // filing A matrix  
    scaling_filling(A, N, axisx, axisy, min, max);

    // taking only the values that matter from matrix A 
    scaling_cleaning(A, temp, N, axisx, axisy, min, max);
    
    // scaling the matrix temp
     scaling(temp, temp2, N, scalingRow, scalingColumn);


    scaling_translate(temp2, B, N, axisx, axisy, scalingRow, scalingColumn);
    
    end = clock();
    time_taken = end - start;
    time_taken /= CLOCKS_PER_SEC;
    printf("%5.6f\n\n\n\n\n", time_taken);
    counter *=2;
    time_taken = start = end = 0;
   } 
   
     free(A);
     free(B);
     free(temp);
     free(temp2);
     printf("\n\n");
    return 0;
}
