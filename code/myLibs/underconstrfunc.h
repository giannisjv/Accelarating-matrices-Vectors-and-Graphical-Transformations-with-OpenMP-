
int Uptriangle(int A[size][size], int size){
int ratio, B[size][size];
int i, j, k;

for(i=0; i<size; i++){
  if(A[i][i] == 0){
     printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
     printf("\nThe main diagonal has to be any number except 0 zero means Mathemical Error\n" );
     printf("\nJust try again giving no 0 at the main diagonal\n" );
     return -1;
  }

  for(j=i+1; j<size; j++){
    ratio = A[j][i] / A[i][i];
     //printf("i = (%2d), j = (%2d), ratio = (%2.2f)\n",i, j, ratio );
     for(k=0; k<size; k++){
        B[j][k] -= ratio * A[i][k];
     }
  }
}
return B[size][size];

};


void display(float A, int N) {

  for (int i = 0; i < N; i++) {
    printf("\n");
    for (int j = 0; j < N; j++) {
      printf("\t%d",A[i][j] );
    }
  }
  printf("\n\n-----------------------------\n");
  printf("End of display function\n");
};

