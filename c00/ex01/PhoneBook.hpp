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

	private :

};

#endif