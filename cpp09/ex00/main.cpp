#include "BitcoinExchange.hpp"


int main(int arc, char **arv)
{
	try
	{
		BitcoinExchange BitcoinEx(arc, arv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}