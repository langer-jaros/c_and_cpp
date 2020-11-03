#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc <= 1) {
        cout << "Required argument was not passed, operation failed.";
        return 1;
    }
    int i;
    for (i = 1; i < argc; i++)
        cout << "Argument[" << i << "] = " << argv[i] << endl;

    return 0;
}