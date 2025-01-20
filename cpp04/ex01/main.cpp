
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include "Brain.hpp"

int main()
{
	int nb = 2;
	Animal	*animal[2] = {new Dog(), new Cat()};

	animal[0]->ideas[0] = "salut";
	animal[1]->ideas[0] = "coucou";

	std::cout << animal[0]->ideas[0] << std::endl;
	std::cout << animal[1]->ideas[0] << std::endl;


	for(int i = 0; i < nb; i++)
		delete tab[i];
	return 0;
}