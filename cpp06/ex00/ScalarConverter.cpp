#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits>

void print_error(const std::string &message) {
	std::cerr << message << std::endl;
}

void print(const std::string &message) {
	std::cout << message;
}

void print_line(const std::string &message) {
	std::cout << message << "\n";
}

bool check_if_inf_or_nan_float(const std::string &input) {
	if (input == "nanf" || input == "+inff" || input == "-inff") {
		return true;
	} else {
		return false;
	}
}

bool check_if_inf_or_nan_double(const std::string &input) {
	if (input == "nan" || input == "+inf" || input == "-inf") {
		return true;
	} else {
		return false;
	}
}

bool check_if_inf_or_nan(const std::string &input) {
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff") {
		return true;
	} else {
		return false;
	}
}

static void convert_float_literal(const std::string &input) {
	char *end = NULL;
	float f = std::strtof(input.c_str(), &end);
	if (end[0] == 'f' && end[1] == '\0') {
		std::cout << "char: impossible\n" << "int: impossible\n";

		if (f == std::numeric_limits<float>::infinity()) {
			std::cout << "float: +" << f << "f\ndouble: +" << static_cast<double>(f) << "\n";
		} else {
			std::cout << "float: " << f << "f\ndouble: " << static_cast<double>(f) << "\n";
		}
	} else {
		print_error("Error: Float parsing error.");
		return;
	}
}

static void convert_double_literal(const std::string &input) {
	char *end = NULL;
	double d = std::strtod(input.c_str(), &end);
	if (*end != '\0') {
		print_error("Error: Double parsing error.");
		return;
	}

	std::cout << "char: impossible\n" << "int: impossible\n";

	if (d == std::numeric_limits<double>::infinity()) {
		std::cout << "float: +" << d << "f\ndouble: +" << static_cast<double>(d) << "\n";
	} else {
		std::cout << "float: " << d << "f\ndouble: " << static_cast<double>(d) << "\n";
	}
}

static void output_results(double value) {
	std::cout << "char: ";
	if (value < 0 || value > 127) {
		std::cout << "impossible\n";
	} else if (!isprint(static_cast<int>(value))) {
		std::cout << "Non displayable\n";
	} else {
		std::cout << "\'" << static_cast<char>(value) << "\'" << "\n";
	}

	long l = static_cast<long>(value);
	std::cout << "int: ";
	if (l < INT_MIN || l > INT_MAX || value != value) {
		std::cout << "impossible\n";
	} else {
		std::cout << static_cast<int>(value) << "\n";
	}

	if (value > 1000000.0 || value < -1000000.0) {
		std::cout << "float: " << value << "f\ndouble: " << static_cast<double>(value) << "\n";
	} else if (value == static_cast<double>(l)) {
		std::cout << "float: " << value << ".0f\ndouble: " << static_cast<double>(value) << ".0\n";
	} else {
		std::cout << "float: " << value << "f\ndouble: " << static_cast<double>(value) << "\n";
	}
}

static void convert_char(const std::string &input) {
	char c = input[0];
	output_results(static_cast<double>(c));
}

static void convert_int(const std::string &input) {
	char *end = NULL;
	long l = std::strtol(input.c_str(), &end, 10);
	if (*end != '\0') {
		print_error("Error: Integer parsing error.");
		return;
	}

	output_results(static_cast<double>(l));
}

static void convert_float(const std::string &input) {
	char *end = NULL;
	float value = std::strtof(input.c_str(), &end);
	if (end[0] == 'f' && end[1] == '\0') {
		output_results(static_cast<double>(value));
	} else {
		print_error("Error: Float parsing error.");
		return;
	}
}

static void convert_double(const std::string &input) {
	char *end = NULL;
	float value = std::strtod(input.c_str(), &end);
	if (*end != '\0') {
		print_error("Error: Double parsing error.");
		return;
	}

	output_results(value);
}

void ScalarConverter::convert(const std::string &input) {
	if (input.empty()) {
		std::cerr << "Error: Bad input.";
		return;
	}

	if (input.length() == 1 && !(input.c_str()[0] >= '0' && input.c_str()[0] <= '9')) {
		convert_char(input);
	} else if (check_if_inf_or_nan_float(input)) {
		convert_float_literal(input);
	} else if (check_if_inf_or_nan_double(input)) {
		convert_double_literal(input);
	}else if (input.find('.') != std::string::npos) {
		if (input.c_str()[input.length() - 1] == 'f') {
			convert_float(input);
		} else {
			convert_double(input);
		}
	} else {
		convert_int(input);
	}
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}
