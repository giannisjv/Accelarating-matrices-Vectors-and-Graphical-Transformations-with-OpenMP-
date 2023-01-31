

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

void parallel_translate_guided(int **A, int **B, int N, int translationRow, int translationColumn, int threads, int chunk){

     int i, j;
     #pragma omp parallel for collapse(2) schedule(guided, chunk) num_threads(threads)
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
void parallel_rotation90_static(int **A, int **B, int N){
  int i, j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(static) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[j][x - i] = A[i][j];
        }
    }
}

void parallel_rotation180_static(int **A, int **B, int N){
int i,j;
int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(static) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[x - i][x - j] = A[i][j];
        }
    }
}


void parallel_rotation270_static(int **A, int **B, int N){
  int i,j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(static) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[x - j][i] = A[i][j];
        }
    }
}

//===============================
// dynamic function
void parallel_rotation90_dynamic(int **A, int **B, int N){
  int i, j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(dynamic) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[j][x - i] = A[i][j];
        }
    }
}

void parallel_rotation180_dynamic(int **A, int **B, int N){
int i,j;
int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(dynamic) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[x - i][x - j] = A[i][j];
        }
    }
}


void parallel_rotation270_dynamic(int **A, int **B, int N){
  int i,j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(dynamic) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[x - j][i] = A[i][j];
        }
    }
}

//====================================
// guided function
void parallel_rotation90_guided(int **A, int **B, int N){
  int i, j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(guided) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[j][x - i] = A[i][j];
        }
    }
}

void parallel_rotation180_guided(int **A, int **B, int N){
int i,j;
int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(guided) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[x - i][x - j] = A[i][j];
        }
    }
}


void parallel_rotation270_guided(int **A, int **B, int N){
  int i,j;
  int x = N - 1;
  #pragma omp parallel for collapse(2) schedule(guided) num_threads(4)
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[x - j][i] = A[i][j];
        }
    }
}
