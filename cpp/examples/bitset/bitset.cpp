#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

int main ()
{
    bitset<16> zeros;
    bitset<16> ones(pow(2,16) - 1);
    bitset<16> fofo (0xf0f0);
    bitset<16> ten (std::string("0101111001"));

    cout << "zeros:\t" << zeros << endl;
    cout << "ones: \t" << ones  << endl;
    cout << "fofo: \t" << fofo  << endl;
    cout << "ten:  \t" << ten   << endl;

    cout << endl;

    cout << "ten[0]: " << ten[0] << endl;
    cout << "ten[1]: " << ten[1] << endl;
    cout << "ten[2]: " << ten[2] << endl;
    cout << "ten[3]: " << ten[3] << endl;

    return 0;
}
