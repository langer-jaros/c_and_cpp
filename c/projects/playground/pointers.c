#include <stdio.h>
#include <stdlib.h>

#define TERMINAL_WIDTH 180
#define static_array_size(a) (sizeof(a) / sizeof((a)[0]))

void change_arr_by_address(int *arr, int val)
{
    *arr = val;
}

void change_arr_by_index(int *arr, int idx, int val)
{
    arr[idx] = val;
}

void change_num_by_pointer(int *num_ptr, int val)
{
    *num_ptr = val;
}

void change_num_by_address(int *num, int val)
{
    change_num_by_pointer(num, val);
}

void print_line(int len)
{
    int i;
    for (i = 0; i < len; i++)
        (i != len - 1)? printf("-"): printf("-\n");
}

int main(int argc, char** argv)
{
    int num = 0;
    int *num_ptr;
    num_ptr = &num;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int *arr_ptr;
    arr_ptr = arr;
    int value_1 = 18;
    int value_2 = 36;
    int index = 8;

    printf("num %d, &num %p, *num_ptr %d, num_ptr %p, &num_ptr %p\n", num, &num, *num_ptr, num_ptr, &num_ptr);
    printf("*arr %d, arr %p, &arr %p, *arr_ptr %d, arr_ptr %p, &arr_ptr %p\n\n", *arr, arr, &arr, *arr_ptr, arr_ptr, &arr_ptr);

    print_line(TERMINAL_WIDTH);

    printf("num %d, &num %p\n", num, &num);
    printf("change_num_by_address(&num=%p, value_1=%d)\n", &num, value_1);
    change_num_by_address(&num, value_1);
    printf("num %d, &num %p\n\n", num, &num);

    printf("num %d, &num %p, *num_ptr %d, num_ptr %p, &num_ptr %p\n", num, &num, *num_ptr, num_ptr, &num_ptr);
    printf("change_num_by_pointer(num_ptr=%p, value_2=%d)\n", num_ptr, value_2);
    change_num_by_pointer(num_ptr, value_2);
    printf("num %d, &num %p, *num_ptr %d, num_ptr %p, &num_ptr %p\n\n", num, &num, *num_ptr, num_ptr, &num_ptr);

    print_line(TERMINAL_WIDTH);

    printf("*arr %d, arr %p, &arr %p\n", *arr, arr, &arr);
    printf("change_arr_by_index(arr=%p, index=%d, value_1=%d)\n", arr, index, value_1);
    change_arr_by_index(arr, index, value_1);
    printf("*arr %d, arr %p, &arr %p\n\n", *arr, arr, &arr);

    printf("*arr %d, arr %p, &arr %p, arr[index] %d, &arr[index] %p\n", *arr, arr, &arr, arr[index], &arr[index]);
    printf("change_arr_by_address(&arr[index]=%p, value_2%d)\n", &arr[index], value_2);
    change_arr_by_address(&arr[index], value_2);
    printf("*arr %d, arr %p, &arr %p, arr[index] %d, &arr[index] %p\n\n", *arr, arr, &arr, arr[index], &arr[index]);

    print_line(TERMINAL_WIDTH);

    int i;
    for (i = 0; i < static_array_size(arr); i++)
        (i != static_array_size(arr) - 1)? printf("%d, ", *arr_ptr++): printf("%d\n", *arr_ptr++);

    return EXIT_FAILURE;
}
