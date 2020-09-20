#include <stdio.h>
#include <stdlib.h>

#define static_array_size(a) (sizeof(a) / sizeof((a)[0]))

void change_num_by_address(int *num, int val)
{
    *num = val;
}

void change_num_by_pointer(int *num_ptr, int val)
{
    *num_ptr = val; // change_num_by_address(num_ptr, val);
}

void change_arr_by_address(int *arr, int val)
{
    *arr = val; // change_num_by_address(arr, val);
}

void change_arr_by_index(int *arr, int idx, int val)
{
    arr[idx] = val; // change_num_by_address(&arr[idx], val);
}

/* 
 * As a code style I prefer to declare variables at the very top of the code
 * however this is not a usefull code, it's an example how to work with pointers
 */
int main(int argc, char** argv)
{
    printf("\nExample of manipulation with variable by its address and by its pointer\n\n");
    int num = 0;
    int *num_ptr;
    num_ptr = &num;
    int value_1 = 11111;
    int value_2 = 88888;

    printf("\nNumber, its value, address, pointer reference, pointer value, pointer address:\n");
    printf("num=%d, &num=%p, *num_ptr=%d, num_ptr=%p, &num_ptr=%p\n\n", num, &num, *num_ptr, num_ptr, &num_ptr);

    printf("Change a value by its address:\n"); // Change a value by its address
    printf("BEFORE: num=%d, &num=%p, value_1=%d\n", num, &num, value_1);
    printf("CALL:   change_num_by_address(&num, value_1)\n");
    change_num_by_address(&num, value_1);
    printf("AFTER:  num=%d, &num=%p, value_1=%d\n\n", num, &num, value_1);

    printf("Change a value by its pointer:\n"); // Change a value by its pointer
    printf("BEFORE: num=%d, &num=%p, *num_ptr=%d, num_ptr=%p, &num_ptr=%p, value_2=%d\n", 
        num, &num, *num_ptr, num_ptr, &num_ptr, value_2);
    printf("CALL:   change_num_by_pointer(num_ptr, value_2)\n");
    change_num_by_pointer(num_ptr, value_2);
    printf("AFTER:  num=%d, &num=%p, *num_ptr=%d, num_ptr=%p, &num_ptr=%p, value_2=%d\n\n", 
        num, &num, *num_ptr, num_ptr, &num_ptr, value_2);

    printf("\nExample of manipulation with array item by its index, and by the array pointer\n\nArray:\n");
    int arr[] = {7, 9, 11, 13, 8, 10, 12, 14};
    int *arr_ptr;
    arr_ptr = arr;
    int index = 3;
    int i;

    for (i = 0; i < static_array_size(arr); i++)
        (i != static_array_size(arr) - 1)? printf("%d, ", arr_ptr[i]): printf("%d\n\n", arr_ptr[i]);

    printf("Array reference, array value, array address, pointer reference, pointer value, pointer address:\n");
    printf("*arr=%d, arr=%p, &arr=%p, *arr_ptr=%d, arr_ptr=%p, &arr_ptr=%p\n\n",
        *arr, arr, &arr, *arr_ptr, arr_ptr, &arr_ptr);

    printf("Change a value of an array item by the item's index:\n"); // change a value of an array item by the ...
    printf("BEFORE: *arr=%d, arr=%p, &arr=%p, index=%d, arr[index]=%d, value_1=%d\n",
        *arr, arr, &arr, index, arr[index], value_1);
    printf("CALL:   change_arr_by_index(arr, index, value_1)\n");
    change_arr_by_index(arr, index, value_1);
    printf("AFTER:  *arr=%d, arr=%p, &arr=%p, index=%d, arr[index]=%d, value_1=%d\n\n",
        *arr, arr, &arr, index, arr[index], value_1);

    printf("Change a value of an array item by the address of the item:\n");// change a value of an array item by the ..
    printf("BEFORE: *arr=%d, arr=%p, &arr=%p, arr[index]=%d, &arr[index]=%p, value_2=%d\n",
        *arr, arr, &arr, arr[index], &arr[index], value_2);
    printf("CALL:   change_arr_by_address(&arr[index], value_2)\n");
    change_arr_by_address(&arr[index], value_2);
    printf("AFTER:  *arr=%d, arr=%p, &arr=%p, arr[index]=%d, &arr[index]=%p, value_2=%d\n\nArray:\n",
        *arr, arr, &arr, arr[index], &arr[index], value_2);

    for (i = 0; i < static_array_size(arr); i++)
        (i != static_array_size(arr) - 1)? printf("%d, ", *arr_ptr++): printf("%d\n\n", *arr_ptr++);

    return EXIT_FAILURE;
}
