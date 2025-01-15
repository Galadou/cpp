#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "Constructor of WrongCat called" << std::endl;
	return;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called." << std::endl << std::endl;
	return;
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << "Copy constructor of WrongCat called." << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	std::cout << "Copy assignment of WrongCat operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}