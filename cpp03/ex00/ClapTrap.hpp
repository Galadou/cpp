#ifndef CLAP_TRAP
# define CLAP_TRAP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(ClapTrap const &cpy);
		ClapTrap	&operator=(ClapTrap const &src);

		ClapTrap(std::string name);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		std::string		_name;
		int				_hit;
		int 			_energy;
		int				_attack_dmg;
};

#endif