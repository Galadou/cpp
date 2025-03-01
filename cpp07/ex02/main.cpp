#include "Array.hpp"

int main(void)
{
	std::cout << std::endl;
	//test avec int
	{
		unsigned int n = 5;
		Array<int> array(n);
		
		try
		{
			//Ici, je test de print une case (fonctionne) et de modifié une case.
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

	//je test avec des std::string
	{
		unsigned int n = 2;
		Array<std::string> array(n);
		try
		{
			//Ici, je test de print une case (fonctionne) et de modifié une case.
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

	//je test avec une erreur d'index
	{
		unsigned int n = 2;
		Array<std::string> array(n);
		try
		{
			//Ici, je test de print une case trop loin (ne fonctionne pas)
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