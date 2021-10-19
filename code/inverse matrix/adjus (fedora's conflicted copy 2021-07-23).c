#include <stdio.h>

#include <time.h>
#include <stdlib.h>

#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/ragnlib.h"
#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/colib.h"

#define N 4

int main(int argc, char const *argv[]) {

  int M = (N-1 * N-1);
  int A[N][N], B[N][N], adju[N][N];
  int  i ,j, p, k, x, t, ti, tj, counter = 0, temp;
  float ratio;


  srand(time(NULL));

  for (i = 0; i < N; i++) {
    for (j = 0; j < N ; j++) {
      A[i][j] = randomGen();
    }
  }

printf("\n\n Εμφάνιση τυχαίου πίνακα %d*%d\n",N,N);
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N ; j++) {
      printf("\t%5d",A[i][j]);
    }
  }


 printf("\n Έυρεση του προσαρμοσμένου πίνακα!\n\n");

for (p = 0; p < N; p++) {
  for (k = 0; k < N; k++) {




  printf("Μηδενίζουμε τα στοιχεία %2d,%2d του πίνακα\n",p,k );



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
        printf(YEL"\t%5d"RESET,B[i][j]);
      } else{  printf("\t%5d",B[i][j]);}

      }
    }

//Πρέπει να γίνει μετατροπή απο Ν*Ν σε Ν-1 * Ν-1 για να μπορέσει να δουλέψει η μετατροπή σε άνω τριγωνικό πίνακα.
/*
  for(i=0; i<N; i++){
    if(B[i][j] != 0 && (i != p || j != k)){
      if(B[i][i] == 0){
       printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
       return -1;
    }

    for(j=i+1; j<N; j++){
      ratio = B[j][i] / B[i][i];
       //printf("i = (%2d), j = (%2d), ratio = (%2.2f)\n",i, j, ratio );

       for(t=0; t<N; t++){
          B[j][t] -= ratio * B[i][t];
       }
    }
 }
}

 printf("\n\n\tUpper triangular Matrix\n\n");
     for(i = 0; i < N; i++){
       printf("\n");
         for(j = 0; j < N; j++){
             //scanf("%f", &matrix[i][j]);
             printf("%15.2f",B[i][j]);
         }
     }
*/
    printf("\n");
    }
  }


//printf("\n");
  return 0;
}
