#include <iostream>
#include <fstream>
#include "python_ctypes.h"

using namespace std;

void write_to_file(const char *file_in, const char *file_out)
{
    ifstream f_in;
    f_in.open(file_in);
    ofstream f_out;
    f_out.open(file_out);

    // wchar_t wc;
    // char *b = new char[100];
    char b[100];
    int i = 0;
    while (f_in >> b[i++]) {
        // todo safe reading
    }
    b[i] = '\0';
    f_in.close();

    f_out << "Writing: " << b << ", from file: " << file_in << " to file: " << file_out << ". ❤️\n";
    // delete b;
    f_out.close();
}
