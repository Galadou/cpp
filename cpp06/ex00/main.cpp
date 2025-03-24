#include "ScalarConverter.hpp"

static void	parsing(int argc, char **argv)
{
	std::string str;
	size_t posDot = 0;
	size_t posMinus = 0;
	size_t posF = 0;

	if (argc != 2)
		throw std::invalid_argument("Error: You have to give one param.");
	str = argv[1];
	if (str.empty())
		throw std::invalid_argument("Error: Param is empty.");
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return;
	posDot = str.find('.');
	if (posDot != std::string::npos && str.find('.', posDot + 1) != std::string::npos)
		throw std::invalid_argument("Error: You cannot give multiple dot.");
	if (posDot != 0 && posDot != std::string::npos && (posDot == str.size() || !isdigit(str[posDot + 1])))
		throw std::invalid_argument("Error: ivalid param.");
	if (str.size() > 1 && ((str[0] != '-' && !std::isdigit(str[0])) || (str[0] == '-' && !std::isdigit(str[1]))))
		throw std::invalid_argument("Error: ivalid param.");
	posMinus = str.find('-');
	if (posMinus != std::string::npos && posMinus != 0)
		throw std::invalid_argument("Error: ivalid param.");
	posF = str.find('f');
	if (posF != std::string::npos && posF != str.size() -1)
		throw std::invalid_argument("Error: ivalid param.");
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str.size() > 1 && str[i] != '-' && str[i] != '.' && str[i] != 'f' && !isdigit(str[i]))
			throw std::invalid_argument("Error: ivalid param.");
	}
}

int main(int argc, char **argv)
{
	try
	{
		parsing(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}