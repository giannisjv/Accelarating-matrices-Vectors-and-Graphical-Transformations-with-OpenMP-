#include <stdio.h>
int main(){

    int j = 0,loop_start = 100000, loop_end = 1000000, loop_step = 100000, i;
    int counter = 0;
    int A[10];

    for(i = loop_start; i <= loop_end; i += loop_step){
        A[j++] = i;
        counter++;
    }
  

    

    for (i = 0; i < counter; i++){
        printf("%d\n",A[i]);
    }
      printf("\ncounter %d\n",counter);
return 0;
}