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

std::string	Contact::getLastName() const
{
	return (this->_lastName);
}

void	Contact::setLastName(std::string const &lastName)
{
	this->_lastName = lastName;
}

std::string	Contact::getNickName() const
{
	return (this->_nickName);
}

void	Contact::setNickName(std::string const &nickName)
{
	this->_nickName = nickName;
}

std::string	Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

void	Contact::setPhoneNumber(std::string const &phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

std::string	Contact::getSecret() const
{
	return (this->_darkestSecret);
}

void	Contact::setSecret(std::string const &secret)
{
	this->_darkestSecret = secret;
}


