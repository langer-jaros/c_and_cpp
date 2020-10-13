# Make

[source](https://github.com/ahockersten/makefile_tutorial)

```makefile
program: main.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $^
```

$^ - input(s) of this target
$@ - is "output(s) 

