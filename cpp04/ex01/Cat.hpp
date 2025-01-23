#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat(Cat const &cpy);
		Cat	&operator=(Cat const &src);

		void	makeSound() const;
		Brain	*getBrain() const;
		void	setBrain(const Brain &newBrain);
	private:
		Brain *_Brain;
};

#endif