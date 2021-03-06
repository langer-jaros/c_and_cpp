#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Create a vector containing integers
    vector<int> v = {7, 5, 16, 8};
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
 
    // Iterate and print values of vector
    for(int n : v) {
        cout << n << '\n';
    }

    v.clear();

    for(int n : v) {
        cout << "never" << '\n';
    }

    vector<bool> boo (5, true);

    for(bool b : boo) {
        cout << "bool: " << b << '\n';
    }

    cout << "---------------- int to binary test -----------------" << endl;
    int a = 0b10;
    vector<bool> test = (vector<bool>)a;
    for(bool t : test) {
        cout << "bool: " << t << '\n';
    }
}
