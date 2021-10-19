/* serial program
Programmer Vidras Ioannis 4414002

Η πρόσθεση πινάκων είναι ίσως η πιο απλή πράξη πινάκων,
το μόνο που χρειάζεται είναι οι δύο πίνακες να έχουν ίδιες διαστάσεις
(πχ αν A[n,m] = B [n,m]) και ισχύει Α + Β ή B + A. Η πρόσθεση πινάκων 
έχει ως αποτέλεσμα έναν τρίτο πίνακα ιδίων διαστάσεων με τούς πρώτους
δύο και το κάθε στοιχείο του του τρίτου πίνακα είναι το άθροισμα των 
ιδίων στοιχείων των δύο προηγούμενων πινάκων.  

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define randomness 100000
//#define N 100000
int main(){
	 int Array_Size;
	// timer an clock 
	srand(time(NULL));
	time_t start, end;
	// timer an clock
	
	// Variables 
	double time_taken;
	int i, j, N;
	// Variables
	
	// Pointers to use with malloc
	int **A, **B, **C;
	// Pointers to use with malloc
	
	printf("N:  ");
	scanf("%d",&N);
	
	// Initiating Pointers size
	Array_Size = N * sizeof(int);
	// Initiating Pointers size
	
	// Creation of A Array
	A = (int **)malloc(N * sizeof(int *)); 
		for(i=0;i<N;i++){
			A[i] = (int *)malloc(Array_Size);
		}
		// Creation of A Array
	
	if(!A){
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
	
	// filling the array A with random numbers
	for(i=0;i<N;i++){
		for (j=0;j<N;j++)
		A[i][j] = rand() % randomness;
	}
	// filling the array A with random numbers

		/* printf("\n\t\t\t\t A Array\n\n");
		
		for(i=0;i<N;i++){
			printf("\n");
			for (j=0;j<N;j++)
		printf("%d \t",A[i][j]);
	}
		printf("\n\n");
		
		*/
		
	
	for(i=0;i<N;i++){
		for (j=0;j<N;j++)
		B[i][j] = rand() % randomness;
	}
		/*
		printf("\n\t\t\t\t B Array\n\n");
		
		for(i=0;i<N;i++){
			printf("\n");
			for (j=0;j<N;j++)
		printf("%d \t",B[i][j]);
	}	
	
	printf("\n\n");
	printf("\n\t\t\t C Array \n\n");
	*/
	start = clock();
	for(i=0;i<N;i++){
		for (j=0;j<N;j++)
		C[i][j] = A[i][j] + B[i][j];
	}
	end = clock();
	/*
	for(i=0;i<N;i++){
		printf("\n");
			for (j=0;j<N;j++)
		printf("%d \t",C[i][j]);
	}
		*/
	
	time_taken = (end-start);
	time_taken /= CLOCKS_PER_SEC;
	printf("\n\n\nExecution τime of sum: %5.6f\n\n",time_taken);
	
	/*C[3][4] = 100;*/ 
	
	for(i=0;i<N;i++){
	   for(j=0;j<N;j++){
	   	if(C[i][j] != A[i][j] + B[i][j])
	   	printf("\nΛάθος σημέιο με τιμη: %d στην θέση x: %d y: %d πραγματική τιμή: %d \n\n",C[i][j],i,j,A[i][j] + B[i][j]);
	   	}
	   }
		
		free(A);
		free(B);
		free(C);

return 0;
}
