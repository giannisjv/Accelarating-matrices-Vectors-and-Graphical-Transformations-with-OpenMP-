
void parallel_translate_static(int **A, int **B, int N, int translationRow, int translationColumn, int threads){

     int i, j;
     #pragma omp parallel for collapse(2) schedule(static) num_threads(threads)
     for ( i = 0; i < N + translationRow; i++){
        for (j = 0; j < N +  translationColumn; j++){
            if(i >= translationRow && j >= translationColumn){
                B[i][j] = A[i - translationRow][j - translationColumn];
            }else
            B[i][j] = 0;
    }
  }
}

