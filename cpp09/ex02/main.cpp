#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pmerge(argc, argv);
		pmerge.exec();
		pmerge.print_value(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}