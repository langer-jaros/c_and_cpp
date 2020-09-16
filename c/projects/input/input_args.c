/* 
 * File:   main.c
 * Author: Langer Jaroslav
 *
 * Created on 2020 September 11 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>

#define BASE_DEC 10
// printf("Decimal digits needed for INT_MAX number %d\n", (int) ceil(log10((double) INT_MAX)));
#define NUM_DEC_DIGIT_INT_MAX 10

// Removes all leading zeros by moving the pointer (minus sign treated)
void remove_leading_zeros(char **str)
{
    char sign;
    if ((*str)[0] == '-' || (*str)[0] == '+')
        sign = (*str)++[0];
    while (**str == '0')
        (*str)++;
    if (sign == '-')
        *(--(*str)) = sign;
}

// Converts string to integer, not time effective, should be safe
bool str_to_int(int *i, char *str)
{
    int string_size_int_max = NUM_DEC_DIGIT_INT_MAX + 1 + 1; // Number of decimal digits + sign + ending null
    char check[string_size_int_max]; // Number of decimal digits + 1 for ending null

    remove_leading_zeros(&str); // Remove leading zeros, sign at beginning treated 

    *i = strtoimax(str, NULL, BASE_DEC); // Convert string to integer
    snprintf(check, string_size_int_max, "%d", *i); // Convert integer back to string for later check
    
    if (((intmax_t) *i > INT_MAX && str[0] != '-') // If number is bigger than INT_MAX (negative) but minus sign not given
            || errno == ERANGE                     // The number overflew the range of int (i.e. bigger than uint)
            || strncmp(str, check, string_size_int_max) != 0) // If the string representation differ
        return false;
    return true;
}

// TODO string to long
bool str_to_long(long *l, char *str)
{
    // *l = strtol(str, NULL, 0);
    return false;
}

int main(int argc, char** argv)
{
    int i;
    for (i = 0; i < argc; i++)
        printf("argument %d = %s\n", i, argv[i]);
    printf("\n");

    // Convert arguments to ints
    int a = 0, b = 0;
    if (argc < 3) {
        printf("The operation requires two arguments, %d given.\n", argc - 1); // First argument is the file name
        return EXIT_FAILURE;
    } else if (!str_to_int(&a, argv[1]) || !str_to_int(&b, argv[2])) {
        printf("Input arguments were not understood: arg1=%s, arg2=%s\n", argv[1], argv[2]);
        return EXIT_FAILURE;
    }
    printf("From string %s read %d, from string %s read %d\n", argv[1], a, argv[2], b);

    // TODO Convert arguments to long ints

    return EXIT_SUCCESS;
}
