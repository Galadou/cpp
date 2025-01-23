#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Constructor of Cat called" << std::endl;
	this->_type = "Cat";
	this->_Brain = new Brain();
	return;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called." << std::endl;
	delete this->_Brain;
	return;
}

Cat::Cat(Cat const &src)
{
	std::cout << "Copy constructor of Cat called." << std::endl;
	*this = src;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << "Copy assignment of Cat operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->_Brain);
}

void	Cat::setBrain(const Brain newBrain)
{
	delete this->_Brain;
	this->_Brain = Brain(newBrain);
}