#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../../myLibs/functions.h"
#include "../../myLibs/colib.h"

#define cores 8
#define min 1
#define max 1000
int main(int argc, char const *argv[]) {

  srand(time(NULL));

    time_t start,  end; 
    double time_taken = 0.0;	                        // Start and end time

    double staticSt = 0.0, staticEn = 0.0;
    double time_takenSt = 0.0;
                              // variable to mesure the time algorith took to run 
    double dynamicSt = 0.0, dynamicEn = 0.0;
    double time_takedy = 0.0;
    
    double guidedSt = 0.0, guidedEn = 0.0;
    double time_takengu = 0.0;	
    					
	
  
  
  int chunk, c;            // A variety of variables!
  int i, j, p, l, sum = 0, counter = 0;
  int NA, MA, NB, MB;
  int **A, **B, **C;
  int RowsA, ColumnsA;
  int RowsB, ColumnsB;

/*
  printf("\n Insert First Matrix's Number of Rows: \n");   // Inserting the first Matrix
  scanf("%d",&NA);

  printf("\n Insert First Matrix's Number of Columns from A \n and Rows from B: \n"); // Inserting the second Matrix

  scanf("%d",&MA);

  printf("\nInsert Second Matrix's Number of Columns: \n");

  scanf("%d",&MB);

  */
 NA = NB = MA = MB =10000;

  RowsA =  NA * sizeof(int *);
  ColumnsA = MA * sizeof(int);

  RowsB =  NB * sizeof(int *);
  ColumnsB = MB * sizeof(int);

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
            for (j=0; j<MA; j++) 
            A[i][j] = randomGenInteger(min, max);
            B[i][j] = randomGenInteger(min, max);
          }

  printf("\n\t\tSerial\t\tStatic\t\tdynamic\t\tguided  \tchunk\t N\tCores");

  //for ( chunk = 1; chunk <= 4096; chunk *= 2) {
    printf("\n");
    for(c = 2; c <= cores; c *= 2){
    /*if(c == 1){
        start = clock();
      matrix_multi_serial(A, B, C, NA, MA, MA);
        end = clock();
  } else{*/
      #pragma omp parallel num_threads(c)
     {
       staticSt = omp_get_wtime();
      #pragma omp  for schedule(static) private(i, j, p, sum)
          for(i=0; i<NA; i++){
            for (j=0; j<MA; j++){
              sum = 0;
              for(p=0; p<MA; p++){
                 sum += A[i][p] * B[p][j];
              }
                 C[i][j] = sum;
                 sum = 0;
          }
        }
       staticEn = omp_get_wtime();
        //matrix_multi_checker(A, B, C, NA, MA, MA);
       dynamicSt = omp_get_wtime();

	  #pragma omp  for schedule(dynamic) private(i, j, p, sum)
			  for(i=0; i<NA; i++){
            for (j=0; j<MB; j++) {
              sum = 0;
              for(p=0; p<MA; p++)

                sum += A[i][p] * B[p][j];

          C[i][j] = sum;
          sum = 0;
        }
      }
      dynamicEn = omp_get_wtime();
      //matrix_multi_checker(A, B, C, NA, MA, MA);
      guidedSt = omp_get_wtime();
    #pragma omp  for schedule(guided) private(i, j, p, sum)
        for(i=0; i<NA; i++){
            for (j=0; j<MB; j++) {
              sum = 0;
              for(p=0; p<MA; p++)
              sum += A[i][p] * B[p][j];
          C[i][j] = sum;
          sum = 0;
          }
        }
      guidedEn = omp_get_wtime();

      }
    //}
    
   //matrix_multi_checker(A, B, C, NA, MA, MA);
/*if(c == 1){
	time_taken = (end-start);
	time_taken /= CLOCKS_PER_SEC;
    time_takenSt = time_takedy = time_takengu = 0.0;
    } else{
    time_taken = 0.0;*/
    time_takenSt = (staticEn - staticSt);
    time_takedy = (dynamicEn - dynamicSt);
    time_takengu = (guidedEn - guidedSt);
    //}
	printf("\n\t%15.6f, %15.6f,%15.6f, %15.6f,\t%d \t%d, \t  %d",time_taken, time_takenSt, time_takedy, time_takengu, chunk,  NA * MB, c);

      /*    -------------------------------------
             | print statements for the Matrices |
             -------------------------------------
*/
/*
            printf("\n\nMatrix A\n");
            display_2D_Non_Squered(A, NA, MA);
            printf("\nMatrix B\n");
            display_2D_Non_Squered(B, NB, MB); 
            printf("\n\nMatrix C\n");
            display_2D_Non_Squered(C, NA, MB);
             matrix_multi_checker(A, B, C, NA, MA, MA);
             */
    }    
             free(A);
             free(B);
             free(C);
printf("\n");
  return 0;
}
