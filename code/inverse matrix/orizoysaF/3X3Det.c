#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include "/home/giannisvi/Dropbox/Πτυχιακή/myLibs/ragnlib.h"
#include "/home/giannisvi/Dropbox/Πτυχιακή/myLibs/colib.h"

#define N 3

int main(){

srand(time(NULL));
 int a[N][N];
 int i,j;
 float determinant=1;



 //printf("Enter the %d elements of matrix: ",N*N);
 for(i = 0; i < N; i++){
     for(j = 0; j < N; j++){
/*
       printf("Δώσε το στοιχείο x: (%d) και y: (%d) του πίνακα Α\n",i+1,j+1 );
         scanf("%f", &a[i][j]);
*/
         a[i][j] = randomGen();
         printf("%d\t",randomGen );
     }
 }

 printf("\nThe First matrix is\n");
 for(i=0;i<N;i++){
     printf("\n");
     for(j=0;j<N;j++)
          printf("%5.4f\t",a[i][j]);
 }

 for(i=0;i<N;i++)
     determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));

 printf("\n\n"YEL"Determinant of matrix is: "RED"%d\n\n"RESET,determinant);

  return 0;
}
