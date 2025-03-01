#include <iostream>
#include "ScalarConverter.hpp"

static void	parsing(int argc, char **argv)
{
	std::string str;
	bool point = false;

	if (argc != 2)
		throw std::invalid_argument("Error: You have to give one param.");
	str = argv[1];
	if (str.empty())
		throw std::invalid_argument("Error: Param is empty.");
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return;
	if (!std::isdigit(str[0]) && str[0] != '-' && str.size() > 1)
		throw std::invalid_argument("Error: You cannot give multiple char.");
	if (std::isdigit(str[0]))
	{
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '.')
			{
				if (!str[i+1] || str[i+1] == 'f')
					throw std::invalid_argument("Error: Need more number after a dot.");
				if (point == true)
					throw std::invalid_argument("Error: You cannot give multiple dot.");
				point = true;
			}
			else if (!std::isdigit(str[i]) && (str[i + 1] || str[i] != 'f'))
				throw std::invalid_argument("Error: Digit and char cannot be mixed.");
		}
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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