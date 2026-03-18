#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

Base *generate(void) {
	int value = std::rand();
	if (value % 3 == 0) {
		return new A;
	} else if (value % 3 == 1) {
		return new B;
	} else {
		return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A\n";
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "B\n";
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "C\n";
	} else {
		std::cout << "Unknown\n";
	}
}

void identify(Base& p) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A\n";
		return;
	} catch (const std::exception &e) {}

	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B\n";
		return;
	} catch (const std::exception& e) {}

	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C\n";
		return;
	} catch (const std::exception &e) {}

	std::cout << "Unknown\n";
}

int main(void) {
	// 1. Seed the random generator using the current time
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "--- Starting Identification Tests ---" << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << "Test #" << i + 1 << ":" << std::endl;

		// 2. Generate a random instance (A, B, or C) as a Base pointer
		Base* instance = generate();

		// 3. Test identification by pointer
		std::cout << "Identify by pointer:   ";
		identify(instance);

		// 4. Test identification by reference
		std::cout << "Identify by reference: ";
		identify(*instance);

		std::cout << "------------------------------------" << std::endl;

		// 5. Clean up heap memory to avoid leaks
		delete instance;
	}

	// 6. Test with a NULL pointer (Edge case for identify(Base* p))
	std::cout << "Test with NULL pointer:" << std::endl;
	identify(NULL);

	return 0;
}
