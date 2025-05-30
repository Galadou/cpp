#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char **argv)
{
	std::string fileName(argv[1]);

	_infileName = argv[1];
	_infile.open(argv[1]);
	if (!this->_infile.is_open())
		throw std::invalid_argument("Error: second arg should be a valid file.");
	this->_data.open("data.csv");
	if (!this->_data.is_open())
		throw std::invalid_argument("Error : cannot open data.csv file.");
}

BitcoinExchange::~BitcoinExchange()
{
	if (this->_infile.is_open())
		this->_infile.close();
	if (this->_data.is_open())
		this->_data.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src)
{
	if (&src != this)
		*this = src;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &src)
{
	if (&src != this)
	{
		if (this->_infile.is_open())
			this->_infile.close();
		this->_infile.open(src._infileName.c_str());                     
		if (!this->_infile.is_open())
			throw std::invalid_argument("Error: src's file should be valid.");
		this->_infileName = src._infileName;
		this->value_data = src.value_data;
		this->value_given = src.value_given;
		this->date = src.date;
	}
	return (*this);
}

static void pars_date(std::string &line, std::string final_sep, std::string &date)
{
	size_t			pos1;
	size_t			pos2;
	std::string		year;
	std::string		month;
	std::string		day;

	pos1 = line.find('-');
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input, no '-' find");
	year = line.substr(0, pos1);
	pos2 = line.find('-', pos1 + 1);
	if (pos2 == std::string::npos)
		throw std::invalid_argument("Error: bad input, no '-' find");
	month = line.substr(pos1 + 1, pos2 - pos1 - 1);
	pos1 = pos2;
	pos2 = line.find(final_sep, pos1 + 1);
	if (pos2 == std::string::npos)
		throw std::invalid_argument("Error: bad input, no separator find");
	day = line.substr(pos1 + 1, pos2 - pos1 - 1);
	
	for (int i = 0; year[i]; i++)
		if (!std::isdigit(year[i]))
			throw std::invalid_argument("Error: bad input from year");
	for (int i = 0; month[i]; i++)
		if (!std::isdigit(month[i]))
			throw std::invalid_argument("Error: bad input from month");
	for (int i = 0; day[i]; i++)
		if (!std::isdigit(day[i]))
			throw std::invalid_argument("Error: bad input from day");
	if (year.size() != 4)
		throw std::invalid_argument("Error: bad input from year");
	if (month.size() != 2)
		throw std::invalid_argument("Error: bad input from month");
	if (day.size() != 2)
		throw std::invalid_argument("Error: bad input from day");

	if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
		throw std::invalid_argument("Error: bad input: day must be between 1 and 31");
	if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
		throw std::invalid_argument("Error: bad input: month must be between 1 and 12");
	if (std::atoi(year.c_str()) < 2000 || std::atoi(year.c_str()) > 2025)
		throw std::invalid_argument("Error: bad input: year must be between 2000 and 2025");

	date = line.substr(0, pos2);
}

static void pars_value(std::string &line, std::string final_sep, std::map<std::string, double> &value, std::string date)
{
	size_t	pos1;
	bool	dot = false;
	std::string bitcoin;

	pos1 = line.find(final_sep);
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input, no separator find");
	bitcoin = line.substr(pos1 + final_sep.size(), line.size() - pos1 - 1);
	value[date] = std::strtod(bitcoin.c_str(), NULL);
	if (value[date] < 0.0)
		throw std::invalid_argument("Error: it's a negative number");
	if ((value[date] > 1000 && final_sep == " | "))
		throw std::invalid_argument("Error: number out of range");
	if ((value[date] > 2147483647))
		throw std::invalid_argument("Error: number out of range");
	for (size_t i = 0; bitcoin[i]; i++)
	{
		if (!std::isdigit(bitcoin[i]))
		{
			if (bitcoin[i] == '.' && dot == false && i != 0 && i != bitcoin.size() - 1)
				dot = true;
			else
				throw std::invalid_argument("Error: bad input");
		}
	}
}

void	BitcoinExchange::find_bitcoin_value()
{
	std::map<std::string, double>::iterator it_data = this->value_data.begin();
	std::map<std::string, double>::iterator it_given = this->value_given.begin();

	it_data = value_data.upper_bound(it_given->first);
	if (it_data != this->value_data.begin())
	{
		it_data--;
		std::cout << it_given->first << " => " << it_given->second << " = " << it_given->second * it_data->second << std::endl;
	}
	else
		std::cout << it_given->first << " => " << it_given->second << " = " << 0.0 << std::endl;
	this->value_given.clear();
}

void	BitcoinExchange::exec()
{
	std::string line;
	std::string line_data;
	bool first_line = true;

	try
	{
		std::getline(this->_data, line_data); //skip first line
		while (std::getline(this->_data, line_data))
		{
			pars_date(line_data, ",", this->date); // parse the date of data.csv
			pars_value(line_data, ",", this->value_data, this->date);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in data.csv." << '\n';
		return;
	}
	while (std::getline(this->_infile, line))
	{
		if (first_line == true)
		{
			if (line != "date | value")
				throw std::invalid_argument("Error: first line should be : 'date | value' for the given file.");
			first_line = false;
			continue;
		}
		try
		{
			pars_date(line, " |", this->date);
			pars_value(line, " | ", this->value_given, this->date);
			find_bitcoin_value();
		}
		catch(const std::exception& e)
		{
			this->value_given.clear();
			std::cerr << e.what() << "." << std::endl;
		}
	}
	if (first_line == true)
		throw std::invalid_argument("Error: no line to read in file given.");
}
