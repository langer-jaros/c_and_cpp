#include <iostream>
#include <vector>
#include <ranges>

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

    PROBLEM new_prob = prob;

    new_prob.items.push_back({123, 321});
    new_prob.items.push_back({333, 111});

    new_prob.items[0] = ITEM({12, 31});

    cout << "OLD: items capacity: " << prob.items.capacity() << ", v size: ";
    cout << prob.items.size() << ", v[0].weight: " << prob.items[0].w << endl;

    cout << "NEW: items capacity: " << new_prob.items.capacity() << ", v size: ";
    cout << new_prob.items.size() << ", v[0].weight: " << new_prob.items[0].w << endl;

    return 0;
}
