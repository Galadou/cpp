#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "constructor called for " << this->_name << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "destructor called for " << this->_name << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

// Zombie* newZombie(std::string name)
// {
// 	return (new Zombie(name));
// }


