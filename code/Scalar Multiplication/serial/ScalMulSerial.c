/* serial algorithm - Σειριακός Αλγόριθμος
Vidras Ioannis - University of Thessaly - Computer Engineering - 4414002

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../myLibs/colib.h"
#include "../../myLibs/functions.h"

#define min 1
#define max 1000

int main(){
	 int Row_size, Column_size;
	 
	srand(time(NULL));									// seed for random generator using current time
	time_t start, end;

	double time_taken;									// clocking the program
	int i, j, N, M, Multiply_Numb;						// A variety of variables!

	int **A, **B;										// double Pointers to create 2D matrices

		printf("\nN ");
		scanf("%d", &N);
		
		printf("\nM ");
		scanf("%d", &M);

		

	Multiply_Numb = randomGenInteger(min, max);

	Row_size = (M * sizeof(int));						// Initiating Pointers size
	Column_size = (N * sizeof(int *));					// Initiating Pointers size

	
	A = (int **)malloc(Column_size);						// Creation of "A" Matrix
		for(i=0;i<N;i++){
			A[i] = (int* )malloc(Row_size);
	}
		if(!A){											// Is Matrix "A" existing???
			printf("The Array is too big\nExiting");
		return -1;
		}

	B = (int **)malloc(Column_size);						// Creation of "B" Matrix
		for(i=0;i<N;i++){
			B[i] = (int* )malloc(Row_size);
		}
		if(!B){											// Is Matrix "B" Existing?
		printf("The Array is too big\nExiting");
		free(A);										// if Not free "A" from memory
		return -1;
	}

	for(i=0;i<N;i++){
	   for(j=0;j<M;j++){
			 A[i][j] = randomGenInteger(min, max);		// Filling the Matrix A with random numbers (min, max)
		 }
	 }

start=clock();											// Starting the timing
	 for(i=0;i<N;i++){									// first "for" for rows
 	   for(j=0;j<M;j++){								// second "for" for columns
 			B[i][j] = A[i][j] * Multiply_Numb;			// multiply every number of "A" with a number and send it to "B"
 		 }
 	 }
end=clock();											// End of the timing

// printf("\n");
// display_2D_Non_Squered(A, N, M);						// Display "A"
// printf("\n\n\n");
// display_2D_Non_Squered(B, N, M);						// Display "B"

//scalar_matrix_corr(A, B, N, M, Multiply_Numb);

time_taken = (end - start);
time_taken /=CLOCKS_PER_SEC;

printf("\n\n\nExecution τime of sum: (%5.6f)\n\nRandom Number: (%d)\n",time_taken, Multiply_Numb);

return 0;
		 }
