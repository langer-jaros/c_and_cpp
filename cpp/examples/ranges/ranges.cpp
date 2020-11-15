#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

int main()
{
    std::vector<int> ints{5, 1, 3, 7, 4, 5, 6, 2};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
 
    for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
    }

    vec | views::filter([](int a){ return a % 2 == 0; })
}