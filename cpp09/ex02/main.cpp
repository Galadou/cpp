#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pmerge(argc, argv);
		pmerge.stock_deque_to_pair();
		pmerge.sort_bigger();
		pmerge.sort_smaller();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}