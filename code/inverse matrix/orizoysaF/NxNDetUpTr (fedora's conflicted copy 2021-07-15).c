#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/ragnlib.h"
#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/colib.h"

#define N 4


int main(){
    float  ratio, det;
    float matrix[N][N];
    int i, j, k;
    srand(time(NULL));

printf("\n\n");
printf("\t\tARRAY A\n\n");
/*
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    printf("Enter the matrix: \n");
    */
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            //scanf("%f", &matrix[i][j]);
            matrix[i][j] = randomGen();
        }
    }
    for(i = 0; i < N; i++){
      printf("\n");
        for(j = 0; j < N; j++){
            //scanf("%f", &matrix[i][j]);
            printf("%15.2f",matrix[i][j]);
        }
    }

    printf("\n\n");
    // Conversion of matrix to upper triangular

    for(i=0; i<N; i++)
	 {
		  if(matrix[i][i] == 0)
		  {
			   printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
			   return -1;
		  }
		  for(j=i+1; j<N; j++)
		  {
			  ratio = matrix[j][i] / matrix[i][i];
         //printf("i = (%2d), j = (%2d), ratio = (%2.2f)\n",i, j, ratio );

			   for(k=0; k<N; k++)
			   {
			  		matrix[j][k] -= ratio * matrix[i][k];
			   }
		  }
	 }

printf("\n\n\tUpper triangular Matrix\n\n");
    for(i = 0; i < N; i++){
      printf("\n");
        for(j = 0; j < N; j++){
            //scanf("%f", &matrix[i][j]);
            printf("%15.2f",matrix[i][j]);
        }
    }
printf("\n\n");

    det = 1; //storage for determinant
    for(i = 0; i < N; i++)
        det *= matrix[i][i];
    printf("  The determinant of matrix is: %4.2f\n\n", det);
    return 0;
}
