#include "BitcoinExchange.hpp"


int main(int arc, char **arv)
{
	try
	{
		if (arc != 2)
			throw std::invalid_argument("There should be only two arguments.");
		BitcoinExchange BitcoinEx(arv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
