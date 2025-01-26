#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : AMateria
{
	protected:
		const std::string _type = "ice";
	public:
		Ice();
		~Ice();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
 
#endif;