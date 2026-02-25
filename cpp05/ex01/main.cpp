#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "--- TEST 1: Basic Form Creation and Signing ---" << std::endl;
    try {
        Bureaucrat boss("The Boss", 1);
        AForm contract("Top Secret Contract", 10, 50);
        
        std::cout << contract; // Tests operator<<
        boss.signForm(contract); // Tests Bureaucrat::signForm
        std::cout << contract; // Check if status changed to SIGNED
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Bureaucrat Grade Too Low to Sign ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        AForm importantForm("Important Form", 1, 1);
        
        std::cout << importantForm;
        intern.signForm(importantForm); // Should fail and print "couldn't sign because..."
        std::cout << importantForm;
    } catch (std::exception &e) {
        std::cerr << "Caught in main: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Invalid Form Creation (Grade Too High) ---" << std::endl;
    try {
        AForm illegalForm("Illegal", 0, 50);
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Invalid Form Creation (Grade Too Low) ---" << std::endl;
    try {
        AForm lowForm("Janitor Duties", 151, 150);
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 5: Signing an Already Signed Form ---" << std::endl;
    try {
        Bureaucrat manager("Manager", 5);
        AForm vacation("Vacation Request", 10, 10);
        
        manager.signForm(vacation);
        manager.signForm(vacation);
    } catch (std::exception &e) {
        std::cerr << "Caught error: " << e.what() << std::endl;
    }

    return 0;
}
