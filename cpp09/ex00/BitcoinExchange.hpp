#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(char **argv);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange &src);
		BitcoinExchange &operator=(BitcoinExchange &src);
		void	find_bitcoin_value();

		void	exec();

	private:
		BitcoinExchange();
		std::ifstream	_infile;
		std::string		_infileName;
		std::ifstream	_data;

		std::string		date;

		std::map<std::string, double> value_given;
		std::map<std::string, double> value_data;


};

#endif