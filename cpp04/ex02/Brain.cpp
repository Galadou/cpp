#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor of Brain called" << std::endl;
	return;
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called." << std::endl;
	return;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Copy constructor of Brain called." << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &src)
{
	std::cout << "Copy assignment of Brain operator called" << std::endl;
	if (this != &src)
		this->_ideas[100] = src._ideas[100]; //NOT SHURE
	return (*this);
}