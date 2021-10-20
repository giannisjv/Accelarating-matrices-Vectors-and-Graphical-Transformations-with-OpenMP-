#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define randomness 5
int main(int argc, char const *argv[]) {

  srand(time(NULL));
  time_t start, end;
  double time_taken;

  int i, j, N, p;
  int **A, **B, **C;
  int Rows, Columns;

  printf("\nN:  ");
  scanf("%d",&N);
  Rows = N * sizeof(int *);
  Columns = N * sizeof(int);

  A = (int **)malloc(Rows);
    for(i=0;i<N;i++){
      A[i] = (int *)malloc(Columns);
    }

    if(!A){
      printf("The Array is too big\nExiting\n");
      return -1;
    }

    B = (int **)malloc(Rows);
      for(i=0;i<N;i++){
        B[i] = (int *)malloc(Columns);
      }

if(!B){
        printf("The Array is too big\nFreeing A and Exiting\n");
        free(A);
        return -1;
      }



        C = (int **)malloc(Rows);
          for(i=0;i<N;i++){
            C[i] = (int *)malloc(Columns);
          }

if(!C){
        printf("The Array is too big\nFreeing A and B\nExiting\n");
        free(A);
        free(B);
        return -1;
          }

          for(i=0; i<N; i++){
            for (j=0; j<N; j++) {
              A[i][j] = rand() % randomness + 1;
            }
          }

          for(i=0; i<N; i++){
            for (j=0; j<N; j++) {
              B[i][j] = rand() % randomness + 1;
            }
          }


          for(i=0; i<N; i++){
            for (j=0; j<N; j++) {
              C[i][j] = 0;
              for(p=0; p<N; p++){

              C[i][j] += A[i][p] * B[p][j];
              printf("\n\ni = (%d) j= (%d) p = (%d) C = (%d)",i,j,p,C[i][j] );
            }

          }
        }



          /* ---------------------------------
             |print statements for the arrays|
             --------------------------------- */

             printf("\n\nArray A\n");
             for(i=0; i<N; i++){
               printf("\n");
               for (j=0; j<N; j++) {
                 printf("(%d)\t", A[i][j]);
                              }
             }

             printf("\n\nArray B\n");
             for(i=0; i<N; i++){
               printf("\n");
               for (j=0; j<N; j++) {
                 printf("(%d)\t", B[i][j]);
                              }
             }

             printf("\n\nArray C\n");
             for(i=0; i<N; i++){
               printf("\n");
               for (j=0; j<N; j++) {
                 printf("(%d)\t", C[i][j]);
                              }
             }

printf("\n\n");
             free(A);
             free(B);
             free(C);

  return 0;
}
