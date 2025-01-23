
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::string name = "Jules";
	ScavTrap robot(name);

	robot.attack("José");
	robot.takeDamage(2);
	robot.beRepaired(2);
	robot.takeDamage(50);
	robot.attack("José");
	robot.beRepaired(20);
	robot.guardGate();
	robot.takeDamage(100);
	robot.beRepaired(20);
}