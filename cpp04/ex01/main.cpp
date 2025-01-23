
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int nb = 2;
	Animal	*animal[nb]; //= {new Dog(), new Cat()};
	Cat *Cat1 = new Cat();
	animal[0] = Cat1;

	//animal[0]->ideas[0] = "salut";
	Brain Brain1;
	Brain1.ideas[0] = "coucou";
	Brain1.ideas[1] = "Salut";
	Cat1->setBrain(Brain1);
	
	//animal[1]->ideas[0] = "coucou";

	std::cout << Cat1->getBrain()->ideas[0] << std::endl;
	//std::cout << animal[0]->getBrain() << std::endl;
	//std::cout << animal[1]->ideas[0] << std::endl;


	for(int i = 0; i < nb; i++)
		delete animal[i];
	return 0;
}