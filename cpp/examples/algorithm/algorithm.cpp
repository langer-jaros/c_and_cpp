#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

struct Item {
    int i;
    int w; // weight
    int v; // value
};

int main ()
{
    // MAX
    vector<int> vect = { 235, 0x150 };
    cout << max(vect[0], vect[1]) << endl;
    cout << max(235, 0x150) << endl;
    // cout << max(1,2,3,4,5,6) << endl; // nope

    // MAX_ELEMENT (Array)
    int v[] = { 4, 7, 4, 6, 9, 3, 5 }; 
    int *int_ptr; 
    int_ptr = max_element(v, v + (sizeof(v) / *v) - 1);
    cout << *int_ptr << endl;

    // MAX_ELEMENT (Vector of structures)
    vector<Item> items ={{1, 158, 1347}, {2, 211, 1148}, {0, 207, 946}, {3, 232, 884}};

    auto max_item = max_element(items.begin(), items.end(),
         [] (const Item &i1, const Item &i2) {return i1.v < i2.v;});

    int boundary =  -1000000;
    cout << "max item 0 " << max_item[0].v << " , bigger than boundary(" << boundary << ") ";
    cout << boolalpha << (max_item[0].v > boundary) << endl;

    items.push_back({0, 12, 300});
    items.push_back({0, 15, 250});
    items.push_back({0, 17, 400});
    items.push_back({0, 13, 310});

    // COPY_IF
    vector<Item> filtered_items;

    int limit_weight = 12;
    copy_if(items.begin(), items.end(),
        back_inserter(filtered_items),
        [limit_weight] (Item i) { return i.w <= limit_weight; });

    for (auto item: filtered_items)
        cout << "Item: weight = " << item.w << ", value = " << item.v << endl;

    auto max_item_2 = max_element(filtered_items.begin(), filtered_items.end(),
         [] (const Item &i1, const Item &i2) {return i1.v < i2.v;});

    cout << '\n' << "Max Item: weight = " << max_item_2[0].w << " , value = " << max_item_2[0].v << endl;
    cout << endl;

    // REMOVE_IF and ERASE
    int weight = 100;
    items.erase(remove_if(items.begin(), items.end(), [weight] (Item i) { return i.w > weight; }), items.end());

    for (auto item: items)
        cout << "Item: weight = " << item.w << ", value = " << item.v << endl;

    cout << "items.size: " << items.size() << endl;

    // ACCUMULATE
    int item_sum = accumulate(items.begin(), items.end(), 0,
        [](int sum, const Item &item) { return sum + item.v; });

    cout << '\n' << "item_sum = " << item_sum << endl;

    return 0; 
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // Get the vector
//     vector<int> a = { 1, 45, 54, 71, 76, 12 };

//     // Print the vector
//     cout << "Vector: ";
//     for (int i = 0; i < a.size(); i++)
//         cout << a[i] << " ";
//     cout << endl;

//     // Find the max element 
//     cout << "\nMax Element = "
//          << *max_element(a.begin(), a.end());
//     return 0;
// }
