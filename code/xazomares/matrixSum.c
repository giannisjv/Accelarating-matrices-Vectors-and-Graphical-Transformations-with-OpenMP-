#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/functions.h"
#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/colib.h"

#define N 4




int main(){
  int  M = (N-1);
  float A[N][N], B[N][N], C[N][N], temp[M][M];
  float ratio, det;
  int i, j, p, k, d, x, y;

srand(time(NULL));

printf("\n\n");
/* Αρχικοποίηση του πίνακα Α με τυχαίες Τιμες από 1 έως 5*/
for (i = 0; i < N; i++) {
  for (j = 0; j < N; j++) {
    A[i][j] = randomGenFloat(1.0, 15.0); /* Η randomGen είναι μία απλή random generator function
    με σκοπό την εύκολη δημιουργία τυχαίων τιμών.
    Βρίσκεται στο myLibs/ragnlib.h */
  }
}
/* Εμφάνιση του πίνκα Α με τις τυχαίες τιμές */
printf("\n\n Εμφάνιση τυχαίου πίνακα %d*%d\n",N,N);
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N ; j++) {
      printf("\t%5.2f",A[i][j]);
    }
  }


for (p = 0; p < N; p++) {
  for (k = 0; k < N; k++) {

  printf("\nΜηδενίζουμε τα στοιχεία %2d,%2d του πίνακα\n",p,k );

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {


    if (i == p || j == k ){
      B[i][j] = 0;
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
        if (B[i][j] == 0){
        printf(YEL"\t%5.2f"RESET,B[i][j]);
      } else{
          printf(RED"\t%5.2f"RESET,B[i][j]);}

      }
    }
printf("\n");
x = 0;
y = -1;
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {

        if (B[i][j] != 0 && (i != p || j != k)){
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


for(i=0; i < M; i++){
    if(temp[i][i] == 0.0) {
       printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
      // printf("%5.2f, i=%d,%d\n",temp[i][i],i );

       return -1;
    }
  }
  ratio = 0;

    for(i=0; i < M; i++) {
    for(j=i+1; j < M; j++) {
      ratio = temp[j][i] / temp[i][i];
       //printf("i = (%2d), j = (%2d), ratio = (%2.2f)\n",i, j, ratio );

       for(d=0; d < M; d++) {
          temp[j][d] -= ratio * temp[i][d];
       }
    }
 }

printf("\n\n\tUpper triangular temp\n\n");
  for(i = 0; i < M; i++){
    printf("\n");
      for(j = 0; j < M; j++){
          //scanf("%f", &temp[i][j]);
          printf("\t%2.2f",temp[i][j]);
      }
  }
printf("\n\n");

  det = 1; //storage for determinant
  for(i = 0; i < M; i++){
      det *= temp[i][i];
    }
    printf("  The determinant of temp is: %4.2f\n\n", det);
C[p][k] = det;
/*


  printf("\n\n Εμφάνιση τυχαίου πίνακα temp %d*%d\n",M,M);
    for (i = 0; i < M; i++) {
      printf("\n" );
      for (j = 0; j < M; j++) {
          printf("%2d",temp[i][j]);
      }
    }
*/

// Εδώ κλείνει η επίλογή στοιχείων.
  }
}

for (i = 0; i < N; i++) {
  printf("\n");
  for (j = 0; j < N; j++) {
    printf("\t%5.2f",C[i][j]);
  }
}



printf("\n\n");
  return 0;
}
