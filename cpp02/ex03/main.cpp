#include "Point.hpp"
#include <iostream>

static void test_case(const char *label, Point const &a, Point const &b, Point const &c, Point const &p,
					  bool expected) {
	bool result = bsp(a, b, c, p);

	std::cout << label << ": ";
	if (result == expected)
		std::cout << "OK";
	else
		std::cout << "FAIL";

	std::cout << " (expected=" << expected << ", got=" << result << ")\n";
}

int main() {
	// Simple right triangle
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);

	// Inside
	test_case("Inside point", a, b, c, Point(1.0f, 1.0f), true);

	// Outside
	test_case("Outside point", a, b, c, Point(5.0f, 5.0f), false);

	// On edge AB
	test_case("On edge AB", a, b, c, Point(2.5f, 0.0f), false);

	// On vertex A
	test_case("On vertex A", a, b, c, Point(0.0f, 0.0f), false);

	// Near edge but inside
	test_case("Near edge inside", a, b, c, Point(0.1f, 0.1f), true);

	// Reversed winding (CW instead of CCW)
	test_case("Reversed winding", a, c, b, Point(1.0f, 1.0f), true);

	// Negative coordinates
	Point d(-5.0f, -5.0f);
	Point e(5.0f, -5.0f);
	Point f(0.0f, 5.0f);

	test_case("Negative coordinates inside", d, e, f, Point(0.0f, -1.0f), true);

	test_case("Negative coordinates outside", d, e, f, Point(0.0f, -6.0f), false);

	return 0;
}
