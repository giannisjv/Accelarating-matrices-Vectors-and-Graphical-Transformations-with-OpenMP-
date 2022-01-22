#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 2

int main(int argc, char const *argv[])
{
    // Defining 3 arrays as pointers for use with malloc
    int **A, **B, **C;
    int i = 0, j = 0, p = 0, k = -1, s, f;
    int temps;
    int NN;
    int counter = 0;
    srand(time(NULL));

    NN = N * N; 

    //Initiate arrays using malloc!!!
    // A, B
    A = (int **)malloc(N * sizeof(int *));
        for(i=0; i<N; i++){
            A[i] = (int *)malloc(N * sizeof(int));
        }

    B = (int **)malloc(N * sizeof(int *));
        for(i=0; i<N; i++){
            B[i] = (int *)malloc(N * sizeof(int));
        }

    //C is the product of the multiplication of every single element from A multiplied with B...
     C = (int **)malloc(NN * sizeof(int *));
        for(i=0; i<NN; i++){
            C[i] = (int *)malloc(NN * sizeof(int)); 
        }


// Filling the matrices with random numbers from -10 to 10
            for (i = 0; i < N; i++){
                for (j = 0; j < N; j++){
                    A[i][j] = randomGenInteger(-10, 10);
                }
                
            }
            

            for (i = 0; i < N; i++){
                for (j = 0; j < N; j++){
                    B[i][j] = randomGenInteger(-10, 10);
                }
            }
   
     // for ( i = 0; i < N; i++){
           // for ( j = 0; j < N; j++){
                /*for ( p = 0; p < N; p++){
                    for ( k = 0; k < N; k++){
                        /*
                        if( k > N){
                            tempj = j--;
                                C[p][k] = A[i][j++] * B[p][k];
                                printf("\n\ni %d, j %d, p %d, k %d\n A %d, B %d, C %d",i, j, p, k, A[i][j] , B[p][k], C[p][k]);
                                printf("\n eimai i prwti if");
                         } // end if (k > N)*/
                       
                       // if (k < N){
                                    for(s = 0; s < N; s++){
                                        for (f = 0; f < N; f++){
                                             if (k == (N -1)){
                                   j++;
                               }else if(k == (NN -1)){
                                    p++;
                                    k = -1;
                                    i++;
                                    j = 0;
                                } 
                                            
                                            C[p][k++] = (A[i][j]) * (B[s][f]);
                                printf("\n\ni %d, j %d, p %d, k %d, s %d, f %d\n A %d, B %d, C %d",i, j, p, k, s, f, A[i][j] , B[s][f], C[p][k]);
                                    
                            } 
                        }
         // } // end of else if (k > N)
        // } // end for k      
       // } // end for p
     //  } // end for j
  //    } // end for i
        



//Display matrix A
printf("\n\n");
printf("Matrix A\n");
        for (i = 0; i < N; i++){
            printf("\n");
            for (j = 0; j < N; j++){
                    printf("%d\t",A[i][j]);
                }
            } 
      

//Display matrix B
printf("\n\n");
printf("Matrix B\n");
        for (i = 0; i < N; i++){
            printf("\n");
            for (j = 0; j < N; j++){
                    printf("%d\t",B[i][j]);
                }
            } 



//Display matrix C
printf("\n\n");
printf("Matrix C\n");
        for (i = 0; i < NN; i++){
            printf("\n"); 
            for (j = 0; j < NN; j++){
                    printf("%d\t",C[i][j]);
                }
            } 


    free(A);
    free(B);
    free(C);

    return 0;
}
