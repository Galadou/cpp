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

		virtual void	makeSound() const;
	private:
		Brain *_Brain;
};

#endif