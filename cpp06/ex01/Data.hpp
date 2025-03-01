#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	public:
		Data();
		~Data();
		Data(Data const &src);
		Data& operator=(Data const &src);

		void		setName(std::string newName);
		std::string	getName();

	private:
		std::string _name;
};

#endif