# c

## Content

- [c](#c)
  - [Content](#content)
  - [Install C++](#install-c)
  - [Compile a cpp code](#compile-a-cpp-code)
  - [Comments, documentation](#comments-documentation)
  - [Variables](#variables)
    - [Boolean is integer 0 and 1](#boolean-is-integer-0-and-1)
    - [Byte](#byte)
  - [Operator precedence](#operator-precedence)
  - [Stdin, stdout](#stdin-stdout)
  - [String](#string)
    - [w_char](#w_char)
    - [https://stackoverflow.com/questions/12015571/how-to-print-unicode-character-in-c](#httpsstackoverflowcomquestions12015571how-to-print-unicode-character-in-c)
  - [Condtitions](#condtitions)
  - [Loops](#loops)
  - [Assertions](#assertions)
  - [Files](#files)
  - [Dynamic memory](#dynamic-memory)
  - [STL - standard template library](#stl---standard-template-library)
    - [Vector](#vector)
  - [Limits](#limits)
    - [make](#make)
  - [Debugger](#debugger)
    - [TODO: GDB](#todo-gdb)
  - [Header file](#header-file)
  - [Chrono](#chrono)

## Install C++

```sh
sudo apt-get install build-essential
```

## Compile a cpp code

```sh
g++ -Wall -pedantic main.cpp -g -o ./a.out
```

## Comments, documentation

[link](https://developer.lsst.io/cpp/api-docs.html)

## Variables

### Boolean is integer 0 and 1

[source](https://www.learncpp.com/cpp-tutorial/boolean-values/)

### Byte

There is std::byte since C++17

[source](https://en.wikipedia.org/wiki/C++17)

## Operator precedence

[Operator precedence link](https://en.cppreference.com/w/cpp/language/operator_precedence)

## Stdin, stdout

```cpp
#include <iostream>
```

```cpp
int n, user_num;
// Read n from stdin
cin >> n;

// Print "Hello {n}th world!\n"
cout << "Hello " << n << "th world! There is user number " << user_num << "." << endl;
```

[cin in while loop](https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num)

## String

[strings are objects, not array of characters](https://stackoverflow.com/questions/3454900/whats-the-difference-between-c-strings-and-c-strings)
[read](https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/)
[link](https://www.cprogramming.com/tutorial/unicode.html)
[unicode string](https://www.oreilly.com/library/view/c-cookbook/0596007612/ch13s02.html)
[unicode characters](https://en.wikipedia.org/wiki/List_of_Unicode_characters)

### w_char

```cpp
wchar_t wide_c = L"a";
```

### https://stackoverflow.com/questions/12015571/how-to-print-unicode-character-in-c

```cpp
#include <iostream>
#include <io.h>
#include <fcntl.h>

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"Hello, \u0444!\n";
}
```

## Condtitions

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
```
[source](https://stackoverflow.com/questions/4706199/post-increment-and-pre-increment-within-a-for-loop-produce-same-output)

## Assertions

```cpp
#include <cassert>
```

```cpp
assert(("Result value was false", result == true));
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
int *weights;
weights = new int [5];

// Initialize with zeros
a = new int[10]();

// free the memory
delete a;
```

[source](http://www.cplusplus.com/doc/tutorial/dynamic/)

## STL - standard template library

### Vector

```cpp
#include <iostream>
#include <vector>
 
int main()
{
    // Create a vector containing integers
    std::vector<int> v = {7, 5, 16, 8};
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
 
    // Iterate and print values of vector
    for(int n : v) {
        std::cout << n << '\n';
    }
}
```

https://en.cppreference.com/w/cpp/container/vector

## Limits

```cpp
#include <climits>
```

```cpp
long l = LONG_MAX;
```

[limits](http://www.cplusplus.com/reference/climits/)

### make

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

### TODO: GDB

https://stackoverflow.com/questions/18271363/line-by-line-c-c-code-debugging-in-linux-ubuntu

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


## Chrono

```cpp
#include <chrono>
```

```cpp
auto start = std::chrono::steady_clock::now();
std::cout << "f(42) = " << fibonacci(42) << '\n';
auto end = std::chrono::steady_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
```
[source](https://en.cppreference.com/w/cpp/chrono)
