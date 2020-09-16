/* 
 * File:   main.c
 * Author: Langer Jaroslav
 *
 * Created on 2020 September 11 
 */

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>

#define BASE_DEC 10
// printf("Decimal digits needed for INT_MAX number %d\n", (int) ceil(log10((double) INT_MAX)));
// (int) ((ceil(log10((double) INT_MAX)) + 1) * sizeof(char)) // is better if char is not 1 byte long
#define NUM_DEC_DIGIT_INT_MAX 10

// Returns greatest common divisor
long int gcd(long int a, long int b)
{
    return (a == 0)? b: gcd(b%a, a);
}

// Returns least common multiple
long int lcm(long int a, long int b)
{
    return a*(b/ gcd(a, b));
}

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

/* Script that for two numbers counts the greatest common divisor and the least common multiple.
 * Implementation is based on integer numbers, uses strtoimax, and snprintf for check if the string was read correctly.
 * For implementation with long numbers function strtol would be used.*/
int main(int argc, char** argv)
{
    int a = 0, b = 0;

    if (argc < 3) {
        printf("The operation requires two arguments, %d given.\n", argc - 1); // First argument is the file name
        return EXIT_FAILURE;
    } else if (!str_to_int(&a, argv[1]) || !str_to_int(&b, argv[2])) {
        printf("Input arguments were not understood: arg1=%s, arg2=%s\n", argv[1], argv[2]);
        return EXIT_FAILURE;
    }
    printf("For numbers a=%d, b=%d: gcd=%li, lcm=%li\n", a, b, gcd(a, b), lcm(a, b));
    return EXIT_SUCCESS;
}
