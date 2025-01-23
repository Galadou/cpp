#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Constructor of FragTrap called" << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack_dmg = 30;
	return;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap called." << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "Copy constructor of FragTrap called." << std::endl;
	*this = src;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Copy assignment operator of FragTrap called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_energy = src._energy;
		this->_hit = src._hit;
		this->_attack_dmg = src._attack_dmg;
	}
	return (*this);
}

FragTrap::FragTrap(std::string &name) : ClapTrap(name)
{
	std::cout << "Constructor initializing name of FragTrap called." << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack_dmg = 30;
	this->_name = name;
	return;
}

void	FragTrap::highFivesGuys(void)
{
	if (!this->_energy || this->_hit < 1)
	{
		std::cout << "\033[93mNo energy or life left\033[0m. \033[31m!\033[0m"<< std::endl;
		return;
	}
	std::cout << "FragTrap want to High Fives you !" << std::endl;
}