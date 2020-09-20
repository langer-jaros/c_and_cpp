# C

## MENU

## TODO

[variable scope](https://study.com/academy/lesson/variable-scope-in-c-programming.html#:~:text=In%20programming%2C%20variable%20scope%20denotes,are%20passed%20to%20other%20functions.)

## Install

```sh

# Install valgrind for memory leak checks
sudo apt install valgrind
```

## Basics

```c
main(int argc, char** argv)
{
    return 0;
}
```

## Comments

```c
// Single line comment

/* Single line comment old c */

/*
 * Multiline comment
 * Handy for a file anotation perhaps
 */

/* 
 * File:   main.c
 * Author: Langer Jaroslav
 *
 * Created on 11 September 2020, 12:15
 */
```

## Printing (standard input output)

```c
#include <stdio.h>
```
```c
// Inside a funtion
printf("Printing \"Printing \\n\"\n");
printf("% 3d", invisible_sign_right_adjusted);
printf("\n");
// Convert integer back to string for later check
snprintf(string, max_size_of_string, "%d", integer);
```

[Printf documentation](https://www.cypress.com/file/54441/download#:~:text=Using%20printf%20numbers%20can%20be,right%2Djustified%20with%20leading%20spaces.)

## Compile

```sh
# Compile PATH_TO_CODE.c to executable a.out 
gpp PATH_TO_CODE.c

# Specify the executable output yourself -> code.out
gpp -o code.out PATH_TO_CODE.c

# Prefered way to complie
g++ -Wall -pedantic -Wno-long-long PATH_TO_CODE.c
```

## Run the executable

```sh
# Just run in terminal
./a.out

# Load the standard input form text file
./a.out < 0000_in.txt
```

## Variables

### Integers

```c
int number;
long int long_int;
unsigned int unsigned_int;
print("number %d, long_int %li, unsigned int %u\n", number, long_int, unsigned_int,  character);
```
`g++ test.c; ./a.out`
```out
number 1234567890, long_int 1234567890123456789, negativ -1294967296, unsigned int 3000000000
```

### Floating point numbers

```c
float decimal = 7654321;
double more_precise = 12345678901234567e7;
printf("%f - decimal\n%f - more_precise\n%f - more_precise - decimal\n", decimal, more_precise, more_precise - decimal);
```
`g++ test.c; ./a.out`
```out
7654321.000000 - decimal
123456789012345669025792.000000 - more_precise
123456789012345669025792.000000 - more_precise - decimal
```

[ascii table](http://www.asciitable.com/)

## Casting

```c
char character = 64; // c = '@'
print("(int) character %d, character %c\n", (int) character, character);
```
`g++ test.c; ./a.out`
```out
(int) character 64, character @
```

## Aritmetics, operators precedence, asociativity

```c
// Precedence of operators and thir associativity is beatiful, always use brackets
a = a * b % c; // dunno, just use brackets
```
[operator precedence](https://en.cppreference.com/w/c/language/operator_precedence)


### Inrement pre-increment, decrement

```c
a *= 10; // a = a * 10;
b = a++; // first is b assigned to a, then the a is incremented by one
c = --d; // first is d decremented by one, then is c asigned the d value
```


## Arrays

```c
int array[10];
int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
printf("%lu - number of bytes of the array arr\n", sizeof(arr));
```
`g++ test.c; ./a.out`
```out
40 - number of bytes of the array arr
```

### String

```c
#include <string.h>
```

```c
char str_1[30];
char str_2[] = "Hello world!";
char str_3[] = {'H', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd', '!'}; //missing ending null

long unsigned int str_size = sizeof(str_2); // number of bytes (13)
long unsigned int str_len = strlen(str_2); // number of chars before '\0' (12)
// size_t str_len = strlen(str_2); // needs #include <stdlib.h>

printf("String str_2: %s\n%lu - str_size\n%lu - str_len\n\n", str_2, str_size, str_len);

strncpy(str_1, str_2, sizeof(str_1));
printf("str_1 - %s\nsizeof(str_1) - %lu\nstrlen(str_1) - %lu\n\n", str_1, sizeof(str_1), strlen(str_1));

bool same;
same = strncmp(str_2, str_3, sizeof(str_2)) == 0; // 0 means eaqual, the response may be either positive or negative
printf("str_2: %s, str_3: %s, same: %d\n", str_2, str_3, same);
```
`g++ test.c; ./a.out`
```out
String str_2: Hello world!
13 - str_size
12 - str_len

str_1 - Hello world!
sizeof(str_1) - 30
strlen(str_1) - 12

str_2: Hello world!, str_3: Helloworld!Hello world!, same: 0
```

### Address of a variable

```
&number;
```

### Pointers

```c
int number, arr[100];

int *num_ptr = &number;
int *arr_ptr = arr;

arr_ptr++;
*arr_ptr = 10; // arr_ptr[0] = 10;

printf("Pointer value %p, pointed value %d", num_ptr, *num_ptr);
```

## Conditions

```c
if (condition) {
    stuff();
} else if (condition_2){
    stuff_2();
} else {
    stuff_else();
}
```

## Boolean

```c
#include <stdbool.h>
```
```c
bool a = false;
if (a) {
    wont_happen();
}
```

## Short-Circuiting

```c
bool wont_happen()
{
    printf("This is sad.\n");
    return false;
}

bool fu()
{
    printf("Printing is beautiful!\n");
    return true;
}

int main(int argc, char** argv)
{
    if (fu() || wont_happen()) {
        printf("This is called Short-Circuiting, wont_happen did not happen...\n");
    }
    return EXIT_SUCCESS;
}
```
```g++ c.c; ./a.out```
```out
Printing is beautiful!
This is called Short-Circuiting, wont_happen did not happen...
```

### Ternary condition

```c
(condition)? positive(): negative();

a = (condition)? b: c;
```

## Loops

```c
for (i = 0; i < size; i++) {
    stuff();
}

while (condition) {
    stuff();
}

do {
    stuff();
} while (condition);
```

### Change the loop variable

```
int i;
for (i = 0; i < 4; i++) {
    if (i == 1)
        i++;
    printf("i: %d\n", i);
}
```
`g++ test.c; ./a.out`
```out
i: 0
i: 2
i: 3
```

### Continue

```c
int i;
for (i = 0; i < 4; i++) {
    if (i == 2)
        continue;
    printf("i: %d\n", i);
}
```
`g++ test.c; ./a.out`
```
i: 0
i: 2
i: 3
```

## Functions

```c
int fu(a, *b)
{
    *b = 10;
    return a;
}

// Main
    fu(a, b);
    printf("b = %d", b); # b = 10
```

### Passing values or adressses

If you want to change the value inplace, you must pass an adress.

```c
int fu(int *num)
{
    num++;
}
// Main
    fu(&num);
```
If the value is pointed (array), you can change the value by passing the pointer

```c
int fu(int *num)
{
    num[10] = 10;
}
// Main
    fu(num);
```
However if you want to change the pointer (i.e. reallocate memory) you must pass the adress

```c
int fu(int **ptr)
{

}
// Main
    fu(&ptr);
```

## Input

### Input arguments

```c
int main(int argc, char **argv)
{
    if (argc > 3) { // argc arguments count
        // argv arguments vector, first string is the calling of the executable file itself (path/file)
        printf("arg 0 %s, arg 1 %s, arg 2%s\n", argv[0], argv[1], argv[2]);
    }
}
```

### Standard input

```c
if (scanf("%d %d %d", &s_bob, &s_tom, &delay) !=3 || s_bob <= 0 || s_tom <= 0 || delay < 0) {
    printf("%s\n", m_incorrect);
    return 0;
}
```

## Standard library

```c
#include <stdlib.h>
```
```c
int a;
a = (int) strtol(argv[1], NULL, 0);
printf("a %d\n", a);

size_t str_len = strlen(str_2);

return EXIT_FAILURE;
```

## Dynamic memory

```c
// Alocate memory
a_ptr = (int *) malloc(a_len * sizeof(*a_ptr));

// Reallocate memory
a_len = a_len * 2;
a_ptr = (int *) realloc(a_ptr, a_len * sizeof(*a_ptr));

// Dont forget to also free the memory
free(a_ptr); 
```

### Check for memory leaks

```sh
valgrind --leak-check=full -v ./a.out
```

## Assertions

```c
#include <assert.h>

assert(fu() == 0); // If fu() is not 0, the run is interupted

// Add additional message
assert(false && "message");
```

## Struct

```c
struct Books {
    char title[50];
    char author[50];
};

int main(int argc, char** argv)
{
    struct Books book1;
    strncpy(book1.title, "C Programming", 50);
    printf("book1.title = %s\n", book1.title);
    return 0;
}
```
`g++ test.c; ./a.out`
```out
book1.title = C Programming
```

### Typedef struct

```c
typedef unsigned char BYTE;

typedef struct Books {
    char title[50];
    char author[50];
} Book;

int main(void)
{
    Book book1;
    return 0;
}
```

## Limits

```c
#include <limits.h>

printf("LONG_MAX %li\n", LONG_MAX);
```

## Constants

```c
#define TERMINAL_WIDTH 180 // every TERMINAL_WIDTH is simply substituted with 180
```

```c
const int TERMINAL_WIDTH = 180; // this variable is just constant, can not be changed
// also possible
const int TERM_W = TERMINAL_WIDTH;
```

### Macros

```c
#define static_array_size(a) (sizeof(a) / sizeof((a)[0]))
```

## Math

```c
#include <math.h>
```

```c
// Number of decimal digits of LONG_MAX
printf("Number of decimal digits of LONG_MAX %d\n", (int) ceil(log10((double) LONG_MAX)));
```
`g++ test.c; ./a.out`
```out
Number of decimal digits of LONG_MAX 19
```

```c
// Count number of bits needed to store INT_MAX number
printf("Needed bits for INT_MAX number %d\n", (int) ceil(log((double) INT_MAX)));

const int BITS = 8;
const int BASE_BIN = 2;
double long_max;

/* Check biggest signed long by making 2 to the power of number of bits 
 * (number of bytes * bits per byte) and devide by 2 for negativ numbers -1 for zero
 */
long_max = pow((double) BASE_BIN, (double) sizeof(LONG_MAX)*BITS)/2 - 1;

/* Interesting is, that cast LONG_INT to double changes the number. 
 * Probably because of short mantisa */
printf("%f - (double) LONG_MAX\n", (double) LONG_MAX);
printf("%li - (long int) (double) LONG_MAX\n",(long int) (double) LONG_MAX);
```
`g++ test.c; ./a.out`
```out
9223372036854775808.000000 - (double) LONG_MAX
9223372036854775807 - (long int) (double) LONG_MAX
```

## Int types

```c
#include <inttypes.h>

// Convert string to int type intmax_t (long int)
i = strtoimax(str, end_char, base);

/* Number that is bigger than INT_MAX, but smaller than UINT_MAX 
 * is casted to int taken as negative, no error needs to be careful*/
printf("res d %d\n", (int) strtoimax("2147483648", NULL, 10)); // res d -2147483648
printf("res ld %ld\n", strtoimax("2147483648", NULL, 10)); // res ld 2147483648
```

### Errno

```c
#include <errno.h>

printf("%ld\n", strtoimax("9223372036854775808",&endptr,10));
// Show error message
printf("%s\n", strerror(errno));
```

## Test driven development

```sh
# Write the output to file
./a.out < 0000_in.txt > 0000.txt

# Compare results with expected ones
diff 0000.txt 0000_out.txt
```

## Debug a segfault

```sh
gdb ./a.out
```
```gdb
run
```



