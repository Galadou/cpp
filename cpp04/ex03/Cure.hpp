#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure	&operator=(Cure const &src);
		Cure(Cure const &cpy);

		AMateria* clone() const;

		void use(ICharacter& target);
};
 
#endif