#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(FragTrap const &cpy);
		FragTrap	&operator=(FragTrap const &src);

		FragTrap(std::string &name);
		void	highFivesGuys(void);
};

#endif