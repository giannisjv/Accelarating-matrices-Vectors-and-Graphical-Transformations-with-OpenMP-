// parallel programm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


#define cores 12
#define randomness 22000
//#define N 100000
int main(){
	 int Array_Size, Line_sizes;
	// timer an clock
	srand(time(NULL));

	// timer an clock

	// Variables
	double time_taken = 0 ,start=0, end=0;;
	int i, j, N, M, Multiply_Numb, c, counter = 0;
	// Variables

	// Pointers to use with malloc
	int **A, **B;


	printf("N:  ");
	scanf("%d",&N);

	printf("M:  ");
	scanf("%d",&M);

Multiply_Numb = rand() % randomness;

printf("N= (%d)\tM= (%d)\tRandom Number: (%d)\tcounter(%d)\n",N,M,Multiply_Numb,counter);




	// Initiating Pointers size
	Array_Size = (M * sizeof(int));
	Line_sizes = (N * sizeof(int *));
	// Initiating Pointers size

	// Creation of A Array
	A = (int **)malloc(Line_sizes);
		for(i=0;i<N;i++){
			A[i] = (int* )malloc(Array_Size);
		}
		// Creation of A Array

	if(!A){
		printf("The Array is too big\nExiting");
		return -1;
	}

	B = (int **)malloc(Line_sizes);
		for(i=0;i<N;i++){
			B[i] = (int* )malloc(Array_Size);
		}

		if(!B){
		printf("The Array is too big\nExiting");
		free(A);
		return -1;
	}


	for(i=0;i<N;i++){
	   for(j=0;j<M;j++){
			 A[i][j] = rand() % randomness;
		 }
	 }

	 for(c=1;c<cores;c*=2){

 time_taken = 0;
 start = 0;
 end = 0;

start = omp_get_wtime();
	 #pragma omp parallel for collapse(2) schedule(static) num_threads(c) shared(Multiply_Numb, B, A, N, M ) private(i, j)
		for(i=0;i<N;i++){
 	   for(j=0;j<M;j++){
 			B[i][j] = A[i][j] * Multiply_Numb;
 		 }
 	 }
end = omp_get_wtime();
/*
 printf("\n A");
	 for(i=0;i<N;i++){
		 printf("\n");
 	   for(j=0;j<M;j++){
 			 printf("%d\t",A[i][j]);
 		 }
 	 }

	 printf("\n B");


	 	 for(i=0;i<N;i++){
	 		 printf("\n");
	  	   for(j=0;j<M;j++){
	  			 printf("%d\t",B[i][j]);
	  		 }
	  	 }
*/

			 printf("\n\n");
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(B[i][j] != A[i][j] * Multiply_Numb){
					printf("number: (%d) thesi x: (%d), y: (%d) Expected number: (%d) \n",B[i][j], i,j,A[i][j]*Multiply_Numb );
				}
			}
		}

time_taken = end - start;

printf("\n\nExecution τime of sum: (%5.4f)\nCore(s) used: (%d)\n\n",time_taken,c);

	}



free(A);
free(B);

return 0;
		 }
