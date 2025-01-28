#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	public:
		Dog();
		~Dog();
		Dog(Dog const &cpy);
		Dog	&operator=(Dog const &src);

		void	makeSound() const;
	private:
		Brain *_Brain;
};

#endif