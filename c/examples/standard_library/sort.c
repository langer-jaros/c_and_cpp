/*
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define static_array_size(a) (sizeof(a) / sizeof((a)[0]))

int double_cmp (const void * a, const void * b) 
{
    return ( *(double*)a - *(double*)b );
}

void print_arr_double(double *arr, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        (i < len -1)? printf("%f, ", arr[i]): printf("%f\n", arr[i]);
    }
}

int main(int argc, char** argv)
{
    double arr[] = {1.5, 67, 4.6, -132.7, 0.00006, 500000.25, -362};
    int arr_len = static_array_size(arr);

    print_arr_double(arr, arr_len);
    
    qsort(arr, arr_len, sizeof(arr[0]), double_cmp);
    
    print_arr_double(arr, arr_len);

    return EXIT_SUCCESS;
}
