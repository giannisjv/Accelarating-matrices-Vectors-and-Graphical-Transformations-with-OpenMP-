#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define N 100000
int main(int *argc, char **argv){
	
	srand(time(NULL)); // time 
	time_t start, end;
	
	int N, *A, *B, *C; 
	
	int  i, j;
	
	double time_taken;
	
	// printf("Insert the size of the array %d",N);
	
	printf("Insert the size of the array");
	scanf("%d",&N);
	
	
	
	A = malloc(N * sizeof(int));
	if (A == NULL){
		printf("\nThe array is too big.\nExiting");
	}
	
	B = malloc(N * sizeof(int));
	if (B == NULL){
		printf("\nThe array is too big.\freeing array A\nExiting");
		free(A);
	}
	
	C = malloc(N * sizeof(int));
	if (C == NULL){
		printf("\nThe array is too big.\freeing array A and B!\nExiting");
		free(A);
		free(B);
	}
	
	
	
	
	
	for(i=0;i<N;i++){
		A[i] = rand() % 20;
	}
		
	printf("\n\t\t\t\t A Array\n\n");
		
		for(i=0;i<N;i++){
		printf("%d \t",A[i]);
	}
		printf("\n\n");
	
	for(j=0;j<N;j++){
		B[j] = rand() % 20;
	}

		printf("\n\t\t\t\t B Array\n\n");
		
		for(j=0;j<N;j++){
		printf("%d \t",B[j]);
	}	
	
	printf("\n\n");
	printf("\n\t\t\t C Array \n\n");
	
	start = clock();
	for(i=0;i<N;i++){
		C[i] = A[i] + B[i];
	}
	end = clock();
	
	for(i=0;i<N;i++){
		printf("%d \t",C[i]);
	}

	time_taken = (end - start);
	time_taken = time_taken/CLOCKS_PER_SEC;
	
	printf("\n\n\nExecution τime of sum: %.6f\n\n",time_taken);
		
	free(A);
	free(B);
	free(C);
return 0;
}

