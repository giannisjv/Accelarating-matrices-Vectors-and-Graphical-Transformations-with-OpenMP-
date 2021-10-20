#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define N 100000
int main(int *argc, char **argv){
	
	 int Array_Size;
	// timer an clock 
	srand(time(NULL));
	
	int i, j, N;
	int **A;
	int counter = 0; 
	
	
	printf("Insert the size of the array");
	scanf("%d",&N);
	
	//Array_Size = N * sizeof(int);
	
	A = (int **)malloc(N * sizeof(int *)); 
		for(i=0;i<N;i++){
			A[i] = (int *)malloc(N * sizeof(int));
		}
		// Creation of A Array
	
	if(!A){
		printf("The Array is too big\nExiting");
		return -1;
	}
	
	for(i=0;i<N;i++){
		for (j=0;j<N;j++)
		A[i][j] = (j+1) * (i+1);
		}
	
	printf("\n\t\t\t\t A Array\n\n");
		
		for(i=0;i<N;i++){
			printf("\n\n");
			for (j=0;j<N;j++)
		printf("%d \t",A[i][j],counter++);
	}
		printf("\n\nCount(%d)\n\n",counter);
		
			free(A);
			

return 0;
}

