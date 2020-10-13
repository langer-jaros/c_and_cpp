#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main ( void )
{
    vector<int> numbers;
    copy (istream_iterator<int>(cin),
    istream_iterator<int>(), back_inserter(numbers));
    sort ( numbers . begin (), numbers . end () );
    cout << numbers[numbers.size () / 2] << endl;

    cout << numbers.size() << endl;
    return 0;
}