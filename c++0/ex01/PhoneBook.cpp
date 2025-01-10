#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::setRepertory(int i)
{
	this->_repertory[i] = this->_addContact();
}

Contact PhoneBook::_addContact(void)
{
	Contact newContact;

	std::cout << "Please enter first name: ";
	while (newContact.firstName.empty())
		std::getline(std::cin, newContact.firstName, '\n');
	std::cout << "Please enter last name: ";
	while (newContact.lastName.empty())
		std::getline(std::cin, newContact.lastName, '\n');
	std::cout << "Please enter nickname: ";
	while (newContact.nickName.empty())
		std::getline(std::cin, newContact.nickName, '\n');
	std::cout << "Please enter phone number: ";
	while (newContact.phoneNumber.empty())
		std::getline(std::cin, newContact.phoneNumber, '\n');
	std::cout << "Please enter darkest secret: ";
	while (newContact.darkestSecret.empty())
		std::getline(std::cin, newContact.darkestSecret, '\n');
	std::cout << "Thanks" << std::endl;
	return (newContact);
}

void	print_category(std::string str)
{
	int i = 10;

	while (i > (int)str.size())
	{
		std::cout << " ";
		i--;
	}
	for (int j = 0; j < i; j++)
	{
		if (j == 9 && (int)str.size() > 10)
			std::cout << ".";
		else
			std::cout << str[j];
	}
	std::cout << "|";
}

void	PhoneBook::_printListContact(int nb) const
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << "         " << i << "|";
		if (i < nb)
			print_category(this->_repertory[i].firstName);
		else
			std::cout << "          |";
		if (i < nb)
			print_category(this->_repertory[i].lastName);
		else
			std::cout << "          |";
		if (i < nb)
			print_category(this->_repertory[i].nickName);
		else
			std::cout << "          |";
		std::cout << std::endl;
	}
}

void	PhoneBook::_printThisContact(int id, std::string choice) const
{
	std::cout << std::endl;
	std::cout << "Id choose:	| " << choice << std::endl;
	std::cout << "First name:	| " << this->_repertory[id].firstName << std::endl;
	std::cout << "Last name:	| " << this->_repertory[id].lastName << std::endl;
	std::cout << "Nickname:	| " << this->_repertory[id].nickName << std::endl;
	std::cout << "Phone number:	| " << this->_repertory[id].phoneNumber << std::endl;
	std::cout << "Darkest secret:	| " << this->_repertory[id].darkestSecret << std::endl;
}

void	PhoneBook::searchContact(int nb) const
{
	std::string choice;
	int id;

	this->_printListContact(nb);
	std::cout << std::endl;
	std::cout << "Please enter an id: ";
	std::getline(std::cin, choice, '\n');
	if ((int)choice.size() != 1)
	{
		std::cout << "! Error: wrong input entered. !" << std::endl;
		return ;
	}
	id = choice[0] - 48;
	if (id < 0 || id > 7 || this->_repertory[id].firstName.empty())
		std::cout << "! Error: wrong number entered. !" << std::endl;
	else
		this->_printThisContact(id, choice);
}