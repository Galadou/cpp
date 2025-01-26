#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(WrongAnimal const &cpy);
		WrongAnimal	&operator=(WrongAnimal const &src);

		void	makeSound() const;
		const std::string	&getType() const;

	protected:
		std::string _type;
};

#include "WrongCat.hpp"

#endif