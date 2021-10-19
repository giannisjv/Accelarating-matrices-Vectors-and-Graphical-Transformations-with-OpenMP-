#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define randomness 2500
int main(int argc, char const *argv[]) {

  srand(time(NULL));
  time_t start, end;
  double time_taken;


  int i, j, p,l, a = 0;
  int NA, MA, NB, MB;
  int **A, **B, **C;
  int RowsA, ColumnsA;
  int RowsB, ColumnsB;


  /* Inserting the first Matrix */
  printf("\n Insert First Matrix's Number of Rows: \n");
  scanf("%d",&NA);

  printf("\n Insert First Matrix's Number of Columns from A \n and Rows from B: \n");

  scanf("%d",&MA);
/* Inserting the second Matrix */
  NB = MA;

  printf("\nInsert Second Matrix's Number of Columns: \n");

  scanf("%d",&MB);

/* checking if both Matrices Rows from A are equal to Columns from B
and if Rows from B are equal to Columns from A*/

/* checking finished */


  RowsA =    NA * sizeof(int *);
  ColumnsA = MA * sizeof(int);

  RowsB =    NB * sizeof(int *);
  ColumnsB = MB * sizeof(int);
  //printf("Here i am Before malloc\n" );

  A = (int **)malloc(RowsA);
    for(i=0;i<NA;i++){
      A[i] = (int *)malloc(ColumnsA);
    }


    if(!A){
      printf("The Matrix is too big\nExiting\n");
      return -1;
    }

    B = (int **)malloc(RowsB);
      for(i=0; i<NB; i++){
        B[i] = (int *)malloc(ColumnsB);
      }

if(!B){
        printf("The Matrix is too big\nFreeing A and Exiting\n");
        free(A);
        return -1;
      }

        C = (int **)malloc(RowsA);
          for(i=0;i<NA;i++){
            C[i] = (int *)malloc(ColumnsB);
          }

if(!C){
        printf("The Matrix is too big\nFreeing A and B\nExiting\n");
        free(A);
        free(B);
        return -1;
          }


          for(i=0; i<NA; i++){
            for (j=0; j<MA; j++) {
            A[i][j] = rand() % randomness + 1;

            }
          }


          for(i=0; i<NB; i++){
            for (j=0; j<MB; j++) {
              B[i][j] = rand() % randomness + 1;

            }
          }


          for(i=0; i<NA; i++){
            for (j=0; j<MB; j++) {
              C[i][j] = 0;
            }
          }

      start = clock();

          for(i=0; i<NA; i++){
            for (j=0; j<MB; j++) {
              for(p=0; p<MA; p++){

                  /* code */
                  a += A[i][p] * B[p][j];
            //  printf("\n\ni = (%d) j= (%d) p = (%d) C = (%d)",i,j,p,C[i][j] );

          }
          C[i][j] = a;
          a=0;

          }
        }

end = clock();


  time_taken = (end - start);
  time_taken /= CLOCKS_PER_SEC;

      /*    -------------------------------------
             | print statements for the Matrices |
             -------------------------------------*/

            /* printf("\n\nMatrix A\n");
             for(i=0; i<NA; i++){
               printf("\n");
               for (j=0; j<MA; j++) {
                 printf("(%d)\t", A[i][j]);
                              }
             }

             printf("\n\nMatrix B\n");
             for(i=0; i<NB; i++){
               printf("\n");
               for (j=0; j<MB; j++) {
                 printf("(%d)\t", B[i][j]);
                              }
             }

             printf("\n\nMatrix C\n");
             for(i=0; i<NA; i++){
               printf("\n");
               for (j=0; j<MB; j++) {
                 printf("(%d)\t", C[i][j]);
                              }
}*/

printf("\nTime took to run the program: (%5.6f)\n",time_taken );
             free(A);
             free(B);
             free(C);

  return 0;
}
