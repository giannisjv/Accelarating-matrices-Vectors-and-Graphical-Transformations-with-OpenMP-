/* Kronecker product 

*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 250   
#define M 250

int main(int argc, char const *argv[])
{
    
    int **A, **B, **C; // Defining 3 matrices as pointers for use with malloc
    int i, j, s, f, loop;
    int ARow, ACol, BRow, BCol ,CRow, CCol, stRow, stCol;
    int NN = N * N;
    time_t seqStart, Seq_End;
    double CPU_time;
    srand(time(NULL));

        ARow = N;   // Initialize A matrix
        ACol = M;

        BRow = M;   // Initialuze B matrix
        BCol = N;

        CRow = ARow * BRow; // initiate C Matrix 
        CCol = ACol * BCol; // C matrix will have Rows A multiplied by Rows B same in Columns




    //Initiate arrays using malloc!!!
    // A, B
    A = (int **)malloc(ARow * sizeof(int *));
        for(i = 0; i < ARow; i++){
            A[i] = (int *)malloc(ACol * sizeof(int));
        }

    B = (int **)malloc(BRow * sizeof(int *));
        for(i=0; i<BRow; i++){
            B[i] = (int *)malloc(BCol * sizeof(int));
        }

    // C is the product of the multiplication of every single element from A multiplied with B...
     C = (int **)malloc(CRow * sizeof(int *));
        for(i = 0; i < CRow; i++){
            C[i] = (int *)malloc(CCol * sizeof(int)); 
        }


    // Checking if the matrix does not exist
    if(!A){
        printf("\nThe A matrix does not exist\nProbably too big array");
        return -1;
    }

    if(!B){
        printf("\nThe B matrix does not exist\nProbably too big array");
        free(A);
        return -1;
    }


    if(!C){
        printf("\nThe B matrix does not exist\nProbably too big array");
        free(A);
        free(B);
        return -1;
    }


// Filling the matrices with random numbers from -10 to 10
            for (i = 0; i < ARow; i++){
                for (j = 0; j < ACol; j++){
                    A[i][j] = randomGenInteger(-10, 10);
                     B[i][j] = randomGenInteger(-10, 10);
                }
             }
    printf("\nTime\n");
            for (loop = 0; loop < 15; loop++)
            {
                    seqStart = clock(); // starting the timer 
                     for(i = 0; i < ARow; i++){ // i from 0 to ROWS cardinality of the first Matrix
                        for (j = 0; j < ACol; j++){ // j from 0 to Columns cardinality of the first Matrix Col
                            stRow = i * BRow; // Matrix C ROW is "i" multiplied by the cardinality of Rows from the second Matrix 
                            stCol = j * BCol; // Matrix C Column is "j" multiplied by the cardinality of Columns from the second Matrix
                                for ( s = 0; s < BRow; s++){ // s from 0 to cardinality of ROWS from the second Matrix
                                     for ( f = 0; f < BCol; f++){ // f from 0 to cardinality of Columns from the second Matrix
                                        C[stRow+s][stCol+f] = (A[i][j]) * (B[s][f]);
                     }
                          }
                                }
                                    }
            Seq_End = clock(); 
            CPU_time = Seq_End - seqStart;
            CPU_time /= CLOCKS_PER_SEC;
            printf("\n%5.6f\n",CPU_time);
            CPU_time = Seq_End = seqStart = 0;
            }
/*
//Display matrix A
    printf("\n\n");
    printf("Matrix A\n");
    display_2D_Non_Squered(A, ARow, ACol);

//Display matrix B
printf("\n\n");
printf("Matrix B\n");
     display_2D_Non_Squered(B, BRow, BCol);

//Display matrix C
printf("\n\n");
printf("Matrix C\n");
        display_2D_Non_Squered(C, CRow, CCol);
printf("\n");
*/

    free(A);
    free(B);
    free(C);

    return 0;
}
