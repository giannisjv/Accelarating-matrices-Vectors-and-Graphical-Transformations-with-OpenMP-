#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../myLibs/functions.h"
#include "../myLibs/colib.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    time_t start, end;
    double time_took = 0.0;
    int N = 150;
    float det, det_temp;
    float A[N][N], B[N][N], X[N], Z[N];
    int counter = 0, i, j, p, k, g;

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
printf("\nSerial Program\n");
while(counter != 13){
    counter++;
    start = clock();
    UpperTriangleNonMalloc(N, B);
    det = determinant_tri_non_malloc(N, B);
    //printf("\n%.2f", det);

    for (i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            B[i][j] = A[i][j];
        }
    }

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
  for (i = 0; i < N; i++){
    X[i] /= det;
  }
  end = clock();
  time_took = end - start;
  time_took /= CLOCKS_PER_SEC;
  
 printf("\n\nTime took %5.6f", time_took);
  //display1d(N, X);
}


    return 0;
}
