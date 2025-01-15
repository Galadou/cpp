#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog const &cpy);
		Dog	&operator=(Dog const &src);

		virtual void	makeSound() const;
};

#endif