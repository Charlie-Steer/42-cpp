#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: Wrong number of arguments. Required format: btc FILE" << std::endl;
		return 1;
	}

	BitcoinExchange bitcoin_exchange;

	std::string database_filename("data.csv");
	if (bitcoin_exchange.load_database(database_filename) == 1) {
		return 1;
	}

	std::string input_filename(argv[1]);
	if (bitcoin_exchange.process_input(input_filename) == 1) {
		return 1;
	}

	return 0;
}
