#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define SIZE 10 

int main()
{
	Animal	*animal[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		if (i % 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	std::cout << std::endl;
	for (int i = 0; i < SIZE; i++)
		animal[i]->makeSound();
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		delete animal[i];

	return 0;
}