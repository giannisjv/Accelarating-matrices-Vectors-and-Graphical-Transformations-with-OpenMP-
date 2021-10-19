#include <stdio.h>

int  main(void) {
int i;
char *t="#";

for(i=0;i<=100;i++) {
        printf("\b\b\b33[0;31m%%",i);
        usleep(1000);
        }
        return 0;
}
