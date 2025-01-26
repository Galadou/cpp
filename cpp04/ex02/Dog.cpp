#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Constructor of Dog called" << std::endl;
	this->_type = "Dog";
	this->_Brain = new Brain();
	return;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called." << std::endl;
	delete this->_Brain;
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