#include "ScalarConverter.hpp"
#include <iostream>

void runTest(const std::string& literal) {
    std::cout << "--- Testing: [" << literal << "] ---" << std::endl;
    ScalarConverter::convert(literal);
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    // If arguments are provided, test those specifically
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            runTest(argv[i]);
        }
        return 0;
    }

    // --- Mandatory Subject Examples ---
    runTest("0");
    runTest("nan");
    runTest("42.0f");

    // --- Char Literals ---
    runTest("a");
    runTest("Z");
    runTest("*");
    // Note: '0' should be detected as an INT, not a CHAR [cite: 139, 141]

    // --- Integer Literals & Overflows ---
    runTest("42");
    runTest("-42");
    runTest("2147483647");  // INT_MAX
    runTest("-2147483648"); // INT_MIN
    runTest("2147483648");  // Overflow: should show "impossible" for int

    // --- Float Literals ---
    runTest("0.0f");
    runTest("4.2f");
    runTest("-4.2f");
    runTest("42.42f");

    // --- Double Literals ---
    runTest("0.0");
    runTest("4.2");
    runTest("-4.2");
    runTest("42.42");

    // --- Pseudo-literals (Science & Fun) ---
    runTest("-inff");
    runTest("+inff");
    runTest("nanf");
    runTest("-inf");
    runTest("+inf");
    runTest("nan");

    // --- Edge Cases ---
    runTest(".");     // Should probably fail parsing or be handled
    runTest("42.f");  // Valid float in some contexts
    runTest("f");     // Should be treated as a char 'f'
    runTest("42.0ff"); // Invalid literal

	std::cout << "End of tests.\n";

    return 0;
}
