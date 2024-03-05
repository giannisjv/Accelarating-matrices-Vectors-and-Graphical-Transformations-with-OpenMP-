#include <stdio.h>
int main()
{
    int b = 99;
    printf("char (%lu)\n", sizeof(char));
    printf("int (%lu)\n", sizeof(int));
    printf("float (%lu)\n", sizeof(float));
    printf("double (%lu)", sizeof(double));
    printf("\n");
    int  a = 2147483650;
    printf("\n%d\n", a);
    printf("%d", b/2);
    return 0;
}