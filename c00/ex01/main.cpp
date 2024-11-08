#include "PhoneBook.hpp"
#include "contact.hpp"
#include <iostream>

int main ()
{
	PhoneBook	phoneBook;
	std::string	choice;
	int			i;
	bool		is_full;

	i = 0;
	is_full = false;
	while (choice != "EXIT")
	{
		if (i == 8)
		{
			i = 0;
			is_full = true;
		}
		std::cout << "Please type your choise:\nADD\nSEARCH\nEXIT\nEnter here: ";
		std::cin >> choice;
		std::cout << std::endl;

		if (choice == "ADD")
		{
			phoneBook.Repertory[i] = phoneBook.addContact();
			i++;
		}
		else if (choice == "SEARCH")
		{
			if (is_full)
				phoneBook.searchContact(8);
			else
				phoneBook.searchContact(i);
		}
		else if (choice == "EXIT")
		{
			std::cout << "Exit" << std::endl;
			break;
		}
	}
	return(0);
}