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

    vector<ITEM> v;

    v.push_back({123, 321});
    v.push_back({333, 111});
    
    v[0] = ITEM({12, 31});

    cout << "v capacity: " << v.capacity() << ", v size: " << v.size() << ", v[0].weight: " << v[0].w << endl;

    return 0;
}