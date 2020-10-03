# c

## MENU

## Install C++

```sh
sudo apt-get install build-essential
```

## Compile a cpp code

```sh
g++ -Wall -pedantic main.cpp -g -o ./a.out
```

## Dynamic memory

```cpp
int *weights;
weights = new int [5];
```

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

## Unicode 

[link](https://www.cprogramming.com/tutorial/unicode.html)