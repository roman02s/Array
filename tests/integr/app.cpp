#include <iostream>
#include <vector>

#include "Array.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Enter values of string array" << std::endl;
        return -1;
    }
    if (argc - 2 != atoi(argv[1])) {
        std::cout << argc << '\n';
        std::cerr << "n does not match the length of array" << std::endl;
        return -2;
    }
    const size_t n = atoi(argv[1]);
    Array<std::string> array(n);
    int k = 2;
    for(std::string &string: array)
        string = argv[k++];
    array.sort([&](auto &a, auto &b) {return a < b;});
    for(const std::string &string: array)
        std::cout << string << '\n';
    return 0;
}