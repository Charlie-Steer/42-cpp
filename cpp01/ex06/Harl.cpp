#include "Harl.hpp"
#include <cctype>
#include <iostream>
#include <string>

static void log(std::string message) {
	std::cout << message << "\n";
}

void Harl::debug(void) {
	log("[ DEBUG ]\nThis is a DEBUG message.\n");
}

void Harl::info(void) {
	log("[ INFO ]\nThis is an INFO message.\n");
}

void Harl::warning(void) {
	log("[ WARNING ]\nThis is a WARNING message.\n");
}

void Harl::error(void) {
	log("[ ERROR ]\nThis is an ERROR message.\n");
}

static void make_string_lowercase(std::string &s) {
	for (std::string::size_type i = 0; i < s.length(); i++) {
		s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
	}
}

enum level {
	LEVEL_INVALID,
	LEVEL_DEBUG,
	LEVEL_INFO,
	LEVEL_WARNING,
	LEVEL_ERROR,
};

enum level parse_level_string(std::string s) {
	make_string_lowercase(s);

	if (s == "debug")
		return LEVEL_DEBUG;
	else if (s == "info")
		return LEVEL_INFO;
	else if (s == "warning")
		return LEVEL_WARNING;
	else if (s == "error")
		return LEVEL_ERROR;
	else
		return LEVEL_INVALID;
}

void Harl::complain(std::string level_string) {
	enum level level = parse_level_string(level_string);

	switch (level) {
	case LEVEL_DEBUG:
		debug();
		// fallthrough
	case LEVEL_INFO:
		info();
		// fallthrough
	case LEVEL_WARNING:
		warning();
		// fallthrough
	case LEVEL_ERROR:
		error();
		break;
	default:
		log("[ Harl has nothing to complain about. ]");
	}
}
