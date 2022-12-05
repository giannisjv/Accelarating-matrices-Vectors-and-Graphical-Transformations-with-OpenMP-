/* Ανάστροφος πίνακας
   Vidras Ioannis
   4414002
   Parallel of transponse algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../myLibs/functions.h"  					// importing my libs
#include "../myLibs/colib.h"

#define cores 8
#define min 1
#define max 1000

int main(){
	 int Row_size, Column_size;
	 
	srand(time(NULL));									// seed for random generator using current time

	double start = 0.0, end = 0.0; 
    double time_taken = 0.0;	                        // Start and end time

    double staticSt = 0.0, staticEn = 0.0;
    double time_takenSt = 0.0;
                              // variable to mesure the time algorith took to run 
    double dynamicSt = 0.0, dynamicEn = 0.0;
    double time_takedy = 0.0;
    
    double guidedSt = 0.0, guidedEn = 0.0;
    double time_takengu = 0.0;	
    		
	int i, j, N, M, c;						// A variety of variables!
	int chunk;

	int **A, **B;										// double Pointers to create 2D matrices

		printf("\nN ,M  ");
		scanf("%d", &N);
			M = N;

	Row_size = (M * sizeof(int));							// Initiating Pointers size
	Column_size = (N * sizeof(int *));						// Initiating Pointers size

	A = (int **)malloc(Column_size);						// Creation of "A" Matrix
		for(i=0;i<N;i++){
			A[i] = (int* )malloc(Row_size);
	}
		if(!A){												// Is Matrix "A" existing???
			printf("The Array is too big\nExiting");
		return -1;
		}

	B = (int **)malloc(Column_size);						// Creation of "B" Matrix
		for(i=0;i<N;i++){
			B[i] = (int* )malloc(Row_size);
		}
		if(!B){												// Is Matrix "B" Existing?
		printf("The Array is too big\nExiting");
		free(A);											// if Not free "A" from memory
		return -1;
	}


	for(i=0;i<N;i++){
	   for(j=0;j<M;j++){
			 A[i][j] = randomGenInteger(min, max);    // Filling the A matrix the B will take A's values
		 }
	 }


	printf("\n\t\tSerial\t\tStatic\t\tdynamic\t\tguided  \tchunk\t N\tCores");
	
  // for ( chunk = 1; chunk < 10; chunk++){
    //        printf("\n");
          c = 8;
      staticSt = omp_get_wtime();
	  #pragma omp parallel for collapse(2) num_threads((c)) schedule(static)
				for(i=0;i<N;i++){									        // first "for" for rows
 	    			for(j=0;j<M;j++){							        	// second "for" for columns
 				B[i][j] = A[j][i]; 			// multiply every number of "A" with a number and send it to "B"
 		 	}
 	 	}
      staticEn = omp_get_wtime();
            
      dynamicSt = omp_get_wtime();
	  #pragma omp parallel for collapse(2) num_threads(c) schedule(dynamic)
				for(i=0;i<N;i++){									        // first "for" for rows
 	    			for(j=0;j<M;j++){							        	// second "for" for columns
 			 B[i][j] = A[j][i];             			// multiply every number of "A" with a number and send it to "B"
 		 }
 	 }
      dynamicEn = omp_get_wtime();
            
      guidedSt = omp_get_wtime();
      #pragma omp parallel for collapse(2) num_threads(c) schedule(guided)
				for(i=0;i<N;i++){									        // first "for" for rows
 	    			for(j=0;j<M;j++){							        	// second "for" for columns
 				 B[i][j] = A[j][i];		     // for every B[i][j] Is Equal to A[j][i]
 		 }
 	 }
      guidedEn = omp_get_wtime();
/*
B[1][2] = 5;
transpose(A, B, N);
display_2D_Non_Squered(A, N, M);
printf("\n");
display_2D_Non_Squered(B, N, M);
*/



if(c == 1){
	time_taken = (end-start);
    time_takenSt = time_takedy = time_takengu = 0.0;
    } else{
        time_taken = 0.0;
    time_takenSt = (staticEn - staticSt);
    time_takedy = (dynamicEn - dynamicSt);
    time_takengu = (guidedEn - guidedSt);
    }
	printf("\n\t%15.6f, %15.6f,%15.6f, %15.6f, \t%d, \t  %d",time_taken, time_takenSt, time_takedy, time_takengu, N, c);
    //  }

	//}
printf("\n");
free(A);
free(B);

return 0;
		 }
  
  
  
  