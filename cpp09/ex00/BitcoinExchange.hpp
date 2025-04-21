#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

class BitcoinExchange
{
	public:
		BitcoinExchange(char **argv);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange &src);
		BitcoinExchange &operator=(BitcoinExchange &src);
		//void	data_parsing();
		void	find_bitcoin_value(std::vector<std::string> &valueTxt);

		void	exec();

	private:
		BitcoinExchange();
		std::ifstream	_infile;
		std::string		_infileName;
		std::ifstream	_data;

		std::vector<std::vector<std::string> > value_csv;
		std::vector<std::vector<std::string> > value_txt;


};

#endif