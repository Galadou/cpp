#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
		AMateria();
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria	&operator=(AMateria const &src);
		AMateria(AMateria const &cpy);

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif