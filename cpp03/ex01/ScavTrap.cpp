#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Constructor of ScavTrap called" << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack_dmg = 20;
	return;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap called." << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "Copy constructor of ScavTrap called." << std::endl;
	*this = src;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "Copy assignment operator of ScavTrap called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_energy = src._energy;
		this->_hit = src._hit;
		this->_attack_dmg = src._attack_dmg;
	}
	return (*this);
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
	std::cout << "Constructor initializing name of ScavTrap called." << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack_dmg = 20;
	this->_name = name;
	return;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_energy || this->_hit < 1)
	{
		std::cout << "\033[93mScavTrap: No energy or life left\033[0m. \033[31m! Attack on " << target;
		std::cout << " failed !\033[0m." << std::endl;
		return;
	}
	this->_energy--;
	std::cout << "\033[36mScavTrap\033[0m " << this->_name << " \033[35mattacks " << target;
	std::cout << ", causing " << this->_attack_dmg << " damage points!\033[0m";
	std::cout << std::endl;
	return;
}

void	ScavTrap::guardGate()
{
	if (!this->_energy || this->_hit < 1)
	{
		std::cout << "\033[93mNo energy or life left\033[0m. \033[31m!\033[0m"<< std::endl;
		return;
	}
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
