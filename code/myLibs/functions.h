/* 
randomness function

randomness function floating Point
*/


double randomGenFloat(double min, double max){
//double min = 1.0;
//double max = 15.0;

  double num = 0.0;
  num = ((max - min) * ((double)rand() / RAND_MAX)) + min;
    return num;
}

//randomness function integer
int randomGenInteger(int min, int max){

  
  int num = rand() % (max - min) + min;
    return num;
}


void display2d(int N, float A[N][N]){
  for (int i = 0; i < N; i++)
  {
    printf("\n");
    for (int j = 0; j < N; j++)
    {
      printf("%.6f\t",A[i][j]);
    }
  }
  printf("\n");
}

void display2dint(int N, int A[N][N]){
  for (int i = 0; i < N; i++)
  {
    printf("\n");
    for (int j = 0; j < N; j++)
    {
      printf("%d\t",A[i][j]);
    }
  }
  printf("\n");
}

void display(int *a, int size){

    for (int i = 0; i <size; i++)
    {
      printf("%d\n",a[i]);
    }
    
}
void display1d(int size, float a[size]){
printf("\n");
    for (int i = 0; i <size; i++)
    {
      printf("%5.6f\n",a[i]);
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

void display_2D_Non_Squared(int **a, int row, int column){
   #include "colib.h"
   for (int i = 0; i <row; i++)
    {
      printf("\n");
      for (int j = 0; j < column; j++)
      {
      printf(MAG"%d\t",a[i][j]);
    }
  }
  printf(RESET"\n\n");
}

void display_2D_Non_Squeredfloat(float **a, int row, int column){
  
   for (int i = 0; i <row; i++)
    {
      printf("\n");
      for (int j = 0; j < column; j++)
      {
      printf("%5.10f\t",a[i][j]);
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

float determinant_tri(float **A, int N){
      float det = 1.0; //storage for determinant
    for(int i = 0; i < N; i++){
        det *= A[i][i]; // finding determinant by multiply trigonal matrix's main diagonal
    }
 return det; 
}

void UpperTriangle(float **A, int N){
      int i, j, k; 
      float ratio;
      
    for (i = 0; i < N; i++) {
      ratio = 0.0;
		  for(j = i + 1; j < N; j++) {
			  ratio = A[j][i] / A[i][i];
          for(k=0; k<N; k++) {
			  		A[j][k] -= ratio * A[i][k];
			   }
		  }
	 }
}

float determinant_tri_non_malloc(int N, float A[N][N]){
      float det = 1.0; //storage for determinant
    for(int i = 0; i < N; i++){
        det *= A[i][i]; // finding determinant by multiply trigonal matrix's main diagonal
    }
 return det; 
}


void UpperTriangleNonMalloc(int N, float A[N][N]){
      int i, j, k; 
      float ratio;
      
    for (i = 0; i < N; i++) {
      ratio = 0.0;
		  for(j = i + 1; j < N; j++) {
			  ratio = A[j][i] / A[i][i];
          for(k=0; k<N; k++) {
			  		A[j][k] -= ratio * A[i][k];
         }
         
		  }
	 }
}

int serial_search(int *A, int N, int searchNum){
int counter = 0;
for(int i=0; i<N; i++){
            if(A[i] == searchNum){
                counter++;
        }
    }
    return counter;
}



int binary_search(int *A, int start, int end, int searchNum){
  int mid, value;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    value = A[mid];
    if (A[value] == searchNum){
      return A[mid];
    }
    else if (A[value] > searchNum){
      end = mid - 1;
      }
    else 
      start = mid + 1;
  }
  return -1;
}

void translate(int **A, int **B, int N, int translationRow, int translationColumn){
     int i, j;
     for ( i = 0; i < N + translationRow; i++){
        for (j = 0; j < N +  translationColumn; j++){
            if(i >= translationRow && j >= translationColumn){
                B[i][j] = A[i - translationRow][j - translationColumn];
            }else
            B[i][j] = 0;
    }
  }
}




void rotation90(int **A, int **B, int N){
  int i,j;
  int x = N - 1;
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[j][x - i] = A[i][j];
        }
    }
}


void rotation180(int **A, int **B, int N){
int i,j;
int x = N - 1;
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[x - i][j] = A[i][j];
        }
    }
}


void rotation270(int **A, int **B, int N){
  int i,j;
  int x = N - 1;
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[x - j][i] = A[i][j];
        }
    }
}

// Scaling

void scaling_filling(int **A, int N, int axisx, int axisy, int min, int max){
    for (int i = 0; i < N + axisx; i++){ 
      for (int j = 0; j < N + axisy; j++){
        if(i < axisx  || j < axisy){
          A[i][j] = 0;
        }else{
          A[i][j] = randomGenInteger(min, max);
      }
    }
  }
}

void scaling_cleaning(int **A, int **temp, int N, int axisx, int axisy, int min, int max){
for (int i = 0; i < N + axisx; i++){
        for (int j = 0; j < N + axisy; j++){
            if(A[i][j] != 0){
                temp[i - axisx][j - axisy] = A[i][j];
      }
    }
  }
}

void scaling(int **temp, int ** temp2, int N, int scalingRow, int scalingColumn){
   for (int i = 0; i < N * scalingRow; i++){
        for (int j = 0; j < N * scalingColumn; j++){
            if(i < N && j < N){
            temp2[i][j] = temp[i][j];
            }else
            temp2[i][j] = 1;
        }
    }
}


void scaling_translate(int **A, int **B, int N, int axisx, int axisy, int scalingRow, int scalingColumn){
     
     int i, j;
     for (i = 0; i < N * scalingRow + axisx; i++){
        for (j = 0; j < N * scalingColumn + axisy; j++){
           if(i < axisx || j < axisy){
              B[i][j] = 0;
              }
              else{
                B[i][j] = A[i - axisx][j - axisy];
                } 

   // B[i][j] = randomGenInteger(1, 50);
    }
  }
}
