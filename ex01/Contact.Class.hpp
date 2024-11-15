#ifndef CONTACT
# define CONTACT

#include <iostream>

struct	Contact {

	Contact(void);
	~Contact(void);

	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

#endif