/* 
 * File:   main.c
 * Author: langer
 *
 * Created on 08 January 2018, 06:53 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_MULTIPLICATION 2;

#define static_array_size(a) (sizeof(a) / sizeof((a)[0]))

int cmp_int(const void *a, const void *b)
{
    if (*(int *) a < *(int *) b)
        return 1;
    if (*(int *) b < *(int *) a)
        return -1;
    return 0;   
}

void realloc_str(char **str, int *str_len)
{
    *str_len *= ARRAY_MULTIPLICATION;
    *str = (char *) realloc(*str, *str_len * sizeof(**str));
}

void array_to_str(char **str, int *arr, int arr_len)
{
    int i, written;
    int str_len = arr_len;
    int index = 0;
    int sep = 1;
    int space = 1;
    int end = 1;

    *str = (char *) malloc(str_len * sizeof(**str));

    for (i = 0; i < arr_len; i++) {
        if (index >= str_len - 1 - 1) // length - '\0'
            realloc_str(str, &str_len);
        
        // TODO when snprintf returns what, how to handle
        written = snprintf(&(*str)[index], str_len - index, "%d", arr[i]);
        if (written < 0) {
            i--;
            realloc_str(str, &str_len);
            continue;
        }
        index += written;
        
        if ((i < arr_len - 1 && index > str_len - space - sep - end)
                || i >= arr_len -1 && index > str_len - end) {
            realloc_str(str, &str_len);
        }

        // TODO change this to string contencation
        if (i < arr_len - 1) {
            (*str)[index++] = ',';
            (*str)[index++] = ' ';
        } else {
            (*str)[index++] = '\0';
        }
    }
}

void print_arr_int(int *arr, int arr_len, char sep, char *space)
{
    int i;
    for (i = 0; i < arr_len; i++)
        (i != arr_len - 1)? printf("%d%c%s", arr[i], sep, space): printf("%d\n", arr[i]);
}

void print_line(int len)
{
    int i;
    for (i = 0; i < len; i++)
        (i != len - 1)? printf("-"): printf("-\n");
}

int main(int argc, char** argv)
{
    int arr[] = {1, 5, 19, 2, 8, 4, 6, 5, 15, 8, 9};
    int arr_len = (int) static_array_size(arr);
    // TODO change sep to sep[] = ", "; delte space, add sep_len
    char *str, sep = ',', space[] = " ";
    int str_len;

    // TODO change sep, space to sep
    print_arr_int(arr, arr_len, sep, space);
    // TODO  add , sep, to input parameters, solve lengths
    array_to_str(&str, arr, arr_len);

    print_line(strlen(str));

    qsort(arr, arr_len, sizeof(int), cmp_int);

    print_arr_int(arr, arr_len, sep, space);
    
    return EXIT_SUCCESS;
}
