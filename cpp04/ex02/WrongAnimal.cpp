#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Constructor of WrongAnimal called" << std::endl;
	return;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called." << std::endl << std::endl;
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "Copy constructor of WrongAnimal called." << std::endl;
	*this = src;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Copy assignment of WrongAnimal operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WROOOOONG" << std::endl;
}

const std::string	&WrongAnimal::getType() const
{
	return (this->_type);
}
