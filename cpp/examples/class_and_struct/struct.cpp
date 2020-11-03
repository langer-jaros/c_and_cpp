#include<iostream>
#include <vector>

using namespace std;

struct ITEM {
    int w; // weight
    int v; // value
};

struct PROBLEM {
    int n;                  // Number of items
    int W;                  // Weight capacity
    int V;                  // Required total value
    vector<ITEM> items;     // vector of items
    vector<int> values_left; // sums of values left
};

int main()
{
    PROBLEM prob;

    ITEM i = {10, 130};

    prob.items.push_back(i);

    cout << "First item: weight = " << prob.items[0].w << ", value =" << prob.items[0].v << endl;

    return 0;
}