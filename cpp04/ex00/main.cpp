#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	const WrongAnimal*	wrong_animal = new WrongAnimal();
	const WrongAnimal*	wrong_cat = new WrongCat();

	std::cout << std::endl;

	std::cout << wrong_cat->getType() << std::endl;
	wrong_cat->makeSound();
	wrong_animal->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	delete wrong_animal;
	delete wrong_cat;

	return 0;
}