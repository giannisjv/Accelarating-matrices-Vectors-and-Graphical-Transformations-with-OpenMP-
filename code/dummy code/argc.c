#include <stdio.h>
int main(int argc, char const *argv[]) {
int a[10],i;

    printf("You have entered %d arguments\n",argc);


    for (int i = 0; i < argc; ++i)
        printf("%s\n",argv[i] );
printf("\n\n%s\n",argv[2]);
    return 0;
}
