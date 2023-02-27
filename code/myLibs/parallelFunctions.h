/*|===================================|
  |start of serial search functions   |
  |===================================|
*/

int serial_search_parallel_static(int *A, int N, int searchNum, int cores, int chunk){
int result;
#pragma omp parallel for schedule(static, chunk) num_threads(cores) reduction(+ : counter)
for(int i=0; i<N; i++){
            if(A[i] == searchNum)
                result = A[i];
    }
    return result;
}

int serial_search_parallel_Dynamic(int *A, int N, int searchNum, int cores, int chunk){
int result;
#pragma omp parallel for schedule(dynamic, chunk) num_threads(cores) reduction(+ : counter)
for(int i=0; i<N; i++){
            if(A[i] == searchNum)
                result = A[i];
    }
    return result;
}


int serial_search_parallel_Guided(int *A, int N, int searchNum, int cores, int chunk){
int result;
#pragma omp parallel for schedule(guided, chunk) num_threads(cores) reduction(+ : counter)
for(int i=0; i<N; i++){
            if(A[i] == searchNum)
                result = A[i];
    }
    return result;
}



/*|===================================|
  |end of serial search functions     |
  |===================================|
*/


/*|==========================================|
  |Start of serial binary paralell functions |
  |==========================================|
*/

void parallel_work(int *A, int N, int searchVal, int num_threads){

    int result;
    double start, end, total_time;

    // For use with Parallel search
    int first = 0;
    int last = N - 1;
    int middle = first + (last - first) / 2;

    // Array will be sliced into sections
    int thread_one, thread_two, thread_three, thread_four;
    int quarter_slice = middle / 2;

   // printf("\n****** Now beginning Parallel work with OpenMP ******\n\n");

    // printf("Starting binary search...\n");

    start = omp_get_wtime();

#pragma omp parallel num_threads(num_threads)
    {
#pragma omp sections
        {
        /* Function parameters:
            binarySearch_openmp(first_index, last_index, search_value);
        */

#pragma omp section
            thread_one = binary_search(A, 0, quarter_slice, searchVal);
#pragma omp section
            thread_two = binary_search(A, quarter_slice + 1, middle, searchVal);
#pragma omp section
            thread_three = binary_search(A, middle + 1, quarter_slice * 3, searchVal);
#pragma omp section
            thread_four = binary_search(A,  (quarter_slice * 3) + 1, last, searchVal);
        }
    }

    end = omp_get_wtime();
    total_time = end - start;

    if(thread_one != -1){
      result = thread_one;
    }
    else if(thread_two != -1){
      result = thread_two;
    }
    else if(thread_three != -1){
      result = thread_three;
    }
    else if(thread_four != -1){
      result = thread_four;
    }else
    result = -1;
    
    
    printf("Work took %f seconds ", total_time);

    // Print results of serial Binary search
    if (result != -1)
    {
        printf("Element %d found! At index %d\n", searchVal, result);
    }
    else
    {
        printf("Element %d not found\n", searchVal);
    }
    printf("\n");
}


/*|==========================================|
  |end of serial binary paralell functions   |
  |==========================================|
*/


/*|===============================|
  |start of translate functions   |
  |===============================|
*/
void parallel_translate_static(int **A, int **B, int N, int translationRow, int translationColumn, int threads, int chunk){

     int i, j;
#pragma omp parallel for collapse(2) schedule(static, chunk) num_threads(threads)
  for ( i = 0; i < N + translationRow; i++){
    for (j = 0; j < N +  translationColumn; j++){
     if(i >= translationRow && j >= translationColumn){
      B[i][j] = A[i - translationRow][j - translationColumn];
    }else
      B[i][j] = 0;
    }
  }
}


void parallel_translate_dynamic(int **A, int **B, int N, int translationRow, int translationColumn, int threads, int chunk){

     int i, j;
     #pragma omp parallel for collapse(2) schedule(dynamic, chunk) num_threads(threads)
     for ( i = 0; i < N + translationRow; i++){
        for (j = 0; j < N +  translationColumn; j++){
            if(i >= translationRow && j >= translationColumn){
                B[i][j] = A[i - translationRow][j - translationColumn];
            }else
            B[i][j] = 0;
    }
  }
}

void parallel_translate_guided(int **A, int **B, int N, int translationRow, int translationColumn, int threads){

     int i, j;
     #pragma omp parallel for collapse(2) schedule(guided) num_threads(threads)
     for ( i = 0; i < N + translationRow; i++){
        for (j = 0; j < N +  translationColumn; j++){
            if(i >= translationRow && j >= translationColumn){
                B[i][j] = A[i - translationRow][j - translationColumn];
            }else
            B[i][j] = 0;
    }
  }
}

/*|===============================|
  |end of translate functions     |
  |===============================|
*/


/*|===============================|
  |start of rotation functions    |
  |rotation functions is about    |
  |90, 180, 270 degrees           |
  |===============================|
*/

// Static functions
void parallel_rotation90_static(int **A, int **B, int N, int threads, int chunk){
  int i, j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(static, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[j][x - i] = A[i][j];
        }
    }
}

void parallel_rotation180_static(int **A, int **B, int N, int threads, int chunk){
int i,j;
int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(static, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[x - i][x - j] = A[i][j];
        }
    }
}


void parallel_rotation270_static(int **A, int **B, int N, int threads, int chunk){
  int i,j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(static, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[x - j][i] = A[i][j];
        }
    }
}

//===============================
// dynamic function
void parallel_rotation90_dynamic(int **A, int **B, int N, int threads, int chunk){
  int i, j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(dynamic, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[j][x - i] = A[i][j];
        }
    }
}

void parallel_rotation180_dynamic(int **A, int **B, int N, int threads, int chunk){
int i,j;
int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(dynamic, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[x - i][x - j] = A[i][j];
        }
    }
}


void parallel_rotation270_dynamic(int **A, int **B, int N, int threads, int chunk){
  int i,j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(dynamic, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[x - j][i] = A[i][j];
        }
    }
}

//====================================
// guided function
void parallel_rotation90_guided(int **A, int **B, int N, int threads, int chunk){
  int i, j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(guided, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[j][x - i] = A[i][j];
        }
    }
}

void parallel_rotation180_guided(int **A, int **B, int N, int threads, int chunk){
int i,j;
int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(guided, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[x - i][x - j] = A[i][j];
        }
    }
}


void parallel_rotation270_guided(int **A, int **B, int N, int threads, int chunk){
  int i,j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(guided, chunk) num_threads(threads)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[x - j][i] = A[i][j];
        }
    }
}

/*|===============================|
  |start of Scaling functions     |
  |Scaling functions is about     |
  |Filling an array, cleaning     |
  |scaling and translating at the |
  |original location              |
  |===============================|
*/

// Scaling Static

void scaling_filling_Static(int **A, int N, int axisx, int axisy, int min, int max, int chunk){
  #pragma omp for collapse(2) schedule(static, chunk)
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

void scaling_cleaning_static(int **A, int **temp, int N, int axisx, int axisy, int chunk){
   #pragma omp for collapse(2) schedule(static, chunk)
for (int i = 0; i < N + axisx; i++){
        for (int j = 0; j < N + axisy; j++){
            if(A[i][j] != 0){
                temp[i - axisx][j - axisy] = A[i][j];
      }
    }
  }
}



// Scaling Dynamic

void scaling_filling_dynamic(int **A, int N, int axisx, int axisy, int min, int max, int chunk){
  #pragma omp for collapse(2) schedule(dynamic, chunk)
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

void scaling_cleaning_dynamic(int **A, int **temp, int N, int axisx, int axisy, int chunk){
   #pragma omp for collapse(2) schedule(dynamic, chunk)
for (int i = 0; i < N + axisx; i++){
        for (int j = 0; j < N + axisy; j++){
            if(A[i][j] != 0){
                temp[i - axisx][j - axisy] = A[i][j];
      }
    }
  }
}

void scaling_dynamic(int **temp, int ** temp2, int N, int scalingRow, int scalingColumn, int chunk){
   #pragma omp for collapse(2) schedule(dynamic, chunk)
   for (int i = 0; i < N * scalingRow; i++){
        for (int j = 0; j < N * scalingColumn; j++){
            if(i < N && j < N){
            temp2[i][j] = temp[i][j];
            }else
            temp2[i][j] = 1;
        }
    }
}

void scaling_translate_dynamic(int **A, int **B, int N, int axisx, int axisy, int scalingRow, int scalingColumn, int chunk){
      #pragma omp for collapse(2) schedule(dynamic, chunk)
     for (int i = 0; i < N * scalingRow + axisx; i++){
        for (int j = 0; j < N * scalingColumn + axisy; j++){
           if(i < axisx || j < axisy){
              B[i][j] = 0;
              }
              else{
                B[i][j] = A[i - axisx][j - axisy];
                } 
    }
  }
}

// Scaling Guided

void scaling_filling_guided(int **A, int N, int axisx, int axisy, int min, int max){
  #pragma omp for collapse(2) schedule(guided)
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

void scaling_cleaning_guided(int **A, int **temp, int N, int axisx, int axisy){
   #pragma omp for collapse(2) schedule(guided)
for (int i = 0; i < N + axisx; i++){
        for (int j = 0; j < N + axisy; j++){
            if(A[i][j] != 0){
                temp[i - axisx][j - axisy] = A[i][j];
      }
    }
  }
}

void scaling_guided(int **temp, int ** temp2, int N, int scalingRow, int scalingColumn){
   #pragma omp for collapse(2) schedule(guided)
   for (int i = 0; i < N * scalingRow; i++){
        for (int j = 0; j < N * scalingColumn; j++){
            if(i < N && j < N){
            temp2[i][j] = temp[i][j];
            }else
            temp2[i][j] = 1;
        }
    }
}

void scaling_translate_guided(int **A, int **B, int N, int axisx, int axisy, int scalingRow, int scalingColumn){
      #pragma omp for collapse(2) schedule(guided)
     for (int i = 0; i < N * scalingRow + axisx; i++){
        for (int j = 0; j < N * scalingColumn + axisy; j++){
           if(i < axisx || j < axisy){
              B[i][j] = 0;
              }
              else{
                B[i][j] = A[i - axisx][j - axisy];
                } 
    }
  }
}