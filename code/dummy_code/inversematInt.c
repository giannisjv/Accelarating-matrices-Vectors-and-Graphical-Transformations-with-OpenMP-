    #include<stdio.h>
    #include<math.h>


    #include "../myLibs/functions.h"

#define N 10
   // float determinant(float [][25], float);


    float determinant(float [][N], float);


    void cofactor(float [][25], float);

    void transpose(float [][25], float [][25], float);

    int main(){

      float a[25][25], k, d;
      int i, j;

      printf("Enter the order of the Matrix : ");
      scanf("%f", &k);
      printf("Enter the elements of %.0fX%.0f Matrix : \n", k, k);

      for (i = 0;i < k; i++){
          for (j = 0;j < k; j++) {
            scanf("%f", &a[i][j]);
            }
           }

      d = determinant(N, a);
        if (d == 0)
        printf("\nInverse of Entered Matrix is not possible\n");
        else
      cofactor(a, k);

    }

     

    /*For calculating Determinant of the Matrix */


    void cofactor(float num[25][25], float f)

    {

     float b[25][25], fac[25][25];

     int p, q, m, n, i, j;

     for (q = 0;q < f; q++)

     {

       for (p = 0;p < f; p++)

        {

         m = 0;

         n = 0;

         for (i = 0;i < f; i++)

         {

           for (j = 0;j < f; j++)

            {

              if (i != q && j != p)

              {

                b[m][n] = num[i][j];

                if (n < (f - 2))

                 n++;

                else

                 {

                   n = 0;

                   m++;

                   }

                }

            }
         }
          fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
      }
  }

      transpose(num, fac, f);

    }

    /*Finding transpose of matrix*/ 

    void transpose(float num[25][25], float fac[25][25], float r)

    {

      int i, j;

      float b[25][25], inverse[25][25], d;
      
      for (i = 0;i < r; i++){
        for (j = 0;j < r; j++) {

             b[i][j] = fac[j][i];

            }
       }

      d = determinant(N, b);

      for (i = 0;i < r; i++){
        for (j = 0;j < r; j++) {

            inverse[i][j] = b[i][j] / d;
        }
     }
         printf("\n\n\nThe inverse of matrix is : \n");

       for (i = 0;i < r; i++){
         for (j = 0;j < r; j++) {
               printf("\t%f", inverse[i][j]);
            }
          printf("\n");
       }
     }