/* serial program
Programmer Vidras Ioannis 4414002
Το άθροισμα πινάκων αποτελείται από 2 πίνακες και δίνουν σαν αποτέλεσμα έναν τρίτο πίνακα
με στοιχεία τόσα όσα το οι γραμμές του πρώτου και οι    

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define randomness 100000
//#define N 100000
int main(){
	 int Array_Size, Line_sizes;
	// timer an clock
	srand(time(NULL));
	time_t start, end;
	// timer an clock

	// Variables
	double time_taken;
	int i, j, N, M, Multiply_Numb;
	// Variables

	// Pointers to use with malloc
	int **A, **B;
	// Pointers to use with malloc

	printf("N:  ");
	scanf("%d",&N);

	printf("M:  ");
	scanf("%d",&M);

 	//printf("Give the number to Multiply the array: ");
 	//scanf("%d",&Multiply_Numb);

	Multiply_Numb = 17865;

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
start=clock();
	 for(i=0;i<N;i++){
 	   for(j=0;j<M;j++){
 			B[i][j] = A[i][j] * Multiply_Numb;
 		 }
 	 }
end=clock();

/*
	 for(i=0;i<N;i++){
		 printf("\n");
 	   for(j=0;j<M;j++){
 			 printf("%d\t",A[i][j]);
 		 }
 	 }
*/
	 printf("\n\n\n");

	 for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(B[i][j] != A[i][j] * Multiply_Numb){
					printf("number: (%d) thesi x: (%d), y: (%d) Expected number: (%d) \n",B[i][j], i,j,A[i][j]*Multiply_Numb );
				}
			}
		}
time_taken = end - start;

printf("\n\n\nExecution τime of sum: (%5.6f)\n\nRandom Number: (%d)\n",time_taken, Multiply_Numb);

return 0;
		 }
