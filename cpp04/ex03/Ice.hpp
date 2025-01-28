#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice	&operator=(Ice const &src);
		Ice(Ice const &cpy);

		AMateria* clone() const;
		void use(ICharacter& target);
};
 
#endif