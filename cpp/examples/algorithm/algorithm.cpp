#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct STATE {
    int i; // index of the state item
    int w; // total weight of the state
    int v; // total value of the state
    int p; // previous weight or value
};

bool cmp_vals(const STATE &ls, const STATE &rs)
{
  return ls.v < rs.v;
}

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

    vector<STATE> sts;
    vector<vector<STATE>> dp(prob.n+1, vector<STATE>(prob.W+1));

    sts.push_back({1, 10, 135, 0});
    sts.push_back({2, 11, 132, 0});

    auto max_st = max_element(sts.begin(), sts.end(),
         [] (const STATE &ls, const STATE &rs) {return ls.v < rs.v;});

    STATE st;
    st = max_st[];
    // cout << "id: " << max_st->i << ", weight: " <<  max_st->w << ", value: " << max_st->v << endl;
    cout << "id: " << st.i << ", weight: " <<  st.w << ", value: " << st.v << endl;

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