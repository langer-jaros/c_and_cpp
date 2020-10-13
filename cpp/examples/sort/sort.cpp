#include<bits/stdc++.h> 
using namespace std; 

struct Item
{ 
    int w, v; 
}; 
  
// Compares two intervals according to staring times. 
bool compareInterval(Item i1, Item i2) 
{ 
    return (i1.v/i1.w >= i2.v/i2.w); 
} 
  
int main() 
{ 
    Item arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    // sort the intervals in increasing order of 
    // start time 
    sort(arr, arr+n, compareInterval); 
  
    cout << "Intervals sorted by start time : \n"; 
    for (int i=0; i<n; i++) 
       cout << "[" << arr[i].w << "," << arr[i].v 
            << "] "; 
  
    return 0; 
} 