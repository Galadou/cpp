#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main () // utiliser  setw function from: iomap
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
		std::cout << std::endl << "Please type your choice:\nADD\nSEARCH\nEXIT\nEnter here: ";
		while (choice != "ADD" && choice != "SEARCH" && choice != "EXIT")
		{
			std::getline(std::cin, choice); // gerer endofile std::cin.clear();
		}
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
		else if (choice == "EXIT") // std::cin.eof() == 1
		{
			std::cout << "Exit" << std::endl;
			break;
		}
		choice = "";
	}
	return(0);
}