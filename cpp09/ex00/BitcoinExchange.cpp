#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char **argv) 
{
	_infile.open(argv[1]);
	parsing(argv);
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
		this->_infile.open(fileName.c_str());
		if (!this->_infile.is_open())
			throw std::invalid_argument("Second arg should be a valid file.");
	}
	return (*this);
}

void	BitcoinExchange::parsing(char **arv)
{
	std::string fileName(arv[1]);
	size_t		pos;
	std::string ext = ".txt";

	if (!this->_infile.is_open())
		throw std::invalid_argument("Second arg should be a valid file.");
	pos = fileName.find(ext);
	if (pos != fileName.size() - ext.size())
		throw std::invalid_argument("The file name must finish with '.txt'");
}

static void pars_line(std::string &line)
{
	size_t pos;
	std::string year;
	std::string month;
	std::string day;

	pos = line.find('-');
	
}


void	BitcoinExchange::exec()
{
	std::string line;

	while (std::getline(this->_infile, line))
	{
		try
		{
			pars_line(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
}
