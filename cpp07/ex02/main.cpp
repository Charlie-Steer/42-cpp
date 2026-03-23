#include <iostream>
#include <string>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    // 1. Basic Construction and Size
    std::cout << "--- Basic Construction ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Size of numbers: " << numbers.size() << std::endl;

    // 2. Deep Copy Test (Copy Constructor)
    std::cout << "\n--- Deep Copy Test (Copy Constructor) ---" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        
        // Change original, check if copy remains same
        numbers[0] = -42;
        if (test[0] == mirror[0])
            std::cout << "SUCCESS: Copy is independent of original." << std::endl;
        else
            std::cout << "FAILURE: Copy changed with original!" << std::endl;
    }

    // 3. Deep Copy Test (Assignment Operator)
    std::cout << "\n--- Deep Copy Test (Assignment) ---" << std::endl;
    Array<int> assign_test;
    assign_test = numbers;
    numbers[0] = 999;
    if (assign_test[0] != numbers[0])
        std::cout << "SUCCESS: Assignment is a deep copy." << std::endl;

    // 4. Exception Handling (Bounds)
    std::cout << "\n--- Exception Handling ---" << std::endl;
    try {
        std::cout << "Trying to access index -2: ";
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying to access index MAX_VAL: ";
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    // 5. Complex Types and Initialization
    std::cout << "\n--- Complex Types (std::string) ---" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "Málaga";
    
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << "strings[" << i << "]: " << strings[i] << std::endl;

    // 6. Const Accessibility
    std::cout << "\n--- Const Accessibility ---" << std::endl;
    const Array<std::string> const_strings = strings;
    std::cout << "Const access [1]: " << const_strings[1] << std::endl;
    // const_strings[1] = "change"; // This would fail compilation, which is correct!

    // Cleanup for mirror
    delete [] mirror;
    
    std::cout << "\n--- Tests Finished ---" << std::endl;
    return 0;
}
