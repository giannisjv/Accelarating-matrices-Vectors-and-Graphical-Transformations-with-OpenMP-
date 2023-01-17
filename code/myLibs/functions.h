
// 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 //

//randomness function

//randomness function floating Point



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

int serial_search(int **A, int N, int searchNum){
int counter = 0;
for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j] == searchNum){
                counter++;
            }
        }
    }
    return counter;
}


int serial_search_parallel(int **A, int N, int searchNum, int cores){
int counter = 0;
#pragma omp parallel for collapse(2) schedule(static) num_threads(cores) reduction(+ : counter) 
for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j] == searchNum){
                counter++;
            }
        }
    }
    return counter;
}
/*
int binary_search_par(int **A, int start, int end, int searchNum){
    
  int mid, row, col, value;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    row = mid / end;
    col = mid % end;
    value = A[row][col];

    if (value == searchNum){
      printf("\nFound\n");
      return 1;
    }
    else if (value > searchNum){
      end = mid - 1;
      }
    else
      start = mid + 1;
  }
  return -1;
}

void binary_search_par_workSharing(int **A, int N, int searchNum, int num_threads){
    int result;
    int mid, row, col, value, start = 0, end = N - 1;
    double start_time, end_time, time_took;

    mid = start + (end - start) / 2;
    row = mid / N;
    col = mid % N;
    value = A[row][col];

    int thread_one, thread_two, thread_three, thread_four;
    int quarter_slice = mid / 2;

     printf("\n****** Now beginning Parallel work with OpenMP ******\n\n");
     printf("Starting binary search...\n");

          start = omp_get_wtime();

#pragma omp parallel num_threads(num_threads)
    {
#pragma omp sections
        {

#pragma omp section
            thread_one = binary_search_par(A, 0, quarter_slice, searchNum);
#pragma omp section
            thread_two = binary_search_par(A, quarter_slice + 1, mid, searchNum);
#pragma omp section
            thread_three = binary_search_par(A, mid + 1, quarter_slice * 3, searchNum);
#pragma omp section
            thread_four = binary_search_par(A, (quarter_slice * 3) + 1, end, searchNum);
        }
    }

    end_time = omp_get_wtime();
    time_took = end_time - start_time;
    time_took /=CLOCKS_PER_SEC;
    printf("Work took %f seconds\n", time_took);

    // Print results of serial Binary search
    if (result != -1)
    {
        printf("Element %d found! At index %d\n", searchNum, result);
    }
    else
    {
        printf("Element %d not found\n", searchNum);
    }
    printf("\n");
}
*/