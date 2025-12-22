#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void error_message(std::string message) {
	std::cerr << "Error: " << message << "\n";
}

void warn(std::string message) {
	std::cerr << "Warning: " << message << "\n";
}

void log_message(std::string message) {
	std::cout << message << "\n";
}

void log_format() {
	log_message("Format: sedlike <filename> <s1> <s2>");
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		error_message("Bad input arguments.");
		log_format();
		return (1);
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1 == "") {
		error_message("<s1> must not be empty.");
		log_format();
		return (1);
	}

	std::ifstream input(argv[1]);
	if (!input.is_open()) {
		error_message("Couldn't open input file.");
		return (1);
	}

	std::ostringstream buffer;
	buffer << input.rdbuf();
	std::string input_string = buffer.str();

	if (input_string.length() == 0) {
		warn("Input file is empty.");
	}

	std::string output_filename = std::string(argv[1]) + ".replace";
	std::ofstream output(output_filename.c_str());

	if (!output.is_open()) {
		error_message("Couldn't create output file.");
		return (1);
	}

	std::string output_string;
	size_t cursor = 0;
	while (true) {
		size_t occurrence_idx = input_string.find(s1, cursor);
		if (occurrence_idx == std::string::npos) {
			output_string.append(input_string, cursor, std::string::npos);
			break;
		} else {
			output_string.append(input_string, cursor, occurrence_idx - cursor);
			output_string.append(s2);
		}
		cursor = occurrence_idx + s1.length();
	}

	output << output_string;

	input.close();
	output.close();

	log_message("Replacement complete.");
}
