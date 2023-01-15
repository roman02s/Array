#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Array.hpp"

int main() {
	Array<int> arr(10);
    for(int & i : arr)
        i = rand() % 10;
    arr[0] = 7;
    arr[1] = 9;
    std::for_each(arr.cbegin(), arr.cend(), [](int x) {
        std::cout << x << ' ';
    });
    Array<int> qwe = arr;
    Array<int> qwe1(arr);
    arr.clear();
    std::cout << '\n';
	return 0;
}