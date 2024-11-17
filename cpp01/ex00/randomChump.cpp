#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name)
{
	Zombie *newZ;
	newZ = newZombie(name);
	newZ->announce();
	delete newZ;
}