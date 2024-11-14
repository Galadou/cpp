#ifndef PHONEBOOK
# define PHONEBOOK

#include "contact.hpp"

class	PhoneBook {
	public :
		PhoneBook(void);
		~PhoneBook(void);

		Contact	Repertory[8];
		Contact addContact(void);
		void	searchContact(int nb);
		void	printListContact(int nb);
		void	printThisContact(int id, std::string choice);

	private :

};

#endif