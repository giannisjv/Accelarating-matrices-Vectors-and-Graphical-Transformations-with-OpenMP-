#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define cores 8 
#define randomness 1000

//#define N 100000
int main(int *argc, char **argv){
	
	srand(time(NULL)); // time 
	time_t start, end;
	
	int N, *A, *B, *C; 
	
	int  i, j, c;
	
	double time_taken;
	
	// printf("Insert the size of the array %d",N);
	
	printf("Insert the size of the array:\t");
	scanf("%d",&N);
	
	
	
	A = malloc(N * sizeof(int));
	if (A == NULL){
		printf("\nThe array is too big.\nExiting");
	return -1;
	}
	
	B = malloc(N * sizeof(int));
	if (B == NULL){
		printf("\nThe array is too big.\freeing array A\nExiting");
		free(A);
	return -1;
	}
	
	C = malloc(N * sizeof(int));
	if (C == NULL){
		printf("\nThe array is too big.\freeing array A and B!\nExiting");
		free(A);
		free(B);
	return -1;
	}
	
	
	
	
	
	for(i=0;i<N;i++){
		A[i] = rand() % randomness;
	}
		
	/*printf("\n\t\t\t\t A Array\n\n");
		
		for(i=0;i<N;i++){
		printf("%d \t",A[i]);
	}
		printf("\n\n");*/
	
	for(j=0;j<N;j++){
		B[j] = rand() % randomness;
	}

		/*printf("\n\t\t\t\t B Array\n\n");
		
		for(j=0;j<N;j++){
		printf("%d \t",B[j]);
	}*/	
	
	/*printf("\n\n");
	printf("\n\t\t\t C Array \n\n");
	*/
	
	for(c=0;c<=cores;c=c+2){
	
	start = clock();
	#pragma omp parallel for schedule(static) num_threads(c)
	for(i=0;i<N;i++){
		C[i] = A[i] + B[i];
	}
	end = clock();
	
	/*for(i=0;i<N;i++){
		printf("%d \t",C[i]);
	
	}
*/
	time_taken = (end - start);
	time_taken = time_taken/CLOCKS_PER_SEC;
	
	printf("\n\n\nExecution τime of sum: (%6.6f)\nNumber of used cores: (%d)\n\n\n",time_taken,c);
	}
	
	free(A);
	free(B);
	free(C);
return 0;
}
