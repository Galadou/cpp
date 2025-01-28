#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Constructor of AAnimal called" << std::endl;
	return;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor of AAnimal called." << std::endl;
	return;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "Copy constructor of AAnimal called." << std::endl;
	*this = src;
}

AAnimal	&AAnimal::operator=(const AAnimal &src)
{
	std::cout << "Copy assignment of AAnimal operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	AAnimal::makeSound() const
{
	return ;
}

const std::string	&AAnimal::getType() const
{
	return (this->_type);
}
