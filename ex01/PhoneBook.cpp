#include "PhoneBook.hpp"
#include <iostream>

//constructeur
PhoneBook::PhoneBook(void)
{
	return;
}

//destructeur
PhoneBook::~PhoneBook(void)
{
	return;
}

Contact PhoneBook::addContact(void)
{
	Contact NewContact;

	std::cout << "Please enter first name: ";
	std::getline(std::cin, NewContact.firstName, '\n');
	//std::cout << std::endl;
	
	std::cout << "Please enter last name: ";
	std::getline(std::cin, NewContact.lastName, '\n');
	//std::cout << std::endl;

	std::cout << "Please enter nickname: ";
	std::getline(std::cin, NewContact.nickName, '\n'); //here 
	//std::cout << std::endl;

	std::cout << "Please enter phone number: ";
	std::getline(std::cin, NewContact.phoneNumber, '\n');
	//std::cout << std::endl;

	std::cout << "Please enter darkest secret: ";
	std::getline(std::cin, NewContact.darkestSecret, '\n');
	std::cout << "Thanks" << std::endl;

	return (NewContact);
}

// void	print_contact(std::string str)
// {
// 	for (int j = 0; j < 10; j++)
// 		{
// 			if (j < (int)str.size())
// 			{
// 				if (j > 9 && (int)str.size() > 10)
// 					std::cout << ".";
// 				else
// 					std::cout << str[j];
// 			}
// 			else
// 				std::cout << " ";
// 		}
// 		std::cout << "|";
// } // sur la gauche

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

void	PhoneBook::printListContact(int nb)
{
	for (int i = 0; i < 8; i++)
	{
		//index
		std::cout << i << "         |";
		
		if (i < nb)
			print_category(this->Repertory[i].firstName);
		else
			std::cout << "          |";

		if (i < nb)
			print_category(this->Repertory[i].lastName);
		else
			std::cout << "          |";

		if (i < nb)
			print_category(this->Repertory[i].nickName);
		else
			std::cout << "          |";
		std::cout << std::endl;
	}
}

void	PhoneBook::printThisContact(int id, std::string choice)
{
	std::cout << std::endl;
	std::cout << "Id choose:	| " << choice << std::endl;
	std::cout << "First name:	| " << this->Repertory[id].firstName << std::endl;
	std::cout << "Last name:	| " << this->Repertory[id].lastName << std::endl;
	std::cout << "Nickname:	| " << this->Repertory[id].nickName << std::endl;
	std::cout << "Phone number:	| " << this->Repertory[id].phoneNumber << std::endl;
	std::cout << "Darkest secret:	| " << this->Repertory[id].darkestSecret << std::endl;
}

void	PhoneBook::searchContact(int nb)
{
	std::string choice;
	int id;

	this->printListContact(nb);//on print

	std::cout << std::endl;
	std::cout << "Please enter an id: ";
	std::getline(std::cin, choice, '\n');
	if ((int)choice.size() != 1)
	{
		std::cout << "! Error: wrong input entered. !" << std::endl;
		return ;
	}
	id = choice[0] - 48;
	if (id < 0 || id > 7)
		std::cout << "! Error: wrong number entered. !" << std::endl;
	else
		this->printThisContact(id, choice);
}