#ifndef PHONEBOOK
# define PHONEBOOK

#include <iostream>
#include "Contact.hpp"

class	PhoneBook {

	private :
		Contact	_repertory[8];
		Contact _addContact(void);
		void	_printThisContact(int id, std::string choice) const;
		void	_printListContact(int nb) const;

	public :
		PhoneBook(void);
		~PhoneBook();

		void	setRepertory(int i);
		void	searchContact(int nb) const;
};

#endif