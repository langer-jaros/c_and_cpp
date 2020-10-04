#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    int x;
    while(cin) {
        cin >> x;
        if (x == 0)
            return 0;
        cout << "+" << x << endl;
    }
    return 0;
}