#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange(int argc, char **argv);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange &src);
		BitcoinExchange &operator=(BitcoinExchange &src);

		void	parsing(int arc);
	
	private:
		BitcoinExchange();
		std::ifstream _infile;
};

#endif