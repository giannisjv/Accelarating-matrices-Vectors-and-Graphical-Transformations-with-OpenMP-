 /*for matrix equals to 1 we multiply the main diagonal.
   If any element of the main diagonal is zero
    we will have 0 as determinant and the inversion will not be available.*/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define min 1
#define max 1000

int main(){

    float ratio, det, det_temp, temp_num;
    int i, j, k, p;
    int c, times;

    int N = 100, M;    
    float **A, **Ad, **inverseA, **matrix;       // main matrices A, 
    float **matrix1, **temp;           // helpers
   
    M = N - 1;
    srand(time(NULL));
    time_t start, end ;
    double time_taken;
	

  	A = (float **)malloc(N * sizeof(float *)); 
		for(i=0; i<N; i++){
			A[i] = (float *)malloc(N * sizeof(float));
		}

    matrix = (float **)malloc(N * sizeof(float *)); 
		for(i=0; i<N; i++){
			matrix[i] = (float *)malloc(N * sizeof(float));
		}

  	Ad = (float **)malloc(N * sizeof(float *)); 
		for(i=0; i<N; i++){
			Ad[i] = (float *)malloc(N * sizeof(float));
		}

    inverseA = (float **)malloc(N * sizeof(float *)); 
		for(i=0; i<N; i++){
			inverseA[i] = (float *)malloc(N * sizeof(float));
		}  

  	matrix1 = (float **)malloc(M * sizeof(float *)); 
		for(i=0; i<M ;i++){
			matrix1[i] = (float *)malloc(M * sizeof(float));
		}

    temp = (float **)malloc(N * sizeof(float *)); 
		for(i=0; i<N; i++){
			temp[i] = (float *)malloc(N * sizeof(float));
		}

     for (i = 0; i < N; i++){
      for (j = 0; j < N; j++){
      A[i][j] = randomGenFloat(min, max);
      matrix[i][j] = A[i][j];
     }
  }
for (times = 0; times <14; times++){
//display_2D_Non_Squeredfloat(A, N, N);
  start = clock();

         for ( i = 0; i < N; i++) { 
            if (matrix[i][i] == 0.0) {
            printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
            printf("The element is x=(%d), y=(%d), value=(%f)\n",i, i,matrix[i][i] );
            return -1;
            }
          }
        UpperTriangle(matrix, N);

det = determinant_tri(matrix, N);      // finding the deteminat by multiplying the main diagonal 

      for (p = 0; p < N; p++) { 
        for (k = 0; k < N; k++) {
            
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    
                    if (i == p || j == k ){
                    temp[i][j] = 0.0;
                    }
                    else {
                        if((i + j) % 2 == 0){
                        temp[i][j] = A[i][j];
                    }   else{
                        temp_num = A[i][j];
                        temp[i][j] = -temp_num;
            }
        }
    }
}


int x = 0;
int y = -1;
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {

        if (temp[i][j] != 0 && (i != p || j != k)){
          y++;
            if(y == M){
                x++;
                y=0;
                }
            matrix1[x][y] = temp[i][j];


      }
    }
  }

    for (i = 0; i < M; i++) {
        if (matrix1[i][i] == 0.0) {
			   printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
         printf("The element is x=(%d), y=(%d), value=(%f)\n",i,j,matrix1[i][j] );
			   return -1;

    }
  }
    UpperTriangle(matrix1, M);

 /*for matrix equals to 1 we multiply the main diagonal.
   If any element of the main diagonal is zero
    we will have 0 as determinant and the inversion will not be available.*/

    det_temp = 1; //storage for determinant
    for(i = 0; i < M; i++){
        det_temp *= matrix1[i][i];
    }

Ad[k][p] = det_temp;    
  }
}
/*
For every element of the First matrix we will divide by the determinant
  by that we will have the inverse matrix */

    for(i=0; i<N; i++){
      for (j = 0; j < N; j++) {
            inverseA[i][j] = Ad[i][j] / det;
      }
    }

    //display_2D_Non_Squeredfloat(inverseA, N, N);
    end = clock();
    time_taken = end - start;
    time_taken /= CLOCKS_PER_SEC;
    printf("\ntime took %5.6f", time_taken);
    time_taken = start = end = 0;
}
printf("\n");
    return 0;
}


