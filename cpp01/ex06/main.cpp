#include "Harl.hpp"
#include <iostream>

void error_message(std::string message) {
	std::cerr << "Error: " << message << "\n";
}

void log_message(std::string message) {
	std::cout << message << "\n";
}

int main(int argc, char *argv[]) {
	Harl harl;

	if (argc != 2) {
		error_message("Bad input arguments.");
		log_message("Format: harlFilter <level>");
		return (1);
	}

	harl.complain(argv[1]);

	return (0);
}
