#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	return;
}
Ice::~Ice()
{
	return;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
	*this = src;
}

Ice	&Ice::operator=(const Ice &src)
{
	(void)src;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
