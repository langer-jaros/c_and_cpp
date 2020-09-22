#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv)
{
    // psudo random integer, multiple compilations and runs, always the same sequence of numbers
    printf("Psudo random integer %d\n", rand());
    // Do not set the seed is the same as set it to 1
    srand(1);

    printf("Psudo random integer %d\n", rand());

    // Common practice is to set the seed with time
    srand(time(0)); // srand((unsigned) time(&t));
    printf("Psudo random integer %d\n", rand());

    return EXIT_SUCCESS;
}
