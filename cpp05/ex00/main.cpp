#include <iostream>
#include "Bureaucrats.hpp"

int main() {
    std::cout << "=== VALID CONSTRUCTION ===\n";
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== INVALID CONSTRUCTION (TOO HIGH) ===\n";
    try {
        Bureaucrat b("Bob", 0);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== INVALID CONSTRUCTION (TOO LOW) ===\n";
    try {
        Bureaucrat c("Charlie", 151);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== INCREMENT TEST ===\n";
    try {
        Bureaucrat d("Diana", 2);
        std::cout << d << std::endl;

        d.incrementGrade();
        std::cout << "After increment: " << d << std::endl;

        d.incrementGrade(); // should throw
    }
    catch (const std::exception& e) {
        std::cout << "Increment exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== DECREMENT TEST ===\n";
    try {
        Bureaucrat e("Edward", 149);
        std::cout << e << std::endl;

        e.decrementGrade();
        std::cout << "After decrement: " << e << std::endl;

        e.decrementGrade(); // should throw
    }
    catch (const std::exception& e) {
        std::cout << "Decrement exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== COPY TEST ===\n";
    try {
        Bureaucrat original("Frank", 75);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Copy exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== ASSIGNMENT TEST ===\n";
    try {
        Bureaucrat g("George", 100);
        Bureaucrat h("Henry", 50);

        std::cout << "Before assignment:\n";
        std::cout << g << std::endl;
        std::cout << h << std::endl;

        g = h;

        std::cout << "After assignment:\n";
        std::cout << g << std::endl;
        std::cout << h << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Assignment exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== END OF TESTS ===\n";
    return 0;
}
