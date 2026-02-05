#include "Bureaucrats.hpp"
#include <iostream>

Bureaucrats::Bureaucrats() {
    std::cout << "Bureaucrats default constructor called." << std::endl;
}

Bureaucrats::Bureaucrats(const Bureaucrats& other) {
    std::cout << "Bureaucrats copy constructor called." << std::endl;
    *this = other;
}

Bureaucrats& Bureaucrats::operator=(const Bureaucrats& other) {
    std::cout << "Bureaucrats copy assignment operator called." << std::endl;
    if (this != &other) {
        // TODO: Copy attributes here.
    }
    return *this;
}

Bureaucrats::~Bureaucrats() {
    std::cout << "Bureaucrats destructor called." << std::endl;
}
