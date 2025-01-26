
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;

	Animal	*animal[2] = {new Dog(), new Cat()};

	std::cout << std::endl;
	animal[0]->makeSound();
	animal[1]->makeSound();
	std::cout << std::endl;

	for (int i = 0; i < 2; i++)
		delete animal[i];

	return 0;
}