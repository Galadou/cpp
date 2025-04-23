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
		my_vector.push_back(nb); //we add 42 to the vector
		easyfind(my_vector, nb);
		std::cout << "The number " << nb << " has been find inside my_vector !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Test that should fail :" << std::endl;
	try
	{
		std::vector<int> my_vector;
		int nb = 42;

		for (int i = 0; i < 5; i++)
			my_vector.push_back(i);
		easyfind(my_vector, nb); //we look for 42 but it is not in the vector
		std::cout << "The number " << nb << " has been find inside my_vector !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}