#include "Array.hpp"

#include <string>
#include <vector>
#include <gtest/gtest.h>


TEST(ArrayTest, Create) {
    Array<int> numbers(10);
    Array<bool> test(5);
    Array<char> word(4);
    Array<std::string> sentence(30);
    ASSERT_EQ(numbers.size(), 10);
    ASSERT_EQ(test.size(), 5);
    ASSERT_EQ(word.size(), 4);
    ASSERT_EQ(sentence.size(), 30);
    sentence.clear();
    word.clear();
    test.clear();
    numbers.clear();
}

TEST(ArrayTest, CreateEmpty) {
    Array<int> arr;
    ASSERT_EQ(arr.size(), 0);
}

TEST(ArrayTest, GetSet) {
    Array<int> numbers(10);
    numbers[0] = 10;
    ASSERT_EQ(numbers[0], 10);
    numbers.clear();
}

TEST(ArrayTest, Resize) {
    Array<std::string> names(10);
    ASSERT_EQ(names.size(), 10);
    names.resize(5);
    ASSERT_EQ(names.size(), 5);
}

TEST(ArrayTest, Iterator) {
    Array<std::string> names(10);
    for(std::string &name: names)
        name = "Петя";
}



TEST(ArrayTest, Filling) {
    Array<std::string> names(10);
    int k = 0;
    for(std::string &name: names)
        name = "Петя" + std::to_string(k++);

    ASSERT_TRUE(names.size() == 10);
    k = 0;
    for(const std::string &name: names)
        ASSERT_TRUE(name == "Петя" + std::to_string(k++));
}

