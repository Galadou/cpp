#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange(char **argv);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange &src);
		BitcoinExchange &operator=(BitcoinExchange &src);
		void	parsing_file(char **arv);
		//void	data_parsing();

		void	exec();

	private:
		BitcoinExchange();
		std::ifstream _infile;
		std::ifstream _data;

		//infile.txt
		std::string _yearTxt;
		std::string _monthTxt;
		std::string _dayTxt;
		std::string _valueTxt;

		std::string _yearCsv;
		std::string _monthCsv;
		std::string _dayCsv;
		std::string _valueCsv;

};

#endif