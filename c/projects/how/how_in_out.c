#include<stdio.h>

int main(int argc, char** argv)
{
    int i;
    if (scanf("%d", &i) != 1 || i <= 0) {
        printf("Input was not correct.\n");
        return 0;
    } else {
        printf("1\n21\n%d\n142\n", i);
    }
    return 0;
}