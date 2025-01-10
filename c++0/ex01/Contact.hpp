#ifndef CONTACT
# define CONTACT

# include <iostream>

# define PRINT std::cout <<
# define END << std::endl;

class	Contact {

	public:
		Contact(void);
		~Contact(void);

		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

		std::string	getFirstName() const;
		void	setFirstName(std::string const &firstName);

		private:
			std::string	_firstName;
};

#endif