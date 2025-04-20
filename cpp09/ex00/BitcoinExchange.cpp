#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char **argv)
{
	parsing_file(argv);
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

void	BitcoinExchange::parsing_file(char **arv)
{
	std::string fileName(arv[1]);
	size_t		pos;
	std::string ext = ".txt";

	_infile.open(arv[1]);
	if (!this->_infile.is_open())
		throw std::invalid_argument("Second arg should be a valid file.");
	this->_data.open("data.csv");
	if (!this->_data.is_open())
		throw std::invalid_argument("Error on opening data.csv file.");
	pos = fileName.find(ext);
	if (pos != fileName.size() - ext.size())
		throw std::invalid_argument("The file name must finish with '.txt'");
}

void pars_date(std::string &line, std::string final_sep, std::string &year, std::string &month, std::string &day)
{
	size_t pos1;
	size_t pos2;

	pos1 = line.find('-');
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input");
	year = line.substr(0, pos1);

	pos2 = line.find('-', pos1 + 1);
	if (pos2 == std::string::npos)
		throw std::invalid_argument("Error: bad input");
	month = line.substr(pos1 + 1, pos2 - pos1 - 1);
	pos1 = pos2;
	pos2 = line.find(final_sep, pos1 + 1);
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input");
	day = line.substr(pos1 + 1, pos2 - pos1 - 1);

	//debug
	std::cout << "year = " << year << std::endl;
	std::cout << "month = " << month << std::endl;
	std::cout << "day = " << day << std::endl;
	//end of debug

	for (int i = 0; year[i]; i++)
		if (!std::isdigit(year[i]))
			throw std::invalid_argument("Error: bad input");
	for (int i = 0; month[i]; i++)
		if (!std::isdigit(month[i]))
			throw std::invalid_argument("Error: bad input");
	for (int i = 0; day[i]; i++)
		if (!std::isdigit(day[i]))
			throw std::invalid_argument("Error: bad input");
	if (std::atoi(year.c_str()) < 2000 || std::atoi(year.c_str()) > 2025)
		throw std::invalid_argument("Error: bad input: year must be between 2000 and 2025");
	if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
		throw std::invalid_argument("Error: bad input: month must be between 1 and 12");
	if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
		throw std::invalid_argument("Error: bad input: day must be between 1 and 31");
}

static void pars_value(std::string &line, std::string final_sep, std::string &value)
{
	size_t		pos1;
	bool		dot = false;

	pos1 = line.find(final_sep);
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input");
	value = line.substr(pos1 + final_sep.size(), line.size() - pos1 - 1);

	//debug
	std::cout << "value = " << value << std::endl;

	if (std::strtod(value.c_str(), NULL) < 0.0)
		throw std::invalid_argument("Error: not a positive number.");
	for (size_t i = 0; value[i]; i++)
	{
		if (!std::isdigit(value[i]))
		{
			if (value[i] == '.' && dot == false && i != 0 && i != value.size() - 1)
				dot = true;
			else
				throw std::invalid_argument("Error: bad input");
		}
	}
}

void	BitcoinExchange::exec()
{
	std::string line;
	std::string line_data;

	//parsing for data.csv
	try
	{
		std::getline(this->_data, line_data); //skip first line
		/*while */(std::getline(this->_data, line_data));
		//{
			pars_date(line_data, ",", _yearCsv, _monthCsv, _dayCsv); // parse la date du data.csv
			pars_value(line_data, ",", _valueCsv);
		//}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in data.csv" << '\n';
		return;
	}


	//parsing for .txt
	while (std::getline(this->_infile, line))
	{
		try
		{
			pars_date(line, " |", _yearTxt, _monthTxt, _dayTxt);
			pars_value(line, " | ", _valueTxt);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "oui" << std::endl;
	}
}
