#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	return;
}
Cure::~Cure()
{
	return;
}

Cure::Cure(Cure const &src)
{
	std::cout << "Copy constructor of Cure called." << std::endl;
	*this = src;
}

Cure	&Cure::operator=(const Cure &src)
{
	std::cout << "Copy assignment of Cure operator called" << std::endl;
	(void)src;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

