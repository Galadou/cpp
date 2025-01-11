#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main ()
{
	PhoneBook	phoneBook;
	std::string	choice;
	int			i;
	bool		is_full;

	i = 0;
	is_full = false;
	while (std::cin.eof() == 0 && choice != "EXIT")
	{
		if (i == 8)
		{
			i = 0;
			is_full = true;
		}
		std::cout << std::endl << "Please type your choice:\nADD\nSEARCH\nEXIT\nEnter here: ";
		while (std::cin.eof() == 0 && choice != "ADD" && choice != "SEARCH" && choice != "EXIT")
		{
			std::getline(std::cin, choice);
		}
		if (std::cin.eof() == 1)
			return (1);
		if (choice == "ADD")
		{
			phoneBook.setRepertory(i);
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
		choice = "";
	}
	return(0);
}