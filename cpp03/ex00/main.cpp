
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap robot;

	robot.attack("José");
	robot.takeDamage(2);
	robot.beRepaired(2);
	robot.takeDamage(10);
	robot.attack("José");
}