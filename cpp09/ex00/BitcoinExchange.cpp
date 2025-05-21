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
		this->value_csv = src.value_csv;
		this->value_txt = src.value_txt;
		this->date = src.date;
	}
	return (*this);
}

static void pars_date(std::string &line, std::string final_sep, std::string &date)
{
	size_t						pos1;
	size_t						pos2;
	std::string					year;
	std::string					month;
	std::string					day;

	pos1 = line.find('-');
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input, no '-' find");
	year = line.substr(0, pos1);
	if (std::atoi(year.c_str()) < 2000 || std::atoi(year.c_str()) > 2025)
		throw std::invalid_argument("Error: bad input: year must be between 2000 and 2025");

	pos2 = line.find('-', pos1 + 1);
	if (pos2 == std::string::npos)
		throw std::invalid_argument("Error: bad input, no '-' find");
	month = line.substr(pos1 + 1, pos2 - pos1 - 1);
	if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
		throw std::invalid_argument("Error: bad input: month must be between 1 and 12");

	pos1 = pos2;
	pos2 = line.find(final_sep, pos1 + 1);
	if (pos2 == std::string::npos)
		throw std::invalid_argument("Error: bad input, no separator find");
	day = line.substr(pos1 + 1, pos2 - pos1 - 1);
	if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
		throw std::invalid_argument("Error: bad input: day must be between 1 and 31");

	for (int i = 0; year[i]; i++)
		if (!std::isdigit(year[i]))
			throw std::invalid_argument("Error: bad input from year");
	for (int i = 0; month[i]; i++)
		if (!std::isdigit(month[i]))
			throw std::invalid_argument("Error: bad input from month");
	for (int i = 0; day[i]; i++)
		if (!std::isdigit(day[i]))
			throw std::invalid_argument("Error: bad input from day");
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
		throw std::invalid_argument("Error: not a positive number.");
	if (value[date] > 1000 && final_sep == " | ")
		throw std::invalid_argument("Error: too large a number");
	if ((value[date] > 2147483647 ||  value[date] < -2147483648) && final_sep == ",")
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
	std::map<std::string, double>::iterator it_txt = this->value_txt.begin();
	while (it_txt != this->value_txt.end())
	{
		std::map<std::string, double>::iterator it_csv = this->value_csv.begin();
		
		while (it_csv != this->value_csv.end())
		{
			if (it_csv->first == it_txt->first)
			{
				std::cout << it_txt->first << " => " << it_txt->second << " = " << it_txt->second * it_csv->second << std::endl;
				break;
			}
			else if (it_csv->first > it_txt->first)
			{
				if (it_csv != this->value_csv.begin())
				{
					it_csv--;
					std::cout << it_txt->first << " => " << it_txt->second << " = " << it_txt->second * it_csv->second << std::endl;
				}
				else
					std::cout << it_txt->first << " => " << it_txt->second << " = " << 0.0 << std::endl;
				break;
			}
			else 
				it_csv++;
		}
		it_txt++;
	}
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
			pars_value(line_data, ",", this->value_csv, this->date);
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
			pars_value(line, " | ", this->value_txt, this->date);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " in the given file." << std::endl;
			return;
		}
	}
	try
	{
		find_bitcoin_value();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	if (first_line == true)
		throw std::invalid_argument("Error: no line to read in file given.");
}
