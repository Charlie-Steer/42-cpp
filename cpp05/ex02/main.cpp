#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "--- Test 1: Grade requirements and execution ---" << std::endl;
    try {
        Bureaucrat boss("The Boss", 1);
        Bureaucrat minion("The Minion", 150);
        
        // Shrubbery: sign 145, exec 137 
        ShrubberyCreationForm sForm("garden");
        // Robotomy: sign 72, exec 45
        RobotomyRequestForm rForm("Bender");
        // Pardon: sign 25, exec 5
        PresidentialPardonForm pForm("Criminal");

        std::cout << "\n-- Testing Shrubbery --" << std::endl;
        minion.signForm(sForm); // Should fail
        boss.signForm(sForm);   // Should succeed
        boss.executeForm(sForm); // Should create garden_shrubbery file

        std::cout << "\n-- Testing Robotomy (50/50 chance) --" << std::endl;
        boss.signForm(rForm);
        boss.executeForm(rForm); // Should hear drilling noises
        boss.executeForm(rForm); 

        std::cout << "\n-- Testing Presidential Pardon --" << std::endl;
        boss.signForm(pForm);
        boss.executeForm(pForm); // Should be pardoned by Zaphod Beeblebrox

    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Execution without signature ---" << std::endl;
    try {
        Bureaucrat midLevel("Manager", 40);
        RobotomyRequestForm rForm2("Target");
        
        // This should throw an exception because it's not signed
        midLevel.executeForm(rForm2);
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Grade too low to execute ---" << std::endl;
    try {
        Bureaucrat lowly("Lowly", 100);
        RobotomyRequestForm rForm3("Robot");
        
        Bureaucrat admin("Admin", 1);
        admin.signForm(rForm3); // Signed, but lowly can't execute (needs grade 45)
        
        lowly.executeForm(rForm3);
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}
