
// 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 //

//randomness function

//randomness function floating Point



double randomGenFloat(double min, double max){
//double min = 1.0;
//double max = 15.0;

  double num = 0.0;
  num = ((max - min) * ((double)rand() / RAND_MAX)) + min;
    return num;
};

//randomness function integer
int randomGenInteger(int min, int max){

  
  int num = rand() % (max - min) + min;
    return num;
};



float determinant2x2(float A[2][2], int a, int b){

float det;

  int sum = a + 1 + b + 1;
  if (sum % 2 == 0){
    det = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
  }
  else{
    det = -(A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
  }

  return det;
};


//determinant for 3x3
float determinant3x3(float B[3][3]){
   float determinant = B[0][0] * ((B[1][1] * B[2][2]) - (B[2][1] * B[1][2])) - B[0][1] * (B[1][0] * B[2][2] - B[2][0] * B[1][2]) + B[0][2] * (B[1][0] * B[2][1] - B[2][0] * B[1][1]);

 return determinant;
};


float inverse3x3(float A[3][3], int det){

  int i,j;

  for(i=0; i<3; i++){
    for (j = 0; j < 3; j++) {
      A[i][j] /= det;
    }
  }
  return A[i][j];
};

void display(int *a, int size){

    for (int i = 0; i <size; i++)
    {
      printf("%d\n",a[i]);
    }
    
}

void display2D(int **a, int size){
   for (int i = 0; i <size; i++)
    {
      printf("\n");
      for (int j = 0; j < size; j++)
      {
      printf("%d\t",a[i][j]);
    }
  }
}

void display_2D_Non_Squered(int **a, int row, int column){
   for (int i = 0; i <row; i++)
    {
      printf("\n");
      for (int j = 0; j < column; j++)
      {
      printf("%d\t",a[i][j]);
    }
  }
}

void scalar_matrix_corr(int **A, int **B, int N, int M, int Numb){
int i, j;
  for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(B[i][j] != A[i][j] * Numb){
					printf("number: (%d) thesi x: (%d), y: (%d) Expected number: (%d) \n",B[i][j], i,j,A[i][j]*Numb );
				}
			}
		}
}
void transpose(int **a, int **b, int N){
for (int i = 0; i < N; i++)
{
  for (int  j = 0; j < N; j++)
  {
    if(b[i][j] != a[j][i]){
					printf("number: (%d) thesi x: (%d), y: (%d) Expected number: (%d) \n",b[i][j], i, j, a[j][i]);
      }
    }
  }
}


void matrix_multi_checker(int **a, int **b, int **c, int rowA, int columnB, int columnA){
int i,j,p;
int sum = 0;

for(i=0; i<rowA; i++){
  for (j=0; j<columnB; j++) {
      for(p=0; p<columnA; p++){
      sum += a[i][p] * b[p][j];
}
    if(c[i][j] !=  sum){
      printf("\nWrong at %d,%d,%d\n", i, j, sum );
    }
     sum = 0;
    }
  }
}

void matrix_multi_serial(int **a, int **b, int **c, int rowA, int columnB, int columnA){
int i,j,p;

for(i=0; i<rowA; i++){
  for (j=0; j<columnB; j++) {
     c[i][j] = 0;
    for(p=0; p<columnA; p++){
      c[i][j] += a[i][p] * b[p][j];
  }
    }
  }
}

void zero_matrix(int **c, int rowA, int columnB){
  int i, j, p;
  for(i=0; i<rowA; i++){
    for (j=0; j<columnB; j++) 
      c[i][j] = 0;
  }
}

/*
float determinant(int N, float A[N][N]){
      
      float s = 1, det = 0, b[N][N];
      int i, j, m, n, c;
      
      if (N == 1){
         return (A[0][0]);
        } else {
         det = 0;
         
         for (c = 0; c < N; c++){
            m = 0;
            n = 0;
            for (i = 0;i < N; i++){
                for (j = 0 ;j < N; j++){
                    
                    b[i][j] = 0;
                    
                    if (i != 0 && j != c){
                       b[m][n] = A[i][j];
                       if (n < (N - 2))
                        n++;
                       else{
                         n = 0;
                         m++;
          }
       }
    }
}
           det = det + s * (A[0][c] * determinant(b, N - 1));
              s = -1 * s;
            }
        }
        return (det);
         }; 

  for (int i = 0; i < N; i++) {
    printf("\n");
    for (int j = 0; j < N; j++) {
      printf("\t%d",A[i][j] );
    }
  }
  printf("\n\n-----------------------------\n");
  printf("End of display function\n");
};


void displayMatr(int N, float A[][N]){
  printf("\n\n Εμφάνιση τυχαίου πίνακα %d*%d\n",N,N);
  for (int i = 0; i < N; i++) {
    printf("\n");
    for (int j = 0; j < N ; j++) {
      printf("\t%5.6f",A[i][j]);
    }
  }
};

*/