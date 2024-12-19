#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(ScavTrap const &cpy);
		ScavTrap	&operator=(ScavTrap const &src);

		ScavTrap(std::string name);
		void	guardGate();
};

#endif