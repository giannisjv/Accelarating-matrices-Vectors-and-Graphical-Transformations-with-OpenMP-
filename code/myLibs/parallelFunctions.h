
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

/*

void rotation180(int **A, int **B, int N){
int i,j;
int x = N - 1;
int y = N - 1;
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[x][j] = A[i][j];
        }
        x--;
    }
}


void rotation270(int **A, int **B, int N){
  int i,j;
  int x = N - 1;
   for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
          B[x][i] = A[i][j];
             x--;
        }
    x = N - 1;
    }
}
*/