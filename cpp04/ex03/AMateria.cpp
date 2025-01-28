#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
}
AMateria::~AMateria()
{
	return;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria	&AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria use on " << target.getName() << std::endl;
}

