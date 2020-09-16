/* 
 * File:   main.c
 * Author: Langer Jaroslav
 *
 * Created on 2020 September 11 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


int main(int argc, char** argv)
{
    int a = 0, b = 0;
    char str_1[] = {'H', 'i', '\0'};
    char str_2[] = {'H', 'i'}; // Not a string
    char str_3[] = "Hi";

    printf("str_1 %s, str_2 %s, strncmp(str_1, str_2, sizeof(str_1)) %d\n", str_1, str_2, strncmp(str_1, str_2, sizeof(str_1)));
    printf("str_1 %s, str_3 %s, strncmp(str_1, str_3, sizeof(str_1)) %d\n", str_1, str_3, strncmp(str_1, str_3, sizeof(str_1)));
    printf("str_2 %s, str_3 %s, strncmp(str_2, str_3, sizeof(str_3)) %d\n", str_2, str_3, strncmp(str_2, str_3, sizeof(str_3)));

    printf("\nSize of str_1: %s = %lu\n", str_1, sizeof(str_1));
    printf("Str length of str_1: %s = %lu\n", str_1, strlen(str_1));

    return EXIT_SUCCESS;
}
