#include "Harl.hpp"

int main(void) {
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");

	harl.complain("err or");
	harl.complain("");

	return (0);
}
