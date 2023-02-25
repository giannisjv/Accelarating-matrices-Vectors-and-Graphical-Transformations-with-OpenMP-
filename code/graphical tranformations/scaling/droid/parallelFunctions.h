

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

void scaling_Static(int **temp, int ** temp2, int N, int scalingRow, int scalingColumn, int chunk){
   #pragma omp for collapse(2) schedule(static, chunk)
   for (int i = 0; i < N * scalingRow; i++){
        for (int j = 0; j < N * scalingColumn; j++){
            if(i < N && j < N){
            temp2[i][j] = temp[i][j];
            }else
            temp2[i][j] = 1;
        }
    }
}

void scaling_translate_Static(int **A, int **B, int N, int axisx, int axisy, int scalingRow, int scalingColumn, int chunk){
      #pragma omp for collapse(2) schedule(static, chunk)
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