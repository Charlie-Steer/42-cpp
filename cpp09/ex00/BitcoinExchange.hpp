#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange &other);
		BitcoinExchange &operator=(BitcoinExchange &other);
		~BitcoinExchange();
};

#endif
