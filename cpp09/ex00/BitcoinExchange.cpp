#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(int argc, char **argv) : _infile(std::ifstream(argv[1]))
{
	parsing(argc);
}
BitcoinExchange::~BitcoinExchange()
{
	if (this->_infile.is_open())
		this->_infile.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src)
{
	if (&src != this)
		*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &src)
{
	if (&src != this)
	{
		if (this->_infile.is_open())
			this->_infile.close();
		std::string fileName;
		src._infile >> fileName;
		std::cout << fileName << std::endl;
		this->_infile.open(fileName);
		if (!this->_infile.is_open())
			throw std::invalid_argument("Second arg should be a valid file.");
	}
}

void	BitcoinExchange::parsing(int arc)
{
	if (arc != 2)
		throw std::invalid_argument("There should be only two arguments.");
	if (!this->_infile.is_open())
		throw std::invalid_argument("Second arg should be a valid file.");

}
