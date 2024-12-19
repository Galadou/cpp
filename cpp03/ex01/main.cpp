
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap robot("Bla");

	robot.attack("José");
	robot.takeDamage(2);
	robot.beRepaired(2);
	robot.takeDamage(10);
	robot.attack("José");
}