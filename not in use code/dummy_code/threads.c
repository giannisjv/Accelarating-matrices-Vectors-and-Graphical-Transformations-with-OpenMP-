#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    int threads;
    threads = omp_get_max_threads();
    printf("\n%d\n", threads);
    return 0;
}
