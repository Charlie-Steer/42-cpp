#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm* rrf = NULL;

    std::cout << "--- Test 1: Robotomy Request ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; // Crucial: Intern returns a 'new' pointer
    }

    std::cout << "\n--- Test 2: Shrubbery Creation ---" << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Test 3: Presidential Pardon ---" << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Test 4: Unknown Form (Error Handling) ---" << std::endl;
    try {
        rrf = someRandomIntern.makeForm("coffee request", "Intern");
        if (rrf) {
            delete rrf;
        }
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}
