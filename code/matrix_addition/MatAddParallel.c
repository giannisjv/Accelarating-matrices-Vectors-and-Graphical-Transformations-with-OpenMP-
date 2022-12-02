/* Parallel alogorithm -- Παράλληλος Αλγόριθμος
Vidras Ioannis - University of Thessaly - Computer Enginnering - 4414002

Η πρόσθεση πινάκων είναι ίσως η πιο απλή πράξη πινάκων,
το μόνο που χρειάζεται είναι οι δύο πίνακες να έχουν ίδιες διαστάσεις
(πχ αν A[n,m] = B [n,m]) και ισχύει Α + Β ή B + A. Η πρόσθεση πινάκων 
έχει ως αποτέλεσμα έναν τρίτο πίνακα ιδίων διαστάσεων με τούς πρώτους
δύο και το κάθε στοιχείο του του τρίτου πίνακα είναι το άθροισμα των 
ιδίων στοιχείων των δύο προηγούμενων πινάκων.  

Matrix Addition is one of the most easy to-do in linear algebra
Two Matrices has to be equal, to have same number of rows and columns.
if A + B = B + A... 
The matrix addition as a result has a Matrix EQUAL to the others.  

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/functions.h"
#include "../myLibs/colib.h"

#define min 1 					// Using min and max to limit the random numbers from 1 to 1000 
#define max 1000
#define loopMin  1000
#define loopMax  10000
#define loopstep 1000
#define cores 8

int main(){

	 int Array_Size; 								// Variable to idicate the array size
	 srand(time(NULL)); 								// Using srand time(NULL) seed because we want truly random numbers base on time! 
	
	double start = 0.0, end = 0.0; 					// Start and end time
	double time_taken = 0.0;						// variable to mesure the time algorith took to run 
	int i, j, c, N;									// other variables 
	
	for(int loop = loopMin; loop <= loopMax; loop+=loopstep){

	N = loop;


	int **A, **B, **C;								// allocating 3 double pointer variables
	/*
	printf("N:  ");									// asking from the user N
	scanf("%d",&N);
	*/
	
	Array_Size = N * sizeof(int); 					// Array size is N multiplied by sizeof(int)  - 4Bytes 
	
	A = (int **)malloc(N * sizeof(int *)); 			// Initialising the first Matrix with malloc - Same with the other two matrices bellow
		for(i=0;i<N;i++){
			A[i] = (int *)malloc(Array_Size);		
		}


	if(!A){											// if the matrix is too big Exiting - Same with the other two matrices bellow
		printf("The Array is too big\nExiting");
		return -1;
	}
	
	B = (int **)malloc(N * sizeof(int *));
		for(i=0;i<N;i++){
			B[i] = (int *)malloc(Array_Size);
		}
		
		if(!B){
		printf("The Array is too big\nExiting");
		free(A);
		return -1;
	}
	
	C = (int **)malloc(N * sizeof(int *));
		for(i=0;i<N;i++){
			C[i] = (int *)malloc(Array_Size);
		}
		
		if(!C){
		printf("The Array is too big\nExiting");
		return -1;
	free(B);
	free(C);
	}
	
	for(i=0;i<N;i++){								// filling the array A with random numbers 
		for (j=0;j<N;j++)
		A[i][j] = randomGenInteger(min, max); 		// using randomGenInteger function with limit to min max which defined above 
	}
	/*
		printf("\n\t\t\t\t A Array\n\n");
		
		display2D(A, N);							// Function to display Matrix A
		printf("\n\n");
		
		*/
	
	for(i=0;i<N;i++){
		for (j=0;j<N;j++)
		B[i][j] = randomGenInteger(min, max);
	}
		/*
		printf("\n\t\t\t\t B Array\n\n");

		display2D(B, N);							// Function to display Matrix B
	
	printf("\n\n");
	printf("\n\t\t\t\t C Array \n\n");
*/

	for(c=1; c<=cores; c *= 2){
	start = omp_get_wtime();
	#pragma omp parallel num_threads(c)
	{
			#pragma omp master
			if (c == 1){
				for(i=0;i<N;i++){
					for (j=0;j<N;j++)
				C[i][j] = A[i][j] + B[i][j];
		}
		}	else{
			#pragma omp parallel for collapse(2) schedule(static) num_threads(c) private(i,j) 
				for(i=0;i<N;i++){
					for (j=0;j<N;j++)
				C[i][j] = A[i][j] + B[i][j];
			}

		}
	}
	end = omp_get_wtime();
	// display2D(C, N);								// Function to display Matrix C
	
	time_taken = (end-start);						// clock is counting by subtracting end from start
	printf("\n"YEL" %5.6f, "RESET""RED"%d"RESET, time_taken, N);
	printf(" ,"MAG"%d\n"RESET,c);
	
}
	
	




/*

	for(i=0;i<N;i++){
	   for(j=0;j<N;j++){
	   	if(C[i][j] != A[i][j] + B[i][j])
	   	printf("\nΛάθος σημέιο με τιμη: %d στην θέση x: %d y: %d πραγματική τιμή: %d \n\n",C[i][j],i,j,A[i][j] + B[i][j]);
	   	}
	   }
	   */
		free(A);
		free(B);
		free(C);
	}


return 0;
}