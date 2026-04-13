#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    // --- Test 1: Vector (Contiguous memory) ---
    std::cout << "--- Testing std::vector ---" << std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(42);
    v.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Success: Found " << *it << " in vector." << std::endl;
        
        std::cout << "Attempting to find non-existent value (100)..." << std::endl;
        easyfind(v, 100);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    // --- Test 2: List (Linked nodes) ---
    std::cout << "--- Testing std::list ---" << std::endl;
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(l, 20);
        std::cout << "Success: Found " << *it << " in list." << std::endl;

        std::cout << "Attempting to find non-existent value (-5)..." << std::endl;
        easyfind(l, -5);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
