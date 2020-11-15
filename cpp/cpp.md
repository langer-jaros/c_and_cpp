# cpp

## Contents <!-- omit in toc -->

- [Install C++](#install-c)
- [Compile a cpp code](#compile-a-cpp-code)
- [Comments, documentation](#comments-documentation)
- [Variables](#variables)
  - [Boolean](#boolean)
  - [Arrays](#arrays)
  - [String](#string)
  - [Enum](#enum)
  - [Byte](#byte)
- [Operator precedence](#operator-precedence)
- [Print and read (standard input, output)](#print-and-read-standard-input-output)
- [Conditions](#condtitions)
- [Loops](#loops)
- [Structures](#structres)
- [Assertions](#assertions)
- [Files](#files)
- [Dynamic memory](#dynamic-memory)
- [STL - standard template library](#stl---standard-template-library)
  - [Vector](#vector)
- [Limits](#limits)
- [make](#make)
- [Debugger](#debugger)
  - [GDB](#gdb)
- [Header file](#header-file)
- [cmath](#cmath)
- [Algorithm](#algorithm)
- [Lambda functions](#lambda-functions)
- [Iterator](#iterator)
- [Numeric](#numeric)
- [Chrono](#chrono)
- [Bitset](#bitset)
- [Ranges](#ranges)

## Install C++

```sh
sudo apt-get install build-essential
```

## Compile a cpp code

```sh
g++ main.cpp # Basic compilation, output is executable a.out
g++ main.cpp -o executable_main # rename output
g++ -Wall -Wextra -pedantic main.cpp -fsanitize=address -g -o main # personally recommended
```

| option    | description                                                           |
| ---       | ---                                                                   |
| -o <file> | Place the output into <file>.                                         |
| -Wall     | Enables all the warnings about constructions that some users consider questionable, and that are easy to avoid |
| -Wextra   | Enables some extra warning flags that are not enabled by -Wall        |
| -Werror   | Make all warnings into errors                                         |
| -pedantic | Issue all the warnings demanded by strict ISO C and ISO C++           |
| -g        | Produce debugging information in the operating system’s native format |
| -c        | Compile and assemble, but do not link                                 |
| -fsanitize=address | Enable AddressSanitizer, a fast memory error detector.       |

- [GCC documentation](https://gcc.gnu.org/onlinedocs/gcc/)

## Comments, documentation

[link](https://developer.lsst.io/cpp/api-docs.html)

## Variables

### Boolean

Boolean is integer 0 and 1.

```cpp
bool var = true; // 1
```

[source](https://www.learncpp.com/cpp-tutorial/boolean-values/)

### Arrays

```cpp
// Initialize array of int with one value
int scores[100] = {0};
```

### String

```cpp
#include<string>
```

```cpp
std::stoi(string) // String to int
std::stod(string) // String to double
```

[strings are objects, not array of characters](https://stackoverflow.com/questions/3454900/whats-the-difference-between-c-strings-and-c-strings)
[read](https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/)
[link](https://www.cprogramming.com/tutorial/unicode.html)
[unicode string](https://www.oreilly.com/library/view/c-cookbook/0596007612/ch13s02.html)
[unicode characters](https://en.wikipedia.org/wiki/List_of_Unicode_characters)

#### w_char

```cpp
wchar_t wide_c = L"a";
```

#### Unicode

[how-to-print-unicode-character-in-c](https://stackoverflow.com/questions/12015571/how-to-print-unicode-character-in-c)

```cpp
#include <iostream>
#include <io.h>
#include <fcntl.h>

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"Hello, \u0444!\n";
}
```

### Enum

```cpp
enum APPROACH { BF=1, BAB=2, DP=3, GH=4, REDUX=5, FPTAS=6 };
```

[enum cppreference](https://en.cppreference.com/w/cpp/language/enum)

### Byte

There is std::byte since C++17

[source](https://en.wikipedia.org/wiki/C++17)

## Operator precedence

First three categories are must

| Prec. | Operator          | Description                            | Associativity |
| ---   | ---               | ---                                    | ---           |
| 1     |                   |                                        | Left-to-right |
|       | ::                | Scope resolution                       |               |
| 2     |                   |                                        | Left-to-right |
|       | a++   a--         | Suffix/postfix increment and decrement |               |
|       | type()   type{}   | Functional cast                        |               |
|       | a()               | Function call                          |               |
|       | a[]               | Subscript                              |               |
|       | .   ->            | Member access                          |               |
| 3     |                   |                                        | Right-to-left |
|       | ++a   --a         | Prefix increment and decrement         |               |
|       | +a   -a           | Unary plus and minus                   |               |
|       | !   ~             | Logical NOT and bitwise NOT            |               |
|       | (type)            | C-style cast                           |               |
|       | *a                | Indirection (dereference)              |               |
|       | &a                | Address-of                             |               |
|       | sizeof            | Size-of[note 1]                        |               |
|       | co_await          | await-expression (C++20)               |               |
|       | new   new[]       | Dynamic memory allocation              |               |
|       | delete   delete[] | Dynamic memory deallocation            |               |

- [Operator precedence link](https://en.cppreference.com/w/cpp/language/operator_precedence)

## Print and read (standard input, output)

```cpp
#include <iostream>
```

```cpp
int n, user_num;
// Read n from stdin
cin >> n;

// Print "Hello {n}th world!\n"
cout << "Hello " << n << "th world! There is user number " << user_num << "." << endl;
// Print true/false instead of 1/0
std::cout << "0: " << false << ", false: " << std::boolalpha << false << endl;
```

[cin in while loop](https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num)

## Conditions

```cpp
switch(expression) {
case constant-expression  :
    statement(s);
    break; //optional
case constant-expression  :
    statement(s);
    break; //optional
  
   // you can have any number of case statements.
default : //Optional
    statement(s);
}
```
[source](https://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm)


## Loops

```cpp
int i;
for (i = n; i > 0; --i) {
    // executes for i = [n, n - 1, ... 1]
    // if conditions fits, code is executed and then comes the third section
    // pre increment and post increment does not matter then
}
// Range-based for loop
vector<int> v = {7, 5, 16, 8};
for(int n : v) {
    cout << n << '\n';
}
```

- [source](https://stackoverflow.com/questions/4706199/post-increment-and-pre-increment-within-a-for-loop-produce-same-output)
- [range based for loop](https://en.cppreference.com/w/cpp/language/range-for)

## Structures

```cpp
struct ITEM { int *w; int *v; };
```

## Assertions

```cpp
#include <cassert>
```

```cpp
assert("Result value was false" && result == true);
```

[more - cppreference assert](https://en.cppreference.com/w/cpp/error/assert)

## Files

```cpp
#include <iostream>
#include <fstream>
```

```cpp
ofstream f_out; // ifstream f_in; fstream f_in_out;
myfile.open ("example.txt");
assert(("Input file was not possible to open", myfile.fail() == false));
myfile << "Writing this to a file.\n";
myfile.close();
```

[files link](http://www.cplusplus.com/doc/tutorial/files/), 
[additional err message](https://stackoverflow.com/questions/17337602/how-to-get-error-message-when-ifstream-open-fails)

[source](http://www.cplusplus.com/doc/tutorial/files/)

## Dynamic memory

```cpp
// Allocate memory for Car my_car
Car my_car = new Car;
// Delte Car my_car
delete my_car;
```
```cpp
// Allocate memory for array
int *weights;
weights = new int [5];

// Initialize with zeros
arr = new int[10]();

// free the memory
delete[] arr;
```

[source](http://www.cplusplus.com/doc/tutorial/dynamic/)

## STL - standard template library

### Vector

```cpp
#include <iostream>
#include <vector>

using namespace std;
```

```cpp
// Initialization
vector<int> v;
vector<int> v = {7, 5, 16, 8};  // define vector with values
vector<int> v(10);              // vector of 10 values
vector<int> v(10, 123);         // vector of 10 values 123
// Vector of vectors 10x10 with values 1
vector<vector<int>> v(10, vector<int>(10, 1));

// Access items
v.front();  // get first item
v.back();   // get last item

// Modify values
v.push_back(25);    // Add two more integers to vector
v.pop_back();       // deletes last element
v.clear();          // delete all items
v.erase (v.begin(),v.begin()+3) // erase the first 3 elements:

// Cappacity
v.size()        // number of elements
v.capacity()    // number of elements for that the storage is allocated

// Values
v.empty()   // number of elements is equal to zero
```

- [vector cppreference](https://en.cppreference.com/w/cpp/container/vector)
- [vector cplusplus](http://www.cplusplus.com/reference/vector/)

## Limits

```cpp
#include <climits>
```

```cpp
long l = LONG_MAX;
```

[limits](http://www.cplusplus.com/reference/climits/)

## make

[make](https://linux.101hacks.com/unix/make/)

```makefile
target [target ...]: [component ...] [<TAB> command 1] . . . 
    [<TAB> command n]
```
[source](https://www.computerhope.com/unix/umake.htm)

## Debugger

```sh
valgrind --leak-check=full ./a.out
```

### GDB

```bash
apt-get install gdb
```

```bash
# Compile your program ,this will generate a.out file with required debugging information
g++ -g file.c
# Start with gdb
gdb a.out
```

| action              | description                                                             |
| ---                 | ---                                                                     |
| b function          | Set a breakpoint at entry to function function.                         |
| b linenum           | Set a breakpoint at line linenum in the current source file.            |
| b linenum if i == 5 | Break only if condition is satisfied                                    |
| b filename:function | Set a breakpoint at entry to function function found in file filename.  |
| b +offset           | Set a breakpoint some number of lines forward or back from the position at which execution stopped in the currently selected stack frame. |
| run                 | Start your program, it will stop at break point                         |
| run < path/file     | Arguments and stdin works as usual                                      |
| c                   | Continue running your program (after stopping, e.g. at a breakpoint).   |
| s                   | option s is to step single line and even step into functions            |
| n                   | option n is to execute next line and step over functions                |
| p variable_name     | to print the value of variable at that particular instance very helpful |
| clear linenum       | Removes breakpoint from line linenum                                    |

- [which debbuger (stackoverwlow)](https://stackoverflow.com/questions/18271363/line-by-line-c-c-code-debugging-in-linux-ubuntu)
- [debugging with gdb](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_chapter/gdb_toc.html)

## Header file

```h
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void test_empty(void);
float test_add(float x, float y);
void test_passing_array(int *data, int len);

#ifdef __cplusplus
}
#endif
```

[source](https://solarianprogrammer.com/2019/07/18/python-using-c-cpp-libraries-ctypes/)
[header files](https://www.learncpp.com/cpp-tutorial/header-files/)

## cmath


```cpp
#include <cmath>
```

```cpp
pow(numer, power)
log2(number)
```

[cppreference](https://en.cppreference.com/w/cpp/numeric/math/pow)

## Algorithm

```cpp
#include <algorithm>

using namespace std;
```

```cpp
// max
cout << max(235, 0x150) << endl;

// max_element
int v[] = { 4, 7, 4, 6, 9, 3, 5 }; 
int *int_ptr;  
int_ptr = max_element(v, v + (sizeof(v) / *v) - 1);
cout << *int_ptr << endl;

// copy_if
std::vector<int> to_vector;
std::copy(from_vector.begin(), from_vector.end(),
          std::back_inserter(to_vector));

// remove_if
remove_if(prob.items.begin(), prob.items.end(),
            [prob] (Item i) { return i.w > prob.W; })

// swap (values, pointers ...)
swap(curr, next);
```

- [max_element](https://en.cppreference.com/w/cpp/algorithm/max_element)
- [remove_if](http://www.cplusplus.com/reference/algorithm/remove_if/)

## Lambda functions

- [lambda cppreference](https://en.cppreference.com/w/cpp/language/lambda)

## Iterator

```cpp
#include <iterator>
```

```cpp
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::copy_if(std::back_inserter(v), 3, -1);
for (int n : v)
    std::cout << n << ' ';
```

## Numeric

```cpp
#include <numeric>
```

```cpp
// Sum item value
accumulate(prob.items.begin(), prob.items.end(), 0,
        [prob] (int sum, const Item &item) { return sum + item.v; }
```

- [how to sum up vector (stackoverflow)](https://stackoverflow.com/questions/3221812/how-to-sum-up-elements-of-a-c-vector)

## Chrono

```cpp
#include <chrono>
using namespace std;
```

```cpp
auto start = std::chrono::steady_clock::now();
std::cout << "f(42) = " << fibonacci(42) << '\n';
auto end = std::chrono::steady_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
```
[source](https://en.cppreference.com/w/cpp/chrono)

## Bitset

```cpp
#include <bitset>
using namespace std;
```

```cpp
bitset<16> fofo (0xf0f0);
bitset<16> ten (std::string("0101111001"));
```

[bitset (cplusplus)](http://www.cplusplus.com/reference/bitset/bitset/bitset/)
[cpp reference](https://en.cppreference.com/w/cpp/utility/bitset)

## Ranges

- [modern way to filter stl container (stackoverflow)](https://stackoverflow.com/questions/21204676/modern-way-to-filter-stl-container)
- [views::filter, filter_view](https://en.cppreference.com/w/cpp/ranges/filter_view)
