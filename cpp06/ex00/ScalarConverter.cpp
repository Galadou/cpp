
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return (*this);
}

void	convertToChar(std::string str)
{
	char result;
	double doubleresult;
	float floatresult;
	double buf;

	if (str.find('.') != std::string::npos)
	{
		doubleresult = std::atof(str.c_str());
		if (doubleresult > 2147483647 || doubleresult < -2147483648)
		{
			std::cout << "char: impossible" << std::endl;
			return;
		}
		floatresult = std::atof(str.c_str());
		buf = doubleresult - floatresult;
		if (buf)
			result = static_cast<char>(doubleresult);
		else
			result = static_cast<char>(floatresult);
	}
	else if (str.size() > 1)
		result = std::atoi(str.c_str());
	else
		result = str[0];
	if (!isascii(static_cast<int>(result)))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(result))
		std::cout << "char: '" << result << "'" << std::endl;
	else if (isascii(static_cast<int>(result)))
		std::cout << "char: Non displayable" << std::endl;
}

void	convertToInt(std::string str)
{
	long long int result;
	double doubleresult;
	float floatresult;
	double buf;

	if (str.find('.') != std::string::npos)
	{
		doubleresult = std::atof(str.c_str());
		if (doubleresult > 2147483647 || doubleresult < -2147483648)
		{
			std::cout << "int: impossible" << std::endl;
			return;
		}
		floatresult = std::atof(str.c_str());
		buf = doubleresult - floatresult;
		if (buf)
			result = static_cast<int>(doubleresult);
		else
			result = static_cast<int>(floatresult);
	}
	else if (str.size() > 1)
		result = std::atol(str.c_str());
	else
		result = str[0];
	if (result > 2147483647 || result < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << result << std::endl;
}


void	convertToFloat(std::string str)
{
	float result;
	double buf;
	double resultdouble;
	long long int nb;

	float float_min = std::numeric_limits<float>::min();
	float float_max = std::numeric_limits<float>::max();

	nb = std::atol(str.c_str());
	result = std::atof(str.c_str()); //on recup le float
	if (isascii(str[0]) && str.size() == 1)
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	else if (str.find('.') != std::string::npos)
	{
		resultdouble = std::atof(str.c_str());
		if (resultdouble < float_min || result > float_max)
		{
			std::cout << "float: impossible" << std::endl;
			return;
		}
		buf = resultdouble - result;
		if (buf) //if buf exist, it's a double, otherwise it's a float
		{
			result = static_cast<float>(resultdouble);
			std::cout << "float: " << result << 'f' << std::endl;
		}
		else
		{
			buf = resultdouble - nb;
			if (buf)
				std::cout << "float: " << result << 'f' << std::endl;
			else
				std::cout << "float: " << result << ".0f" << std::endl;
		}
	}
	else
		std::cout << "float: " << result << ".0f" << std::endl;
}

//truc pas precis quon met dans truc precis == promotion cast

void	convertToDouble(std::string str)
{
	double result;
	float floatresult;
	double buf;
	char *endptr;
	long long int nb;

	double double_min = std::numeric_limits<double>::min();
	double double_max = std::numeric_limits<double>::max();

	nb = std::atol(str.c_str());
	//if it's a char at the beggining
	result = std::strtod(str.c_str(), &endptr);
	if (result < double_min || result > double_max)
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (isascii(str[0]) && str.size() == 1)
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
	else if (str.find('.') != std::string::npos)
	{
		floatresult = std::atof(str.c_str()); //on recup le float
		buf = result - floatresult;
		if (buf) //if buf exist, it's a double, otherwise it's a float
			std::cout /*<< std::fixed << std::setprecision(10)*/ << "double: " << result << std::endl;
		else
		{
			buf = result - nb;
			result = static_cast<double>(floatresult);
			if (buf)
				std::cout << "double: " << result << std::endl;
			else
				std::cout << "double: " << result << ".0" << std::endl;
		}
	}
	else
		std::cout << "double: " << result << ".0" << std::endl;
}

static bool	isInfNan(std::string &str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}
	return (false);
}

void	ScalarConverter::convert(std::string str)
{
		if (isInfNan(str))
			return;
		convertToChar(str);
		convertToInt(str);
		convertToFloat(str);
		convertToDouble(str);
}