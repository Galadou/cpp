#include "Array.hpp"

int main(void)
{
	std::cout << std::endl;

	//test with int
	{
		unsigned int n = 5;
		
		try
		{
			Array<int> array(n);
			//Here I am testing to print a case (works) and to modify a case.
			std::cout << "Ancienne valeur de la case 0: " << array[0] << std::endl;
			array[0] = 3;
			std::cout << "Nouvelle valeur apres l'avoir modifié: " << array[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}
		
	}
	std::cout << std::endl;

	//I test with std::string
	{
		unsigned int n = 2;
		try
		{
			Array<std::string> array(n);
			//Here I am testing to print a case (works) and to modify a case.
			std::cout << "Ancienne valeur de la case 0: " << array[0] << std::endl;
			array[0] = "salut";
			std::cout << "Nouvelle valeur apres l'avoir modifié: " << array[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}
	}
	std::cout << std::endl;

	//I test with an index error
	{
		unsigned int n = 2;
		try
		{
			Array<std::string> array(n);
			//Here, I test to print a case too far (doesn't work)
			std::cout << "Ancienne valeur de la case 0: " << array[50] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}
	}
	std::cout << std::endl;
	return (0);
}