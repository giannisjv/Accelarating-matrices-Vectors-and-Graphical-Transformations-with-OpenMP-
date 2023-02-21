#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/colib.h"
#include "../../myLibs/parallelFunctions.h"

#define min 1
#define max 50
#define axisx 4
#define axisy 4
#define scalingRow  3
#define scalingColumn  3
#define N 4

int main(int argc, char const *argv[])
{
srand(time(NULL));

    time_t start, end;
    double time_taken;
    int i, j;
    int **A, **B, **temp, **temp2;

  

     A = (int **)malloc((axisx + N) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N + axisx; i++)
            A[i] = (int *)malloc((axisy + N) * sizeof(int));
    if(!A){
        printf("\nToo big Array!!!\n");
        return -1;
    }
    
    for (i = 0; i < N + axisx; i++){ //This is a for
        for (j = 0; j < N + axisy; j++){
        if(i < axisx  || j < axisy){
            A[i][j] = 0;
        }else{
            A[i][j] = randomGenInteger(min, max);
        }
    }
}

   /* display_2D_Non_Squered(A, N + axisx, N + axisy);
    printf("\n\n");
*/


      temp = (int **)malloc(N * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N; i++)
            temp[i] = (int *)malloc(N * sizeof(int));

        for (i = 0; i < N + axisx; i++){ //This is a for
        for (j = 0; j < N + axisy; j++){
        if(A[i][j] != 0){
            temp[i - axisx][j - axisy] = A[i][j];
        }
    }
}

    display2D(temp, N);
    printf("\n\n");




     temp2 = (int **)malloc((N * scalingRow) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N * scalingRow; i++)
            temp2[i] = (int *)malloc((N * scalingColumn)  * sizeof(int));

   

      for (i = 0; i < N * scalingRow; i++){
        for (j = 0; j < N * scalingColumn; j++){
            if(i < N && j < N){
            temp2[i][j] = temp[i][j];
            }else
            temp2[i][j] = 1;

            //B[i][j] = randomGenInteger(min, max); 
        }
    }

     display_2D_Non_Squered(temp2, N * scalingRow, N * scalingColumn);

    
     B = (int **)malloc((N * scalingRow + axisx) * sizeof(int *));   //Initiating matrix A with malloc 
        for(i=0; i<N * scalingRow + axisx; i++)
            B[i] = (int *)malloc((N * scalingColumn + axisy)  * sizeof(int));


    printf("\n\n");
    scaling_translate(temp2, B, N, axisx, axisy, scalingRow, scalingColumn);

    display_2D_Non_Squered(B, N * scalingRow + axisx, N * scalingColumn + axisy);

   
     free(A);
     free(B);
     free(temp);
     free(temp2);
     printf("\n\n");
    return 0;
}
