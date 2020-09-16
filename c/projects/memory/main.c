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

#define BASIC_MULTIPLIER 10
#define ARRAY_MULTIPLIER 2
#define SCREEN_WIDTH 180

#define static_array_size(a) (sizeof(a) / sizeof((a)[0]))

void realloc_str(char **str, int *len)
{
    *len *= ARRAY_MULTIPLIER;
    *str = (char *) realloc(*str, *len * sizeof(**str));
}

void realloc_int(int **arr, int *len)
{
    *len *= ARRAY_MULTIPLIER;
    *arr = (int *) realloc(*arr, *len * sizeof(**arr));
}

void print_line(int len)
{
    int i;
    for (i = 0; i < len; i++)
        (i != len - 1)? printf("-"): printf("-\n");
}

int main(int argc, char** argv)
{
    int arr[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60};
    int arr_len = static_array_size(arr);
    
    // Multiply the array size by BASIC_MULTIPLIER
    int *a_ptr;
    int a_len = arr_len;
    int arr_len_final = arr_len * BASIC_MULTIPLIER;

    a_ptr = (int *) malloc(a_len * sizeof(*a_ptr));
    
    int i;
    for (i = 0; i < arr_len_final; i++) {
        if (i == a_len)
            realloc_int(&a_ptr, &a_len);
        a_ptr[i] = arr[i % arr_len];
    }

    // Print multiplied array
    int num_per_line = SCREEN_WIDTH/3;
    for (i = 0; i < arr_len_final; i++)
        ((i % num_per_line != num_per_line - 1) && i != arr_len_final - 1)? printf("%d ", a_ptr[i]): printf("%d\n", a_ptr[i]);

    print_line(SCREEN_WIDTH);

    // Multiply array size by BASIC_MULTIPLIER and cast the integers to characters
    int str_len_final = arr_len * BASIC_MULTIPLIER;
    char *str;
    int str_len = arr_len;
    int index = 0;
    str = (char *) malloc(str_len * sizeof(*str));

    for (i = 0; i < str_len_final; i++) {
        if (index == str_len - 1)
            realloc_str(&str, &str_len);
        str[index++] = (char) arr[i % arr_len];
        if (i == str_len_final - 1)
            str[index++] = '\0';
    }

    // Print the string by characters
    int char_per_line = SCREEN_WIDTH/2;
    for (i = 0; i <= strlen(str); i++)
        ((i % char_per_line != char_per_line - 1) && i != strlen(str))? printf("%c ", str[i]): printf("%c\n", str[i]);

    free(a_ptr);
    free(str);

    return EXIT_SUCCESS;
}
