#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    vector<int> vect = { 235, 0x150 };

    cout << max(vect[0], vect[1]) << endl;

    cout << max(235, 0x150) << endl;
    // cout << max(1,2,3,4,5,6) << endl; // nope

    int v[] = { 4, 7, 4, 6, 9, 3, 5 }; 

    int *int_ptr; 
    int_ptr = max_element(v, v + (sizeof(v) / *v) - 1);
    cout << *int_ptr << endl;

    return 0; 
}