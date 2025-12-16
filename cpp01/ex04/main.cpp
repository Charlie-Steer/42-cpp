#include <fstream>
#include <iostream>

void error(std::string message) {
	std::cerr << "Error: " << message << "\n";
}

void log(std::string message) {
	std::cerr << message << "\n";
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		error("Bad input arguments.");
		log("Format: sedlike <filename> <s1> <s2>");
		return (1);
	}

	std::ifstream input(argv[1]);
	if (!input.is_open()) {
		error("Couldn't open file.");
		return (1);
	}
}
