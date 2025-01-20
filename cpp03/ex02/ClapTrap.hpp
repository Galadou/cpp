#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		virtual ~ClapTrap();
		ClapTrap(ClapTrap const &cpy);
		ClapTrap	&operator=(ClapTrap const &src);

		ClapTrap(std::string &name);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
	protected:
		std::string		_name;
		int				_hit;
		int 			_energy;
		int				_attack_dmg;
};

#endif