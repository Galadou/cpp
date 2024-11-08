#ifndef CONTACT
# define CONTACT

#include <iostream>

class	Contact {
	public :
		Contact(void);
		~Contact(void);

		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	private :
};

#endif