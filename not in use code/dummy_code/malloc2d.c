#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../code/myLibs/functions.h"
#include "../../code/myLibs/randomizers.h"
#include "../../code/myLibs/displays.h"

//#define N 100000
int main(int *argc, char **argv){
	
	 int Array_Size;
	// timer an clock 
	srand(time(NULL));
	
	int i, j, N;
	float **A;
	int counter = 0; 
	
	
	printf("Insert the size of the array");
	scanf("%d",&N);
	
	A = (float **)malloc(N * sizeof(float *)); 
		for(i=0; i<N; i++){
			A[i] = (float *)malloc(N * sizeof(float));
		}
		// Creation of A Array
	
	if(!A){
		printf("The Array is too big\nExiting");
		return -1;
	}
	
	randomFloat(A, N, 1, 5);
	
	printf("\n\t\t\t\t A Array\n\n");

	 for ( i = 0; i < N; i++) {
        if (A[i][i] == 0) {      // if any number of main diagonal is zero - return -1
			   printf("\n\nOne element of the main diagonal is 0 (zero!) You can't procced!\n\n");
         printf("The element is x=(%d), y=(%d), value=(%f)\n",i, i, A[i][i] );
			   return -1;
        }
	 }
		
	display_2Dfloat(A, N, N);
		
			free(A);
			

return 0;
}

