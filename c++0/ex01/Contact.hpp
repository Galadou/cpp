#ifndef CONTACT
# define CONTACT

# include <iostream>

class	Contact {

	public:
		Contact(void);
		~Contact(void);


		std::string	getFirstName() const;
		void	setFirstName(std::string const &firstName);

		std::string	getLastName() const;
		void	setLastName(std::string const &lastName);

		std::string	getNickName() const;
		void	setNickName(std::string const &nickName);

		std::string	getPhoneNumber() const;
		void	setPhoneNumber(std::string const &phoneNumber);

		std::string	getSecret() const;
		void	setSecret(std::string const &Secret);

		private:
			std::string	_firstName;
			std::string	_lastName;
			std::string	_nickName;
			std::string	_phoneNumber;
			std::string	_darkestSecret;
};

#endif