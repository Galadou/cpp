#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Constructor of Dog called" << std::endl;
	return;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called." << std::endl;
	return;
}

Dog::Dog(Dog const &src)
{
	std::cout << "Copy constructor of Dog called." << std::endl;
	*this = src;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << "Copy assignment of Dog operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "OUAF" << std::endl;
}