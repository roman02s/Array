#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Array.hpp"

int main() {
	Array<int> arr(10);
    for(int & i : arr)
        i = rand() % 10;
    std::for_each(arr.cbegin(), arr.cend(), [](int x) {
        std::cout << x << ' ';
    });
    arr.clear();
    std::cout << '\n';
	return 0;
}