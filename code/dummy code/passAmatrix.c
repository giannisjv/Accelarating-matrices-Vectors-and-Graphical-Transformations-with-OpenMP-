// GCC libs
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// MyLibs
#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/ragnlib.h"
#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/colib.h"
#include "/home/giannisvidras/Dropbox/Πτυχιακή/myLibs/functions.h"

//Default public varible values
#define N 2
#define M 3

//determinant for 2x2 Matrix
int determinant2x2(int A[N][N]){

int det;
  det = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
  return det;
}



//determinant for 3x3
int determinant3x3(int B[M][M]){
   int determinant = B[0][0] * ((B[1][1] * B[2][2]) - (B[2][1] * B[1][2])) - B[0][1] * (B[1][0] * B[2][2] - B[2][0] * B[1][2]) + B[0][2] * (B[1][0] * B[2][1] - B[2][0] * B[1][1]);

 return determinant;
}

void display(int A[N][N]) {
  for (int i = 0; i < N; i++) {
    printf("\n");
    for (int j = 0; j < N; j++) {
      printf("\t%d",A[i][j] );
    }
  }
  printf("\n\n-----------------------------\n");
  printf("End of display function\n");
}




void displaytemp(int B[M][M]) {
  for (int i = 0; i < M; i++) {
    printf("\n");
    for (int j = 0; j < M; j++) {
      printf("\t%d",B[i][j] );
    }
  }
  printf("\n\n-----------------------------\n");
  printf("End of display function\n");
}

void displaytempfl(float B[N][N]) {
  for (int i = 0; i < M; i++) {
    printf("\n");
    for (int j = 0; j < M; j++) {
      printf("\t%d",B[i][j] );
    }
  }
  printf("\n\n-----------------------------\n");
  printf("End of display function\n");
}

int main() {
  float temp[N][N];
  int A[N][N], B[M][M], C[1][1], i, j, choice;
  srand(time(NULL));

/*
printf("\nGive the N of the matrix \n" );
printf("Acceptable anwsers 1 to 3\n");
scanf("%d",&choice);
  if (choice == 1) {
    C[0][0] = randomGen();
    printf("The determinant is %d\n",C[0][0]);
  }
  else if(choice == 2){
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      A[i][j] = randomGen();


  }
    }

    printf("\n-----------------------------");
      printf("\nThe determinant is (%d)\n",determinant2x2(A));
      printf("\nThe random generated Matrix\n");
      printf("-----------------------------\n");

      display(A);
  }  /* end of 2x2 if */
  /*
  else if( choice == 3){
    for (i = 0; i < M; i++) {
      for (j = 0; j < M; j++) {
        B[i][j] = randomGen();
    }
      }

      printf("\n-----------------------------");
        printf("\nThe determinant is (%d)\n",determinant3x3(B));
        printf("\nThe random generated Matrix\n");
        printf("-----------------------------\n");

        displaytemp(B);
  }*/
/* this function will work when malloc will appear!

printf("\n-----------------------------");
  printf("\nThe determinant is (%d)\n",determinant2x2(A));
  printf("\nThe random generated Matrix\n");
  printf("-----------------------------\n");

  display(A);
*/
for (i = 0; i < N; i++) {
  for (j = 0; j < N; j++) {
    temp[i][j] = randomGen();

    for (i = 0; i < N; i++) {
      printf("\n");
      for (j = 0; j < N; j++) {
        printf("%d\t",temp[i][j]);

    Uptriangle(temp);
    displaytempfl(temp);




  return 0;
}
