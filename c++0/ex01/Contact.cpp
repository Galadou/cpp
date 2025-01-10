#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string	Contact::getFirstName() const
{
	return (this->_firstName);
}

void	Contact::setFirstName(std::string const &firstName)
{
	this->_firstName = firstName;
}