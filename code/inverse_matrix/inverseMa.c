#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


#include "../myLibs/colib.h"
#include "../myLibs/functions.h"

#define N 4
#define M N-1

int main(){

    float ratio, det, det_temp, division, tempora;
    float A[N][N], matrix[N][N], Ad[N][N] ,inverse[N][N];
    float matrix1[M][M], temp[N][N];
    int i, j, k, p;
    int c;
    srand(time(NULL));

printf("\n\n");
// Initiate the random matrix
for(i=0; i<N;i++){
  for(j=0; j<N;j++){
    A[i][j]= randomGenFloat(1.0, 5.0);
    matrix[i][j] = A[i][j];
  }
}

  for ( i = 0; i < N; i++)
  {
    printf("\n");
    for (j = 0; j < N; j++)
    {
      printf("%.6f\t",A[i][j]);
    }
    
  }
  


  printf("\n\n");
    // Conversion of matrix to upper triangular

      for ( i = 0; i < N; i++) {
        if (matrix[i][i] == 0.0) {
			   printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
         printf("The element is x=(%d), y=(%d), value=(%f)\n",i, i,matrix[i][i] );
			   return -1;
        }
             for ( i = 0; i < N; i++) {
                ratio = 0.0;
		              for(j = i + 1; j < N; j++) {
			          ratio = matrix[j][i] / matrix[i][i];
              //printf("i = (%2d), j = (%2d), ratio = (%2.2f)\n",i, j, ratio );
              for(k=0; k<N; k++) {
			  		matrix[j][k] -= ratio * matrix[i][k];
			   }
		  }
	 }
  }
 


// Printing The upper triangular Matrix just to be sure no error occured
 printf("\n\n Εμφάνιση του Ανω τριγωνικού πίνακα!\n");
  for (int i = 0; i < N; i++) {
    printf("\n");
    for (int j = 0; j < N ; j++) {
      printf("\t%5.2f",matrix[i][j]);
    }
  }




printf("\n\n");
 /*for matrix equals to 1 we multiply the main diagonal.
   If any element of the main diagonal is zero
    we will have 0 as determinant and the inversion will not be available.*/

    det = 1; //storage for determinant
    for(i = 0; i < N; i++)
        det *= matrix[i][i];
    printf("\tThe determinant of matrix is: %4.2f\n\n", det);
    // Countinue from here the attempt to find the adjustible matrix
      
    
      for (p = 0; p < N; p++) {
        for (k = 0; k < N; k++) {

 //printf(RED"\nΜηδενίζουμε τα στοιχεία %2d,%2d του πίνακα\n"RESET,p,k );

        for (i = 0; i < N; i++) {
          for (j = 0; j < N; j++) {


           if (i == p || j == k ){
                temp[i][j] = 0.0;
       }
            else {
               if((p + k) % 2 == 0){
              temp[i][j] = A[i][j];
            } else{
                tempora = A[i][j];
                temp[i][j] = -tempora;
              }
        
      }
    }
   }

    printf("\n\n Εμφάνιση του πίνακα temp!\n");
    for (i = 0; i < N; i++) {
      printf("\n");
      for (j = 0; j < N ; j++) {
        if (temp[i][j] == 0){
        printf(YEL"\t%5.2f"RESET,temp[i][j]);
      } else{
          printf(RED"\t%5.2f"RESET,temp[i][j]);}

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


/*
// Printing The upper triangular Matrix just to be sure no error occured
printf("\n\n\tUpper triangular Matrix\n\n");
    for(i = 0; i < M; i++){
      printf("\n");
        for(j = 0; j < M; j++){
            //scanf("%f", &matrix[i][j]);
            printf("%5.2f\t",matrix1[i][j]);
        }
    }
*/



//printf("\n\n");
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
    for(i=0; i<N; i++){
      printf("\n");
      for (j = 0; j < N; j++) {
        printf("%5.6f\t",Ad[i][j]);
      }
    }

printf("\n");

/*
For every element of the First matrix we will divide by the determinant
  by that we will have the inverse matrix */
    for(i=0; i<N; i++){
      for (j = 0; j < N; j++) {
        division = 0.0;
        if(Ad[i][j] < 0 && det < 0){
            division = (fabs(Ad[i][j])) / (fabs(det));
            inverse[i][j] = division;
        
          }else if(Ad[i][j] < 0 && det > 0){
          division = (fabs(Ad[i][j])) / (fabs(det));
            inverse[i][j] =  0 - division;
      
          }else if(Ad[i][j] > 0 && det < 0){
          division = (fabs(Ad[i][j])) / (fabs(det));
            inverse[i][j] = 0 - division;
          
          }else if(Ad[i][j] > 0 && det > 0){
          division = (fabs(Ad[i][j])) / (fabs(det));
            inverse[i][j] = division;
      }

      }
    }

    //Showing the inversed Matrix
    printf("\nPrinting of the multiplication method matrix!!\n");
    for(i=0; i<N; i++){
      printf("\n");
      for (j = 0; j < N; j++) {
        printf("%5.6f\t",inverse[i][j]);
      }
    }


printf("\n");
    return 0;
}


