#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    // --- Test 1: Subject Example (Single addNumber) ---
    std::cout << "--- Test 1: Subject Basic Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest Span:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // --- Test 2: Templated addNumber (Range) ---
    std::cout << "\n--- Test 2: Range addNumber with std::vector ---" << std::endl;
    try {
        Span sp2 = Span(10000);
        std::vector<int> v;
        for (int i = 0; i < 5000; ++i)
            v.push_back(i * 2); // 0, 2, 4, 6...

        // Using the templated version
        sp2.addNumber(v.begin(), v.end());
        
        std::cout << "Added 5000 numbers via range." << std::endl;
        std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp2.longestSpan() << std::endl;
        
        // Test 3: Exception Handling (Span full)
        std::cout << "\n--- Test 3: Capacity Exception ---" << std::endl;
        sp2.addNumber(42); // This should work (size becomes 5001)
        
        Span spSmall = Span(2);
        spSmall.addNumber(1);
        spSmall.addNumber(2);
        spSmall.addNumber(3); // This should throw
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    // --- Test 4: Big Data Test (10,000+ numbers) ---
    std::cout << "\n--- Test 4: 20,000 Numbers Test ---" << std::endl;
    try {
        unsigned int amount = 20000;
        Span spBig = Span(amount);
        std::vector<int> vBig(amount);
        
        // Fill with random numbers
        std::srand(time(NULL));
        for (unsigned int i = 0; i < amount; ++i)
            vBig[i] = std::rand();

        spBig.addNumber(vBig.begin(), vBig.end());
        std::cout << "Successfully processed " << amount << " numbers." << std::endl;
        std::cout << "Shortest: " << spBig.shortestSpan() << std::endl;
        std::cout << "Longest:  " << spBig.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
