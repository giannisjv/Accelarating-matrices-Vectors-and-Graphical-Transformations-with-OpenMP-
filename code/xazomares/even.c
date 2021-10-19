#include<stdio.h>
#define N 20
int main(){

float num1, det, res;

printf("\nGive the det\t");
scanf("%f",&det);
while(1 == 1){

printf("\nGive the 2\t");
scanf("%f",&num1);

res = num1 / det;
printf("res: %5.2f\n",res);

}
  return 0;
}
