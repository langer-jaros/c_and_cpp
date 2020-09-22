#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
    time_t t;
    printf("Time in seconds from 1970: %li\n", time(&t));
    return 0;
}

