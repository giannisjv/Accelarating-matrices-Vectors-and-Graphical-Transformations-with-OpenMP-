 /*for matrix equals to 1 we multiply the main diagonal.
   If any element of the main diagonal is zero
    we will have 0 as determinant and the inversion will not be available.*/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 4
#define M N-1

int main(){

    float ratio, det, det_temp, division, temp_num;
    float A[N][N], matrix[N][N], Ad[N][N] ,inverse[N][N];
    float matrix1[M][M], temp[N][N];
    int i, j, k, p;
    int c;
    srand(time(NULL));

printf("\n\n");
// Initiate the random matrix
for(i=0; i<N;i++){
  for(j=0; j<N;j++){
    A[i][j]= randomGenFloat(1.0, 5.0); // Random Numbers to A
    matrix[i][j] = A[i][j]; // copy A to matrix 
  }
}

display2d(N, A);        // Display A


  printf("\n\n");
    // Conversion of matrix to upper triangular

      for ( i = 0; i < N; i++) {
        if (matrix[i][i] == 0.0) {      // if any number of main diagonal is zero - return -1
			   printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
         printf("The element is x=(%d), y=(%d), value=(%f)\n",i, i,matrix[i][i] );
			   return -1;
        }
             for ( i = 0; i < N; i++) {
                ratio = 0.0;        // ratio is zero every time i++
		              for(j = i + 1; j < N; j++) {      // select the i + 1 value till N - 1 
			            ratio = matrix[j][i] / matrix[i][i];    // ratio is selected value divided by main diagonal value of i 
                            for(k=0; k<N; k++) {         
			  		            matrix[j][k] -= ratio * matrix[i][k]; // ratio multiplied by [i][k] minus [j][k]
			   }
		  }
	 }
  }
 

det = determinant_tri(N, matrix);

      for (p = 0; p < N; p++) { 
        for (k = 0; k < N; k++) {
            
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    
                    if (i == p || j == k ){
                    temp[i][j] = 0.0;
                    }
                    else {
                        if((p + k) % 2 == 0){
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
                  //printf("x=%d, y=%d\n",x,y);
            matrix1[x][y] = temp[i][j];
      //  printf("i=%2d, j=%2d, x= %2d, y=%2d --> %2d\n",i, j, x, y, temp[x][y]);


      }
    }
  }

 printf("\n\n");
    // Conversion of matrix to upper triangular

    for (i = 0; i < M; i++) {
        if (matrix1[i][i] == 0.0) {
			   printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
         printf("The element is x=(%d), y=(%d), value=(%f)\n",i,j,matrix1[i][j] );
			   return -1;

    }
  }
    for (i = 0; i < M; i++) {
      ratio = 0.0;
		  for(j = i + 1; j < M; j++) {
			  ratio = matrix1[j][i] / matrix1[i][i];
         //printf("i = (%2d), j = (%2d), ratio = (%2.2f)\n",i, j, ratio );
          for(c=0; c<M; c++) {
			  		matrix1[j][c] -= ratio * matrix1[i][c];
			   }
		  }
	 }


 /*for matrix equals to 1 we multiply the main diagonal.
   If any element of the main diagonal is zero
    we will have 0 as determinant and the inversion will not be available.*/

    det_temp = 1; //storage for determinant
    for(i = 0; i < M; i++){
        det_temp *= matrix1[i][i];
    }
    printf("\nThe determinant of matrix is: %4.2f\n\n", det_temp);

    //printf("  The determinant of matrix is: (%4.2f)/1000\n\n", (det/100000));
    // Countinue from here the attempt to find the adjustible matrix


Ad[k][p] = det_temp;    

// Εδώ κλείνει η επίλογή στοιχείων.
  }
}

 //Showing the ad Matrix
 printf("\nPrinting of the  adjugate matrix!!\n");
display2d(N, Ad);
printf("\n");

/*
For every element of the First matrix we will divide by the determinant
  by that we will have the inverse matrix */

    for(i=0; i<N; i++){
      for (j = 0; j < N; j++) {
            inverse[i][j] = Ad[i][j] / det;
      }
    }
    //Showing the inversed Matrix
    printf("\nPrinting of the multiplication method matrix!!\n");
    display2d(N, inverse);

printf("\n");
    return 0;
}


