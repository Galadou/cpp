#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit(10), _energy(10), _attack_dmg(0)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_energy = src._energy;
		this->_hit = src._hit;
		this->_attack_dmg = src._attack_dmg;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string &name) : _hit(10), _energy(10), _attack_dmg(0)
{
	std::cout << std::endl << "Constructor initializing name called." << std::endl;
	this->_name = name;
	return;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_energy || this->_hit < 1)
	{
		std::cout << "\033[93mNo energy or life left\033[0m. \033[31m! Attack on " << target;
		std::cout << " failed !\033[0m." << std::endl;
		return;
	}
	this->_energy--;
	std::cout << "\033[36mClapTrap\033[0m " << this->_name << " \033[35mattacks " << target;
	std::cout << ", causing " << this->_attack_dmg << " damage points!\033[0m";
	std::cout << std::endl;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit -= amount;
	std::cout << "\033[36mClapTrap\033[0m " << this->_name << " \033[31mhas been hit";
	std::cout << ", losing " << amount << " damage points!\033[0m";
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy || this->_hit < 1)
	{
		std::cout << "\033[93mNo energy or life left\033[0m. \033[31m! Repair failed !\033[0m" << std::endl;
		return;
	}
	std::cout << "\033[36mClapTrap\033[0m " << this->_name << " \033[32mhas repaired himself";
	std::cout << ", and recovered " << amount << " points of life!\033[0m";
	std::cout << std::endl;
	this->_energy--;
	this->_hit += amount;
}