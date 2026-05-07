#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: Wrong number of arguments." << std::endl;
		return 1;
	}

	RPN rpn;
	int result = 0;
	bool ok = rpn.compute_expression(argv[1], &result);
	if (!ok) {
		return 1;
	} else {
		std::cout << result << std::endl;
		return 0;
	}
}
