#include "RPN.hpp"


//? Dont forget to enclose the '*' operator in quotes
int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Error: Not enought param.");
		if (argc > 99)
			throw std::invalid_argument("Error: too much param.");
		RPN rpn;
		rpn.parsing(argv);
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}