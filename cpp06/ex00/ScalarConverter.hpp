#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter& operator=(ScalarConverter const &src);

	public:
		static void	convert(std::string str);
};

#endif