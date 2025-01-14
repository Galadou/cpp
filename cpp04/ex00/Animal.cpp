#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Constructor of Animal called" << std::endl;
	return;
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal called." << std::endl << std::endl;
	return;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Copy constructor of Animal called." << std::endl;
	*this = src;
}

Animal	&Animal::operator=(const Animal &src)
{
	std::cout << "Copy assignment of Animal operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Animal::makeSound() const
{
	return ;
}

const std::string	&Animal::getType() const
{
	return (this->_type);
}
