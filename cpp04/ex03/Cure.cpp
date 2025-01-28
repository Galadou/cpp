#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	return;
}
Cure::~Cure()
{
	return;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
	*this = src;
}

Cure	&Cure::operator=(const Cure &src)
{
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

