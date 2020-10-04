// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

void write_to_file(byte *string, len n)
{
    ofstream myfile;
    // myfile.open ("example.txt");
    myfile.open ();
    

    myfile << "Writing this to a file. ❤️\n";
    myfile.close();

}

int main ()
{
    char *string = "❤️.txt"
    write_to_file()

    return 0;
}