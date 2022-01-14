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
    int i, j, p, k, s, f;
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
/*
        for (i = 0; i < NN; i++){
         for ( j = 0; j < NN; j++){
             for ( p = 0; p < N; p++){
                 for ( k = 0; k < N; k++){
                    if(s != N && f != N){
                        C[i][j] = A[p][k] * B[s++][f++]; 
                        //printf("\ntimh C %d timh A %d, timh B %d\n", C[i][j], A[p][k], B[s][f]);
                 } else{
                     s = 0; 
                     f = 0;
                 } 

               }
             } 
         }
         
    }
        

*/
        for ( i = 0; i < N; i++){
            for ( j = 0; j < N; j++){
                
                for ( p = 0; p < N; p++){
                    for ( k = 0; k < N; k++){
                        counter = 0;
                        s = 0;
                        f = 0;
                        if(counter != N * N){
                                C[p][k] = A[i][j] * B[s][f];
                                counter++; // counter will initiate again when will be equal to N * N 
             } // end for f
            } // end for s
          } // end if
         } // end for k      
        } // end for p
       } // end for j
      } // end for i
        
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
printf("Matrix A\n");
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
