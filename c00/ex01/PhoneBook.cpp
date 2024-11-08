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

	std::cout << "Please enter first name : ";
	std::cin >> NewContact.firstName;
	std::cout << std::endl;
	
	std::cout << "Please enter last name : ";
	std::cin >> NewContact.lastName;
	std::cout << std::endl;

	std::cout << "Please enter nickname : ";
	std::cin >> NewContact.nickName;
	std::cout << std::endl;

	std::cout << "Please enter phone number : ";
	std::cin >> NewContact.phoneNumber;
	std::cout << std::endl;

	std::cout << "Please enter darkest secret : ";
	std::cin >> NewContact.darkestSecret;
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

void	print_contact(std::string str)
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

void	PhoneBook::searchContact(int nb)
{
	for (int i = 0; i < 8; i++)
	{
		//index
		std::cout << i << "         |";
		
		if (i < nb)
			print_contact(this->Repertory[i].firstName);
		else
			std::cout << "          |";

		if (i < nb)
			print_contact(this->Repertory[i].lastName);
		else
			std::cout << "          |";

		if (i < nb)
			print_contact(this->Repertory[i].nickName);
		else
			std::cout << "          |";
		std::cout << std::endl;
	}
}