#include <iostream>
#include <string>

int main(void) {
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	// memory addresses.
	std::cout << &s << "\n";
	std::cout << stringPTR << "\n";
	std::cout << &stringREF << "\n";

	// value.
	std::cout << s << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << "\n";

	return (0);
}
