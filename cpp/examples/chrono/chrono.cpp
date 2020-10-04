#include <iostream>
#include <chrono>
#include <climits>
 
void new_and_delete(int len)
{
    int i;
    for (i = 0; i < INT_MAX; i++) {
        // int *a = new int[INT_MAX];
        int *a = new int[len];
        delete a;
    }
}
 
int main()
{
    auto start = std::chrono::steady_clock::now();
    new_and_delete(2);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}