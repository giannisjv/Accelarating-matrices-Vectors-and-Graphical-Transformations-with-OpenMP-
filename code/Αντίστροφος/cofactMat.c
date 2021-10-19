#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/ragnlib.h"
#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/colib.h"
#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/functions.h"

#define N 3
#define M 2




int main(){
    float  ratio, det, determinant;
    float A[N][N] = {{1,2,1}, {3,1,0}, {2,1,3}},matrix[N][N], D[N][N];
    float B[N][N], C[N][N];
    int i, j, k, p;
    int x, y;
    //int  M = (N-1);
    float temp[M][M];

    srand(time(NULL));

     for (i = 0; i < N; i++) {
      for (j = 0; j < N ; j++) {
        matrix[i][j] =  A[i][j];
      }
    }


printf("\n\n Εμφάνιση τυχαίου πίνακα %d*%d\n",N,N);
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N ; j++) {
      printf("\t%5.2f",A[i][j]);
    }
  }


//Ευρεση της ορίζουσας

for(i=0; i<N; i++){
  if(matrix[i][i] == 0){
     printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
     printf("\nThe main diagonal has to be any number except 0 zero means Mathemical Error\n" );
     printf("\nJust try again giving no 0 at the main diagonal\n" );
     return -1;
  }

  for(j=i+1; j<N; j++){
    ratio = matrix[j][i] / matrix[i][i];
     //printf("i = (%2d), j = (%2d), ratio = (%2.2f)\n",i, j, ratio );
     for(k=0; k<N; k++){
        matrix[j][k] -= ratio * matrix[i][k];
     }
  }
}



// Printing The upper triangular Matrix just to be sure no error occured
printf("\n\n\tUpper triangular Matrix\n\n");
for(i = 0; i < N; i++){
  printf("\n");
    for(j = 0; j < N; j++){
        //scanf("%f", &matrix[i][j]);
        printf("%15.2f",matrix[i][j]);
    }
}
printf("\n\n");
/* for matrix equals to 1 we multiply the main diagonal.
If any element of the main diagonal is zero
we will have 0 as determinant and the inversion will not be available.
*/
det = 1; //storage for determinant
for(i = 0; i < N; i++)
    det *= matrix[i][i];
printf("\tThe determinant of matrix is: %4.2f\n\n", det);



// μειωση του πινακα απο NxN σε N-1 * N-1
  printf("\n Έυρεση του προσαρμοσμένου πίνακα!\n\n");

 for (p = 0; p < N; p++) {
   for (k = 0; k < N; k++) {
/* 2 Επανάληψεις για να μπορέσουμε να Μηδενίσουμε κάθε στοιχειο του πινακα
   Μηδενίζουμε όλη την γραμμή του i και όλη την γραμμή του j */
  //printf("Μηδενίζουμε τα στοιχεία %2d,%2d του πίνακα\n",p,k );

/* Σε αυτό το σημείο γίνεται σύγκριση του επιλεγμένου στοιχείου του πίνακα
   με το τρέχων στοιχειο. Αν το στοιχείο ειναι το επιλεγμενο (απο την προηγούμενη επανάληψη)
   τότε το στοιχείο γίνεται 0 αλλίως το στοιχειο παραμένει στον πίνακα ως εχει */
   for (i = 0; i < N; i++) {
     for (j = 0; j < N; j++) {

       if (i == p || j == k ){
       B[i][j] = 256;
     }

     else {
       B[i][j] = A[i][j];
     }
     }
   }


   printf("\n\n Εμφάνιση του πίνακα B %d*%d\n",N,N);
     for (i = 0; i < N; i++) {
       printf("\n");
       for (j = 0; j < N ; j++) {
         if (B[i][j] == 256 ){
         printf(YEL"\t%5.2f"RESET,B[i][j]);
       } else{
           printf(RED"\t%5.2f"RESET,B[i][j]);}

       }
     }
   // Τέλος σύγκρισης


   /* Σε αυτή την σύγκριση κάνουμε τον πίνακα απο NxN σε N-1xN-1 */
 //printf("\n");
 x = 0;
 y = -1;
     for (i = 0; i < N; i++) {
       for (j = 0; j < N; j++) {

         if (B[i][j] != 256 && (i != p && j != k)){
           y++;
             if(y == M){
                 x++;
                 y=0;
                 }
                   //printf("x=%d, y=%d\n",x,y);
             temp[x][y] = B[i][j];
       //  printf("i=%2d, j=%2d, x= %2d, y=%2d --> %2d\n",i, j, x, y, temp[x][y]);


       }
     }
   }


   printf("\n\n Εμφάνιση του πίνακα temp %d*%d\n",M,M);
     for (i = 0; i < M; i++) {
       printf("\n" );
       for (j = 0; j < M; j++) {
           printf("%5.2f",temp[i][j]);
       }
     }

      C[k][p] = determinant2x2(temp, k, p);
      //D[p][k] = determinant2x2(temp);



 }
}



/*
   printf("\n\n Εμφάνιση του πίνακα temp %d*%d\n",M,M);
     for (i = 0; i < M; i++) {
       printf("\n" );
       for (j = 0; j < M; j++) {
           printf("%5.2f",temp[i][j]);
       }
     } */
     printf("\n");

     printf("\n\n Εμφάνιση του πίνακα C \n");
     printf(GRN"\nInversed Matrix\n");
       for (i = 0; i < N; i++) {
         printf("\n" );
         for (j = 0; j < N; j++) {
             printf(YEL"%5.2f\t"RESET,C[i][j]);
         }
       }

       for(i=0; i<3; i++){
         for (j = 0; j < 3; j++) {
           C[i][j] /= det;
     }
   }

    printf("\nInversed matrix 3x3\n");
       for (int i = 0; i < N; i++) {
         printf("\n");
         for (int j = 0; j < N; j++) {
           printf("\t%5.2f",C[i][j] );
         }
       }

         printf("\n");



return 0;
}
