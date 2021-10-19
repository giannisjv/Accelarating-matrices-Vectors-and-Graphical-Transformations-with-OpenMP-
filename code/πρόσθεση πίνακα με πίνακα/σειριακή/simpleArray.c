#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
int main(){
	
	srand(time(NULL));
	time_t start, end;
	
	int A[N], B[N], C[N], i, j;
	
	double time_taken;
	
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
	
	time_taken = ((end-start)/CLOCKS_PER_SEC);
	
	printf("\n\n\nExecution τime of sum: %.12f\n\n",time_taken);
		

return 0;
}
