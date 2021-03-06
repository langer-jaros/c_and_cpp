# C

Programming language by Dennis Ritchie and Kenneth Thompson, a successor of the language B.
It has been standardized by the ANSI since 1989 (ANSI C) and by the ISO since 1990.

## Good sources

[devdocs - C Programming Language](https://devdocs.io/c/)

## Content

- [Good sources](#good-sources)
- [Content](#content)
- [Install](#install)
- [Basics](#basics)
  - [code hello_world.c](#code-hello_worldc)
- [Compile](#compile)
- [Run the executable file](#run-the-executable-file)
  - [Transfer standard input/output to/from file](#transfer-standard-inputoutput-tofrom-file)
- [Comments](#comments)
- [Main function](#main-function)
- [Printing (standard input output library)](#printing-standard-input-output-library)
- [Variables](#variables)
  - [Integers](#integers)
  - [Floating point numbers](#floating-point-numbers)
  - [Formated print](#formated-print)
- [Casting](#casting)
- [Aritmetics, operators precedence, asociativity](#aritmetics-operators-precedence-asociativity)
  - [Precedence 2](#precedence-2)
  - [Inrement pre-increment, decrement](#inrement-pre-increment-decrement)
- [Arrays](#arrays)
  - [String](#string)
  - [Address of a variable](#address-of-a-variable)
  - [Pointers](#pointers)
- [Conditions](#conditions)
  - [If](#if)
  - [Ternary condition](#ternary-condition)
  - [Switch](#switch)
- [Boolean](#boolean)
- [Short-Circuiting](#short-circuiting)
- [Loops](#loops)
  - [Change the loop variable](#change-the-loop-variable)
  - [Continue](#continue)
- [Functions](#functions)
  - [Passing values or adressses](#passing-values-or-adressses)
- [Struct](#struct)
  - [Typedef struct](#typedef-struct)
- [Constants](#constants)
  - [Macros](#macros)
- [Input](#input)
  - [Input arguments](#input-arguments)
- [Libraries](#libraries)
  - [Standard input outpu (stdio)](#standard-input-outpu-stdio)
  - [Standard input](#standard-input)
- [Time](#time)
- [Standard library](#standard-library)
  - [String features](#string-features)
  - [Constants](#constants-1)
  - [Sorting](#sorting)
  - [Randomness](#randomness)
  - [Dynamic memory](#dynamic-memory)
  - [Check for memory leaks](#check-for-memory-leaks)
- [Assertions](#assertions)
- [Limits](#limits)
- [Math](#math)
- [Int types](#int-types)
  - [Errno](#errno)
- [Test driven development](#test-driven-development)
- [Debug a segfault](#debug-a-segfault)
- [Object Orientated Programming](#object-orientated-programming)
- [TODO](#todo)

## Install

```sh

# Install valgrind for memory leak checks
sudo apt install valgrind
```

## Basics

### code hello_world.c

Basic c program to go through.

```c
#include<stdio.h>

int main(int argc, char** argv)
{
    printf("Hello world!\n");
    return 0;
}
```

## Compile

```sh
# Compile PATH_TO_CODE.c to executable a.out 
gcc path/hello_world.c

# Specify the executable output yourself -> code.out
gcc path/to/main.c -o main.out

# Prefered way to complie
g++ -Wall -pedantic -Wno-long-long PATH_TO_CODE.c
```

## Run the executable file

```sh
# Just run in terminal
./hello_world.out
```
```out
Hello world!
```

### Transfer standard input/output to/from file

```sh
# Load the standard input from a text file
./a.out < 0000_in.txt

# Pipe the output to another file
./a.out > 0000_out.txt
```

## Comments

Lines that are commented are skipped by the compiler, will not be compiled, nor executed

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

## Main function

```c
// Execution of a c code starts within main function
main(int argc, char** argv)
{
    int something;
    return 0;
}
```

## Printing (standard input output library)

To be able to use more funcitonality than just the one embeded into the language.
It is possible to include a library.

```c
// Include a standard input output library at the top of the c file
#include <stdio.h>
```
```c
printf("Printing \"Printing \\n\"\n");
```

[source](http://www.cplusplus.com/reference/cstdio/printf/)

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

### Formated print 

```c
// Integer
int num = 10;
printf("%d, %i\n", num, num); // There is a difference between i and d
// Flouat and double
float decimal = 10.6;
double precise = 10.666666666666666666;
printf("%f, %f\n", decimal, precise);
// Char, String
char letter = 'q';
char string[] = "String"
printf("%c, %s\n", letter, string);
// Unsigned int, long int, unsigned long int, long float
unsigned int ui;
long int li;
unsigned long int uli;
long float lf
printf("...");
```

[There is a difference between i and d](https://stackoverflow.com/questions/1893490/what-is-the-difference-between-conversion-specifiers-i-and-d-in-formatted-io-f)


#### Advance formating

```c
// Inside a funtion
printf("% 3d\n", invisible_sign_right_adjusted);
// Convert integer back to string for later check
snprintf(string, max_size_of_string, "%d", integer);
```

[Printf documentation](https://www.cypress.com/file/54441/download#:~:text=Using%20printf%20numbers%20can%20be,right%2Djustified%20with%20leading%20spaces.)

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

### Precedence 2

```c
// Return a size in bytes, the value is of type size_t
sizeof(something)
```
[more about size_t](https://devdocs.io/c/types/size_t)

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

### If

```c
if (condition) {
    stuff();
} else if (condition_2){
    stuff_2();
} else {
    stuff_else();
}
```

### Ternary condition

```c
(condition)? positive(): negative();

a = (condition)? b: c;
```

### Switch

```c
switch (expression) ​{
case constant1:
    stuff();
    break;
case constant2:
    stuff_more();
    break;
default:
    stuff_default();
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

## Loops

```c
for (i = 0; i < size; i++) {
    stuff();
}

while (condition) {
    stuff();
}

while (1) {
    until_break();
    break;
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

## Libraries

### Standard input outpu (stdio)

### Standard input

```c
if (scanf("%d %d %d", &s_bob, &s_tom, &delay) !=3 || s_bob <= 0 || s_tom <= 0 || delay < 0) {
    printf("%s\n", m_incorrect);
    return 0;
}
// read input by bytes (chars)
check = scanf("%c", &char)
if (check == -1)
    printf("end of file");
else if (check != 1)
    return 1;
else
    return 0;
```

## Time

```c
#include <time.h>
```
```c
time_t t;
printf("Time in seconds from 1970: %li\n", time(&t));
```

## Standard library

[Nice source](https://www.tutorialspoint.com/c_standard_library/)

```c
#include <stdlib.h>
```

### String features

```c
int a;
a = (int) strtol(argv[1], NULL, 0);
printf("a %d\n", a);

size_t str_len = strlen(str_2);
```

### Constants

```
return EXIT_FAILURE;
```

### Sorting

```c
int double_cmp (const void * a, const void * b) 
{
    return ( *(double*)a - *(double*)b );
}

// main
double arr[] = {1.5, 67, 4.6, -132.7, 0.00006, 500000.25, -362};
int arr_len = static_array_size(arr);
qsort(arr, arr_len, sizeof(arr[0]), double_cmp);
```

### Randomness

```c
// Get random integer
rand() // psudo random integer, always the same sequence of numbers

// Do not set the seed is the same as set it to 1
srand(1);
rand() // absolutely the same "random" nubmer as above

// Common practice is to set the seed with time
srand(time(0)); // srand((unsigned) time(&t));
rand()
```

### Dynamic memory

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

## Limits

```c
#include <limits.h>

printf("LONG_MAX %li\n", LONG_MAX);
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

## Object Orientated Programming

C does not have builtin support for OOP, however to some extent the paradigm is possible and may be beneficial.

[OOP in C (codementor)](https://www.codementor.io/@michaelsafyan/object-oriented-programming-in-c-du1081gw2)

## TODO

- [variable scope](https://study.com/academy/lesson/variable-scope-in-c-programming.html#:~:text=In%20programming%2C%20variable%20scope%20denotes,are%20passed%20to%20other%20functions.)
- make, makefile
- how to add libraries and where to
