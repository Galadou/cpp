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
	this->_Brain = NULL;
	*this = src;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << "Copy assignment of Dog operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	if (this->_Brain)
		delete this->_Brain;
	this->_Brain = new Brain(*(src._Brain));
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "OUAF" << std::endl;
}