#include <cctype>
#include <iostream>

// TODO: Use locale so Ñs are also uppered.
int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int arg_idx = 1; arg_idx < argc; ++arg_idx) {
			char *arg = argv[arg_idx];
			for (int char_idx = 0; arg[char_idx] != '\0'; ++char_idx) {
				arg[char_idx] = std::toupper(arg[char_idx]);
			}
			std::cout << argv[arg_idx];
		}
		std::cout << std::endl;
	}
}
