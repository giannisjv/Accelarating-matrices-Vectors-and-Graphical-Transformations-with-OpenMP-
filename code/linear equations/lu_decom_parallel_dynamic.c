#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/functions.h"
#include "../myLibs/colib.h"

#define cores 8
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    double start, end, time_taken;
    int N = 150;
    float det, det_temp;
    float A[N][N], B[N][N], X[N], Z[N];
    int i, j, p, k, g, c, chunk;

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            A[i][j] = randomGenFloat(1, 10);
            B[i][j] = A[i][j];
            Z[i] = randomGenFloat(1, 10);
    }
}
    /*
    printf("\nDisplay A");
    display2d(N, A);
    printf("\nDisplay solution ");
    display1d(N, Z);
*/

    
    
    printf("\ndynamic program\n");
    printf("\nTime\t\tchunk\tcores\tN\n");
    for ( chunk = 1; chunk <= 4096; chunk *=2){
           printf("\n");
      for ( c = 2; c <= cores; c *=2){
        
    start = omp_get_wtime();
    UpperTriangleNonMalloc(N, B);
    det = determinant_tri_non_malloc(N, B);
    
    #pragma omp parallel num_threads(c)
    {
    #pragma omp for collapse(2) schedule(dynamic, chunk)
    for (i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            B[i][j] = A[i][j];
        }
    }

    #pragma omp single
    {
    for (i = 0; i < N; i++){
        for (g = 0; g < N; g++){
             B[g][i] = Z[g]; 
         }
        for ( j = 0; j < N; j++){
           
            //display2d(N, B);
            UpperTriangleNonMalloc(N, B);
            det_temp = determinant_tri_non_malloc(N, B);
        }
        X[i] = det_temp;
           for (p = 0; p < N; p++){
            for ( k = 0; k < N; k++){
                B[p][k] = A[p][k];
            }
        }
    }
}

 #pragma omp for collapse(1) schedule(dynamic, chunk)
  for (i = 0; i < N; i++){
    X[i] /= det;
  }
}
end = omp_get_wtime();

  //display1d(N, X);
time_taken = end - start;
printf("%5.6f\t%d\t%d\t%d\n",time_taken, chunk, c, N);
time_taken = end = start = 0;
      }
    }

    return 0;
}
