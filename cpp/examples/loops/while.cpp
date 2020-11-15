#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int next_idx = 0, last_idx = 1;

    while (++next_idx <= last_idx) {
        cout << "Next: " << next_idx << ", last: " << last_idx << endl;
        if (next_idx == 1) last_idx = 3;
        if (next_idx == 3) last_idx = 5;
    } 

}
