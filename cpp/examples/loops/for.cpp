#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vect = {7, 5, 16, 8};
    
    for(int &n : vect) {
    // int n;           // does not work
    // for(n : vect) {  // like this
        cout << n << '\n';
    }

    cout << endl;

    for (auto &elem : vect) {
        cout << elem;
        (&elem != &vect.back())? cout << " ": cout << endl;
    }
}