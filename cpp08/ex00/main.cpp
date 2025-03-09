#include "easyfind.hpp"

int main()
{
	std::cout << "For vector of int:" << std::endl;
	try
	{
		std::vector<int> my_vector;
		int nb = 42;

		for (int i = 0; i < 5; i++)
			my_vector.push_back(i);
		my_vector.push_back(nb);
		easyfind(my_vector, nb);
		std::cout << "The number " << nb << " has been find inside my_vector !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}