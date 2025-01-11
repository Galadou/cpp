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
	std::string str;

	std::cout << "Please enter first name: ";
	while (std::cin.eof() == 0 && str.empty())
		std::getline(std::cin, str);
	if (std::cin.eof() == 1)
		return newContact;
	newContact.setFirstName(str);

	std::cout << "Please enter last name: ";
	str = "";
	while (std::cin.eof() == 0 && str.empty())
		std::getline(std::cin, str);
	if (std::cin.eof() == 1)
		return newContact;
	newContact.setLastName(str);

	std::cout << "Please enter nickname: ";
	str = "";
	while (std::cin.eof() == 0 && str.empty())
		std::getline(std::cin, str);
	if (std::cin.eof() == 1)
		return newContact;
	newContact.setNickName(str);

	std::cout << "Please enter phone number: ";
	str = "";
	while (std::cin.eof() == 0 && str.empty())
		std::getline(std::cin, str);
	if (std::cin.eof() == 1)
		return newContact;
	newContact.setPhoneNumber(str);

	std::cout << "Please enter darkest secret: ";
	str = "";
	while (std::cin.eof() == 0 && str.empty())
		std::getline(std::cin, str);
	if (std::cin.eof() == 1)
		return newContact;
	newContact.setSecret(str);

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
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::setw(10) << "id" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "         " << i << "|";
		if (i < nb)
			print_category(this->_repertory[i].getFirstName());
		else
			std::cout << "          |";
		if (i < nb)
			print_category(this->_repertory[i].getLastName());
		else
			std::cout << "          |";
		if (i < nb)
			print_category(this->_repertory[i].getNickName());
		else
			std::cout << "          |";
		std::cout << std::endl;
	}
}

void	PhoneBook::_printThisContact(int id, std::string choice) const
{
	std::cout << std::endl;
	std::cout << "Id choose:	| " << choice << std::endl;
	std::cout << "First name:	| " << this->_repertory[id].getFirstName() << std::endl;
	std::cout << "Last name:	| " << this->_repertory[id].getLastName() << std::endl;
	std::cout << "Nickname:	| " << this->_repertory[id].getNickName() << std::endl;
	std::cout << "Phone number:	| " << this->_repertory[id].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret:	| " << this->_repertory[id].getSecret() << std::endl;
}

void	PhoneBook::searchContact(int nb) const
{
	std::string choice;
	int id;

	this->_printListContact(nb);
	std::cout << std::endl;
	std::cout << "Please enter an id: ";
	std::getline(std::cin, choice);
	if (std::cin.eof() == 1)
		return ;
	if ((int)choice.size() != 1)
	{
		std::cout << "! Error: wrong input entered. !" << std::endl;
		return ;
	}
	id = choice[0] - 48;
	if (id < 0 || id > 7 || this->_repertory[id].getFirstName().empty())
		std::cout << "! Error: wrong number entered. !" << std::endl;
	else
		this->_printThisContact(id, choice);
}