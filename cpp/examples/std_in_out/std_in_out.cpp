#include <iostream>
#include <fstream>
using namespace std;

bool fu()
{
    int x;
    if(! (cin >> x)) {
        return false;
    }
    cout << "+" << x << endl;
    return true;
}

int main ()
{
    int x;
    // while(cin) {
    //     cin >> x;
    //     if (x == 0)
    //         return 0;
    //     cout << "+" << x << endl;
    // }

    while(fu()){
        x=0;
    }

    return 0;
}