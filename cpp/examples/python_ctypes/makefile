lib_python_ctypes.so : python_ctypes.o
	g++ -shared -Wl,-soname,lib_python_ctypes.so -o lib_python_ctypes.so python_ctypes.o

python_ctypes.o : python_ctypes.cpp
	g++ -c -fPIC python_ctypes.cpp -o python_ctypes.o
