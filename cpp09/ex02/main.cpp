#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pmerge(argc, argv);
		//deque
		pmerge.exec();
		

		//print
		pmerge.print_value();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}