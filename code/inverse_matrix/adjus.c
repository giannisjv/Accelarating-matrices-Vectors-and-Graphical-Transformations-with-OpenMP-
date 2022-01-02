#include <stdio.h>

#include <time.h>
#include <stdlib.h>

#include "../../myLibs/ragnlib.h"
#include "../../myLibs/colib.h"

#define N 4

int main(int argc, char const *argv[]) {

  int A[N][N], B[N][N], C[N-1][N-1], adju[N][N];
  int  i ,j, p, k, ti, tj, x, y, counter = 0;


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

  for (x = 0; x < N-1; x++) {
    for (y = 0; y < N-1; y++) {

  if(B[i][j] != 0 && (i != p || j != k )){
    C[i][j] = B[i][j];
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

    printf("\n\n Εμφάνιση του πίνακα C %d*%d\n",N-1,N-1);
      for (i = 0; i < N-1; i++) {
        printf("\n");
        for (j = 0; j < N-1 ; j++) {
          printf("\t%5d",C[i][j]);

        }
      }

    printf("\n");
    }
  }


//printf("\n");
  return 0;
}
