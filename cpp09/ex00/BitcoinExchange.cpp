#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char **argv)
{
	std::string fileName(argv[1]);
	size_t		pos;
	std::string ext = ".txt";

	_infileName = argv[1];
	_infile.open(argv[1]);
	if (!this->_infile.is_open())
		throw std::invalid_argument("Error: second arg should be a valid file.");
	this->_data.open("data.csv");
	if (!this->_data.is_open())
		throw std::invalid_argument("Error : cannot open data.csv file.");
	pos = fileName.find(ext);
	if (pos != fileName.size() - ext.size())
		throw std::invalid_argument("Error: the file name must finish with '.txt'");
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
		this->_infile.open(src._infileName.c_str());
		if (!this->_infile.is_open())
			throw std::invalid_argument("Error: src's file should be valid.");
		this->_infileName = src._infileName;
		this->value_csv = src.value_csv;
		this->value_txt = src.value_txt;
	}
	return (*this);
}

static void pars_date(std::string &line, std::string final_sep, std::vector<std::vector<std::string> > &value)
{
	size_t						pos1;
	size_t						pos2;
	std::vector<std::string>	array;

	pos1 = line.find('-');
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input");
	array.push_back(line.substr(0, pos1));
	pos2 = line.find('-', pos1 + 1);
	if (pos2 == std::string::npos)
		throw std::invalid_argument("Error: bad input");
	array.push_back(line.substr(pos1 + 1, pos2 - pos1 - 1));
	pos1 = pos2;
	pos2 = line.find(final_sep, pos1 + 1);
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input");
	array.push_back(line.substr(pos1 + 1, pos2 - pos1 - 1));
	for (int i = 0; array[0][i]; i++)
		if (!std::isdigit(array[0][i]))
			throw std::invalid_argument("Error: bad input");
	for (int i = 0; array[1][i]; i++)
		if (!std::isdigit(array[1][i]))
			throw std::invalid_argument("Error: bad input");
	for (int i = 0; array[2][i]; i++)
		if (!std::isdigit(array[2][i]))
			throw std::invalid_argument("Error: bad input");
	if (std::atoi(array[0].c_str()) < 2000 || std::atoi(array[0].c_str()) > 2025)
		throw std::invalid_argument("Error: bad input: year must be between 2000 and 2025");
	if (std::atoi(array[1].c_str()) < 1 || std::atoi(array[1].c_str()) > 12)
		throw std::invalid_argument("Error: bad input: month must be between 1 and 12");
	if (std::atoi(array[2].c_str()) < 1 || std::atoi(array[2].c_str()) > 31)
		throw std::invalid_argument("Error: bad input: day must be between 1 and 31");
	value.push_back(array);
}

static void pars_value(std::string &line, std::string final_sep, std::vector<std::vector<std::string> > &value)
{
	size_t	pos1;
	bool	dot = false;

	pos1 = line.find(final_sep);
	if (pos1 == std::string::npos)
		throw std::invalid_argument("Error: bad input");
	value.back().push_back(line.substr(pos1 + final_sep.size(), line.size() - pos1 - 1));
	if (std::strtod(value.back()[3].c_str(), NULL) < 0.0)
		throw std::invalid_argument("Error: not a positive number.");
	if (std::strtod(value.back()[3].c_str(), NULL) > 1000 && final_sep == " | ")
		throw std::invalid_argument("Error: too large a number");
	if ((std::strtod(value.back()[3].c_str(), NULL) > 2147483647 ||  std::strtod(value.back()[3].c_str(), NULL) < -2147483648) && final_sep == ",")
		throw std::invalid_argument("Error: number out of range");
	for (size_t i = 0; value.back()[3][i]; i++)
	{
		if (!std::isdigit(value.back()[3][i]))
		{
			if (value.back()[3][i] == '.' && dot == false && i != 0 && i != value.back()[3].size() - 1)
				dot = true;
			else
				throw std::invalid_argument("Error: bad input");
		}
	}
}

void	BitcoinExchange::find_bitcoin_value(std::vector<std::string> &valueTxt)
{
	int i = 0;
	std::vector<std::vector<std::string> >::iterator it = this->value_csv.begin();

	while (it !=  this->value_csv.end() && std::atoi((*it)[0].c_str()) <= std::atoi(valueTxt[0].c_str())) // We get the year of the first line of data.csv, and the year of the current txt.
	{
		if (std::atoi((*it)[0].c_str()) == std::atoi(valueTxt[0].c_str()) &&
			std::atoi((*it)[1].c_str()) > std::atoi(valueTxt[1].c_str()))
		{
			it--;
			std::cout << valueTxt[0] + "-" + valueTxt[1] + "-" + valueTxt[2] + " => " +	valueTxt[3] + " = " << std::strtof(valueTxt[3].c_str(), NULL) * std::strtof((*it)[3].c_str(), NULL) << std::endl;
			return;
		}
		if (std::atoi((*it)[0].c_str()) == std::atoi(valueTxt[0].c_str()) &&
			std::atoi((*it)[1].c_str()) == std::atoi(valueTxt[1].c_str()) &&
			std::atoi((*it)[2].c_str()) > std::atoi(valueTxt[2].c_str()))
		{
			it--;
			std::cout << valueTxt[0] + "-" + valueTxt[1] + "-" + valueTxt[2] + " => " +	valueTxt[3] + " = " << std::strtof(valueTxt[3].c_str(), NULL) * std::strtof((*it)[3].c_str(), NULL) << std::endl;
			return;
		}
		it++;
		i++;
	}
	it--;
	if (i > 1 && std::atoi(valueTxt[0].c_str()) < std::atoi((*it)[0].c_str())) // if the date is too small compared to the database
		std::cout << valueTxt[0] + "-" + valueTxt[1] + "-" + valueTxt[2] + " => " +	valueTxt[3] + " = " << "0" << std::endl;
	else if (i)
		std::cout << valueTxt[0] + "-" + valueTxt[1] + "-" + valueTxt[2] + " => " +	valueTxt[3] + " = " << std::strtof(valueTxt[3].c_str(), NULL) * std::strtof((*it)[3].c_str(), NULL) << std::endl; // we print the result
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
			pars_date(line_data, ",", this->value_csv); // parse the date of data.csv
			pars_value(line_data, ",", this->value_csv);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in data.csv" << '\n';
		return;
	}
	while (std::getline(this->_infile, line))
	{
		this->value_txt.clear();
		if (first_line == true)
		{
			if (line != "date | value")
				throw std::invalid_argument("Error: first line should be : 'date | value' for the given file.");
			std::cout << line << std::endl;
			first_line = false;
			continue;
		}
		try
		{
			pars_date(line, " |", this->value_txt);
			pars_value(line, " | ", this->value_txt);
			find_bitcoin_value(this->value_txt.back());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return;
		}
	}
	if (first_line == true)
		throw std::invalid_argument("Error: no line to read in file given.");
}
