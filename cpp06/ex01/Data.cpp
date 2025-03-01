#include "Data.hpp"

Data::Data() : _name("José") {}

Data::~Data() {}

Data::Data(Data const &src)
{
	*this = src;
}


Data& Data::operator=(Data const &src)
{
	(void)src;
	return (*this);
}

void	Data::setName(std::string newName)
{
	this->_name = newName;
}
std::string	Data::getName()
{
	return (this->_name);
}