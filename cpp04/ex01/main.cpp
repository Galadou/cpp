
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*animal[2] = {new Dog(), new Cat()};

	animal[0]->makeSound();
	animal[1]->makeSound();
	Cat *Cat1 = new Cat(); // pourquoi allouer ?

	Brain Brain1;
	Brain1.ideas[0] = "salut";
	Cat1->setBrain(Brain1);
	Cat *Cat2(Cat1); // pourquoi allouer ?

	delete Cat1;
	std::cout << Cat2->getBrain()->ideas[0] << std::endl;



	for(int i = 0; i < 2; i++)
		delete animal[i];
	return 0;
}