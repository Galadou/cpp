
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

//truc pas precis quon met dans truc precis == promotion cast

static bool	isPseudoLiterals(std::string &str)
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


//isfinite

static void	convert(std::string &type, char *c, int *i, float *f, double *d)
{
	int id;
	std::string array[4] = {"char", "int", "float", "double"};

	for(id = 0; id < 4; id++)
	{
		if (type == array[id])
			break;
	}
	switch (id)
	{
		case 0 :
			*i = static_cast<long long int>(*c);
			*f = static_cast<float>(*c);
			*d = static_cast<double>(*c);
			break;
		case 1 :
			*c = static_cast<char>(*i);
			*f = static_cast<float>(*i);
			*d = static_cast<double>(*i);
			break;
		case 2 :
			*c = static_cast<char>(*f);
			*d = static_cast<double>(*f);
			*i = static_cast<long long int>(*f);
			break;
		case 3 :
			*c = static_cast<char>(*d);
			*i = static_cast<long long int>(*d);
			*f = static_cast<float>(*d);
			break;
	}
}

static std::string	findType(std::string &str)
{
	long long int nb;
	double d;
	char *endptr;
	double fract;

	nb = std::atol(str.c_str());
	d = std::strtod(str.c_str(), &endptr);
	if (str.size() == 1)
		return ("char");
	else if (str.find('f') != std::string::npos)
		return ("float");
	else if ((std::modf(d, &fract) != 0) || str.find('.') != std::string::npos)
		return ("double");
	else
		return ("int");
}

static void printValue(std::string &str, char *c, int *i, float *f, double *d)
{
	double	d_fract = 0;
	double d_int = 0;
	double max_double = std::numeric_limits<double>::max();
	std::ostringstream oss;
	oss << std::fixed <<  max_double;
	std::ostringstream ossf;
	ossf << *f;
	std::string f_str = ossf.str();
	std::ostringstream ossd;
	ossd << *d;
	std::string d_str = ossd.str();
	char *str_char;
	
	d_fract = std::modf(*d, &d_int);

	//char
	if (!isascii(*i) || (*d > 2147483647 || *d < -2147483648))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(*c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << *c << "\'" << std::endl;
	
	//int
	if (*d > 2147483647 || *d < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << *i << std::endl;

	//float
	if (*f == std::numeric_limits<float>::infinity() || *f == -std::numeric_limits<float>::infinity())
		std::cout << "float: " << *f << 'f' << std::endl;
	else if (d_fract == 0 && f_str.find('.') == std::string::npos)
		std::cout << "float: " << *f  << ".0f" << std::endl;
	else
		std::cout << "float: " << *f  << "f" << std::endl;

	//double
	if (*d == std::numeric_limits<double>::infinity() || *d == -std::numeric_limits<double>::infinity())
		std::cout << "double: " << *d << std::endl;
	else if (d_fract == 0 && str.find('.') == std::string::npos && d_str.find('.') == std::string::npos)
		std::cout << "double: " << *d << ".0" << std::endl;
	else
	{
		if (d_str.find('.') != std::string::npos && (*d > 2147483647 || *d < -2147483648))
			std::cout << "double: " << *d << std::endl;
		else
		{
			if (str.find('f') != std::string::npos)
				str.resize(str.size() - 1);
			str_char = (char *)str.c_str();
			while (str.size() > 1 && str_char[0] == '0' && str_char[1] != '.')
				str_char++;
			std::cout << "double: " << str_char << std::endl;
		}
	}
}

static void exec(std::string &type, std::string &str)
{
	char c = 0;
	long int buf = 0;
	int i = 0;
	float f = 0;
	double d = 0;
	char *endptr;

	if (type == "char")
	{
		c = str[0];
		convert(type, &c, &i, &f, &d);
	}
	else if (type == "int")
	{
		buf = std::atol(str.c_str());
		//std::cout << buf << std::endl;
		if (buf > 2147483647 || buf < -2147483648)
			throw std::invalid_argument("Error: Invalid argument.");
		i = std::atoi(str.c_str());
		convert(type, &c, &i, &f, &d);
	}
	else if (type == "float")
	{
		f = strtof(str.c_str(), &endptr);
		if (*++endptr != '\0')
			throw std::invalid_argument("Error: Invalid argument.");
		convert(type, &c, &i, &f, &d);
	}
	else if (type == "double")
	{
		d = strtod(str.c_str(), &endptr);
		if (*endptr != '\0')
			throw std::invalid_argument("Error: Invalid argument.");
		convert(type, &c, &i, &f, &d);
	}
	printValue(str, &c, &i, &f, &d);
}

void	ScalarConverter::convert(std::string str)
{
	std::string type;

	if (isPseudoLiterals(str))
		return;
	type = findType(str);
	try
	{
		exec(type, str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}