#include <iostream>
#include "iter.hpp"

// A function to increment an integer
void increment(int &n) {
    n++;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;

    std::cout << "Original int array: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing values..." << std::endl;
    ::iter(intArray, intLen, increment);

    std::cout << "Modified int array: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "42", "C++", "Templates"};
    std::cout << "String array: ";
    ::iter(strArray, 4, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
